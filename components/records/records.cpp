#include "records.h"
#include "ui_records.h"
#include "../start/start.h"
#include "../../classes/Score/score.h"
#include "../../lib/txtActions.h"

records::records(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::records)
{
    ui->setupUi(this);

    std::vector<Score> scores = getScoresFromFile("../../../../data/scores.txt");

    ui->recordsTable->setRowCount(scores.size() + 1);

    QString winnerHeader = "Winner Name";
    QString completedCellsHeader = "Total Score";
    QTableWidgetItem *winnerItemHeader = new QTableWidgetItem(winnerHeader);
    QTableWidgetItem *cellsItemHeader = new QTableWidgetItem(completedCellsHeader);
    winnerItemHeader->setTextAlignment(Qt::AlignCenter);
    cellsItemHeader->setTextAlignment(Qt::AlignCenter);

    // Add the items to the QTableWidget
    ui->recordsTable->setItem(0, 0, winnerItemHeader);
    ui->recordsTable->setItem(0, 1, cellsItemHeader);

    int row = 1;
    for (const auto& score : scores) {
        // Convert data to QString
        QString winnerName = QString::fromStdString(score.getWinnerName());
        QString completedCells = QString::number(score.getCompletedCells());

        // Create new QTableWidgetItem instances
        QTableWidgetItem *winnerItem = new QTableWidgetItem(winnerName);
        QTableWidgetItem *cellsItem = new QTableWidgetItem(completedCells);

        // Add the items to the QTableWidget
        ui->recordsTable->setItem(row, 0, winnerItem);
        ui->recordsTable->setItem(row, 1, cellsItem);

        winnerItem->setTextAlignment(Qt::AlignCenter);
        cellsItem->setTextAlignment(Qt::AlignCenter);

        row++;
    }

    // Set columns to take up equal width
    ui->recordsTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

records::~records()
{
    delete ui;
}

void records::on_homeButton_clicked()
{
    Start *w = new Start();
    w->show();

    this->close();
}


void records::on_exitButton_clicked()
{
    exit(1);
}


