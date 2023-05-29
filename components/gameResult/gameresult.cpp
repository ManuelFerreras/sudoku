#include "gameresult.h"
#include "ui_gameresult.h"
#include "../start/start.h"

gameResult::gameResult(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::gameResult)
{
    ui->setupUi(this);
}

gameResult::~gameResult()
{
    delete ui;
}


void gameResult::showMessage()
{
    ui->winnerLabel->setText(this->getWinnerName());
    ui->winnerScore->setText(QString::number(this->getTotalScore()));
}

void gameResult::on_homeButton_clicked()
{
    Start *w = new Start();
    w->show();

    this->close();
}


void gameResult::on_exitButton_clicked()
{
    exit(1);
}

