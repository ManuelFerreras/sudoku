#include "gamesetup.h"
#include "ui_gamesetup.h"
#include "../start/start.h"
#include "../game/game.h"

gameSetup::gameSetup(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::gameSetup)
{
    ui->setupUi(this);
}

gameSetup::~gameSetup()
{
    delete ui;
}

void gameSetup::on_backButton_clicked()
{
    Start *w = new Start();
    w->show();

    this->close();
}


void gameSetup::on_continueButton_clicked()
{
    QString playerOneName = ui->playerOneLineEdit->text();
    QString playerTwoName = ui->playerTwoLineEdit->text();

    if(playerOneName.isEmpty() || playerTwoName.isEmpty())
        return;

    bool isEmptyBoard = ui->emptyRB->isChecked();

    game *c = new game(playerOneName, playerTwoName, isEmptyBoard);
    c->updateNames(playerOneName, playerTwoName);
    c->setEmptyBoard(isEmptyBoard);
    c->show();

    this->setVisible(false);
}

