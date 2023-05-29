#ifndef GAMERESULT_H
#define GAMERESULT_H

#include <QWidget>

namespace Ui {
class gameResult;
}

class gameResult : public QWidget
{
    Q_OBJECT

public:
    explicit gameResult(QWidget *parent = nullptr);
    ~gameResult();

    int getTotalScore() { return this->totalScore; }
    void setTotalScore(int totalScore) { this->totalScore = totalScore; }

    QString getWinnerName() { return this->winnerName; }
    void setWinnerName(QString winnerName) { this->winnerName = winnerName; }

public slots:
    void showMessage();

private slots:
    void on_homeButton_clicked();

    void on_exitButton_clicked();

private:
    Ui::gameResult *ui;
    QString winnerName;
    int totalScore;
};

#endif // GAMERESULT_H
