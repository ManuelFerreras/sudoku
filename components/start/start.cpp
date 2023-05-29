#include "start.h"
#include "./ui_start.h"
#include "../gameSetup/gameSetup.h"
#include "../records/records.h"
#include "../../lib/txtActions.h"

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
    resetScores("../../../../data/scores.txt");
}


void Start::on_newGameButton_clicked()
{
    gameSetup *c = new gameSetup();
    c->show();

    this->setVisible(false);
}


void Start::on_gamesRecordButton_clicked()
{
    records *c = new records();
    c->show();

    this->setVisible(false);
}

