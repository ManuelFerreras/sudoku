#ifndef TXTACTIONS_H
#define TXTACTIONS_H

#include <QString>
#include <vector>
#include "../classes/Score/score.h"

std::vector<Score> getScoresFromFile(QString path);
void writeScoresToFile(const QString& path, const std::vector<Score>& scores);
void resetScores(const QString& path);

#endif // TXTACTIONS_H
