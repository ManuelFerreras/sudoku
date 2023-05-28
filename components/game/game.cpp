#include "game.h"
#include "ui_game.h"
#include "../start/start.h"

#include <QGridLayout>
#include <QLineEdit>
#include <QRegularExpressionValidator>
#include <QRegularExpression>

game::game(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::game)
{
    ui->setupUi(this);

    // Create the validator with a regex that matches numbers 1-9
    QValidator* validator = new QRegularExpressionValidator(QRegularExpression("[1-9]"), this);

    // Initialize the timer and elapsedTime objects
    timer = new QTimer(this);
    elapsedTime = new QElapsedTimer();

    // Start the timer to trigger every second
    timer->start(1000);

    // Connect the timer's timeout() signal to the updateTime() slot
    connect(timer, SIGNAL(timeout()), this, SLOT(updateTime()));
    elapsedTime->start();

    gameBoard.resize(9);
    for(int i = 0; i < 9; i++)
    {
        gameBoard[i].resize(9, {0, true});

        // Create each row
        for(int j = 0; j < 9; j++)
        {
            QLineEdit* grid = new QLineEdit(this);
            grid->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
            grid->setAlignment(Qt::AlignHCenter);

            if(!gameBoard[i][j].canModify)
            {
                // Set it to read-only
                grid->setReadOnly(true);
            }

            // Set validator and connect slot to textChanged signal
            grid->setValidator(validator);
            connect(grid, &QLineEdit::textChanged, this, &game::validateAndUpdate);

            // Store a pointer to the QLineEdit in the game state
            gameBoard[i][j].grid = grid;

            QString styleString = "QLineEdit { border: 1px solid rgba(255, 255, 255, 0.2); border-radius: 0; ";

            if ((i+1) % 3 == 0) {
                styleString += "border-bottom: 1px solid rgb(248, 211, 197);";
            }
            if ((j+1) % 3 == 0) {
                styleString += "border-right: 1px solid rgb(248, 211, 197);";
            }

            if (i == 0 && j == 0) {
                styleString += "border-top-left-radius: 16px;";
            }
            else if (i == 0 && j == 8) {
                styleString += "border-top-right-radius: 16px;";
            }
            else if (i == 8 && j == 0) {
                styleString += "border-bottom-left-radius: 16px;";
            }
            else if (i == 8 && j == 8) {
                styleString += "border-bottom-right-radius: 16px;";
            }

            // Close the QLineEdit style block
            styleString += "} ";

            // Add style for when the widget is in focus (being edited)
            styleString += "QLineEdit:focus { background-color: rgb(248, 211, 197); color: #252525; }";
            grid->setStyleSheet(styleString);

            ui->boardTiles->addWidget(grid, i, j);
        }
    }

    ui->boardTiles->setVerticalSpacing(0);
}

game::~game()
{
    delete ui;
    delete timer;
    delete elapsedTime;
}

void game::validateAndUpdate()
{
    QLineEdit* senderGrid = qobject_cast<QLineEdit*>(sender());

    // Find the cell in gameBoard that corresponds to the sender QLineEdit
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            if(gameBoard[i][j].grid == senderGrid)
            {
                bool ok;
                int newValue = senderGrid->text().toInt(&ok);

                if(ok && isValid(i, j, newValue))
                {
                    // Update the value in the game state
                    gameBoard[i][j].value = newValue;

                    // Set the cell to read-only
                    gameBoard[i][j].grid->setReadOnly(true);
                }
                else
                {
                    // Clear the cell
                    gameBoard[i][j].grid->clear();
                }

                return;
            }
        }
    }
}

bool game::isValid(int row, int column, int value)
{
    // Check row and column
    for(int i = 0; i < 9; i++)
    {
        if((i != column && gameBoard[row][i].value == value) || (i != row && gameBoard[i][column].value == value))
            return false;
    }

    // Check 3x3 box
    int startRow = row - row % 3;
    int startCol = column - column % 3;
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if((startRow + i != row || startCol + j != column) && gameBoard[startRow + i][startCol + j].value == value)
                return false;
        }
    }

    return true;
}

// Slot to update the timeLabel every second
void game::updateTime()
{
    int elapsedSeconds = elapsedTime->elapsed() / 1000;
    QString timeText = QString("%1:%2").arg(elapsedSeconds / 60, 2, 10, QLatin1Char('0'))
                           .arg(elapsedSeconds % 60, 2, 10, QLatin1Char('0'));
    ui->timeLabel->setText(timeText);
}

void game::on_closeButton_clicked()
{
    Start *w = new Start();
    w->show();

    this->close();
}

