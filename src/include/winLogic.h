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
    std::pair<int, int> tablePath_R[10] = {};
    std::pair<int, int> tablePath_L[10] = {}; // ??????
};
bool isWin(std::string table[100][100], drawData drData, const std::string& Player);
bool drawC(std::string table[100][100], drawData drData);
#endif //TICTACTOEV2_WINLOGIC_H
