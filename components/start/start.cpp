#include "start.h"
#include "./ui_start.h"
#include "../game/game.h"

Start::Start(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Start)
{
    ui->setupUi(this);

    ui->exitButton->setCursor(Qt::PointingHandCursor);
    ui->resetButton->setCursor(Qt::PointingHandCursor);
    ui->newGameButton->setCursor(Qt::PointingHandCursor);
    ui->gamesRecordButton->setCursor(Qt::PointingHandCursor);
}

Start::~Start()
{
    delete ui;
}


void Start::on_exitButton_clicked()
{
    exit(1);
}


void Start::on_resetButton_clicked()
{

}


void Start::on_newGameButton_clicked()
{
    game *c = new game();
    c->show();

    this->setVisible(false);
}


void Start::on_gamesRecordButton_clicked()
{

}

