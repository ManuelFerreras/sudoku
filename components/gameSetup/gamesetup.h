#ifndef GAMESETUP_H
#define GAMESETUP_H

#include <QWidget>

namespace Ui {
class gameSetup;
}

class gameSetup : public QWidget
{
    Q_OBJECT

public:
    explicit gameSetup(QWidget *parent = nullptr);
    ~gameSetup();

private slots:
    void on_backButton_clicked();

    void on_continueButton_clicked();

private:
    Ui::gameSetup *ui;
};

#endif // GAMESETUP_H
