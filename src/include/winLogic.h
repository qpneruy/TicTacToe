//
// Created by huuti on 002, 02/02/2024.
//

#ifndef TICTACTOEV2_WINLOGIC_H
#define TICTACTOEV2_WINLOGIC_H

#include "drawScreen.h"

struct Player {
    int score;
    int time;
};
bool crossCheck(int intWin, char table[9][9], drawData drawData, char Player);
bool HorVerCheck(int intWin, char table[9][9], drawData drawData, char Player);
#endif //TICTACTOEV2_WINLOGIC_H
