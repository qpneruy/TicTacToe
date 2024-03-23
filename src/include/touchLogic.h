//
// Created by huuti on 003, 03/02/2024.
//

#ifndef TICTACTOEV2_TOUCHLOGIC_H
#define TICTACTOEV2_TOUCHLOGIC_H

#include "include/mapping.h"
#include "archive.h"

void getEvent(posData &data);

void dacPos(const gameData& gData, int &o_x, int &o_y);

bool SyntaxCheck(std::string table[100][100], int y, int x);

#endif //TICTACTOEV2_TOUCHLOGIC_H
