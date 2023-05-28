#include "gamesetup.h"
#include "ui_gamesetup.h"

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
