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
struct TableData {
    std::pair<short, short> tablePath[9] = {};
    bool hr = false,
         vr = false,
         cL = false,
         cR = false;
};
bool isWin(char table[9][9], drawData drData, char Player);

#endif //TICTACTOEV2_WINLOGIC_H
