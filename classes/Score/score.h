#ifndef SCORE_H
#define SCORE_H

#include <string>

class Score
{
public:
    Score(const std::string& name, int cells) : winnerName(name), completedCells(cells) {}

    // getter and setter for winnerName
    const std::string& getWinnerName() const { return winnerName; }
    void setWinnerName(const std::string& name) { winnerName = name; }

    // getter and setter for completedCells
    int getCompletedCells() const { return completedCells; }
    void setCompletedCells(int cells) { completedCells = cells; }

private:
    std::string winnerName;
    int completedCells;
};

#endif // SCORE_H
