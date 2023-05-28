#ifndef START_H
#define START_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Start; }
QT_END_NAMESPACE

class Start : public QMainWindow
{
    Q_OBJECT

public:
    Start(QWidget *parent = nullptr);
    ~Start();

private slots:
    void on_exitButton_clicked();

    void on_resetButton_clicked();

    void on_newGameButton_clicked();

    void on_gamesRecordButton_clicked();

private:
    Ui::Start *ui;
};
#endif // START_H
