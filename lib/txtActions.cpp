#include "txtActions.h"
#include "../classes/Score/score.h"

#include <QFile>
#include <QTextStream>
#include <QDebug>

std::vector<Score> getScoresFromFile(QString path)
{
    QFile file(path);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Unable to open file for reading: " << path;
        exit(1);
    }

    QTextStream in(&file);
    std::vector<Score> scores;

    while (!in.atEnd()) {
        QString read_text = in.readLine();
        if (read_text.startsWith("winner_name")) {
            continue;
        }

        QStringList fields = read_text.split(',');

        std::string winnerName = fields[0].trimmed().toStdString();
        int completedCells = fields[1].trimmed().toInt();

        scores.push_back(Score(winnerName, completedCells));
    }

    return scores;
}

void writeScoresToFile(const QString& path, const std::vector<Score>& scores)
{
    QFile file(path);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "Unable to open file for writing: " << path;
        exit(1);
    }

    QTextStream out(&file);

    // Write the headers.
    out << "winner_name,completed_cells\n";

    for(const auto& score : scores){
        out << QString::fromStdString(score.getWinnerName()) << ','
            << score.getCompletedCells()
            << '\n';
    }

    file.close();
}

void resetScores(const QString& path)
{
    QFile file(path);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "Unable to open file for writing: " << path;
        exit(1);
    }

    QTextStream out(&file);

    // Write the headers.
    out << "winner_name,completed_cells\n";

    file.close();
}
