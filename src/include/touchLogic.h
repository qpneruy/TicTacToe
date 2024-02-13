//
// Created by huuti on 003, 03/02/2024.
//

#ifndef TICTACTOEV2_TOUCHLOGIC_H
#define TICTACTOEV2_TOUCHLOGIC_H

#include "include/mapping.h"

void getPosMouse(posData &data);

void dacPos(drawData drData, posData poData, posData locationData, int &o_x, int &o_y);

bool SyntaxCheck(char table[9][9], int y, int x);

#endif //TICTACTOEV2_TOUCHLOGIC_H
