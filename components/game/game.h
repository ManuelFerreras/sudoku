#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include <QLineEdit>
#include <QElapsedTimer>
#include <QTimer>

namespace Ui {
class game;
}

class game : public QWidget
{
    Q_OBJECT

public:
    explicit game(QWidget *parent = nullptr);
    ~game();

public slots:
    void validateAndUpdate();
    void updateTime();

private slots:
    void on_closeButton_clicked();

private:
    struct Cell
    {
        int value;
        bool canModify;
        QLineEdit* grid;
    };

    bool isValid(int row, int column, int value);

    Ui::game *ui;

    QVector<QVector<Cell>> gameBoard;

    QTimer *timer;
    QElapsedTimer *elapsedTime;
};

#endif // GAME_H
