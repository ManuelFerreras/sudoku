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
    explicit game(const QString& playerOneName = QString(), const QString& playerTwoName = QString(), bool empty = false, QWidget *parent = nullptr);
    ~game();

    bool updateScore;
    bool error;

    void updateNames(QString playerOneName, QString playerTwoName) { this->playerOneName = playerOneName; this->playerTwoName = playerTwoName; }
    QString getPlayerOneName() { return this->playerOneName; }
    QString getPlayerTwoName() { return this->playerTwoName; }

    void setEmptyBoard(bool empty) { this->emptyBoard = empty; }
    bool getEmptyBoard() { return this->emptyBoard; }

    void setPlayerOneTurn(bool playerOneTurn) { this->playerOneTurn = playerOneTurn; }
    bool getPlayerOneTurn() { return this->playerOneTurn; }

public slots:
    void validateAndUpdate();
    void updateTime();
    void renderBoard(bool emptyBoard);
    bool generateBoard(int index);

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

    QString playerOneName;
    QString playerTwoName;

    bool emptyBoard;
    bool playerOneTurn;

    int playerOneScore = 0;
    int playerTwoScore = 0;
};

#endif // GAME_H
