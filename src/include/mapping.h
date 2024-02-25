//
// Created by huuti on 003, 03/02/2024.
//

#ifndef TICTACTOEV2_MAPPING_H
#define TICTACTOEV2_MAPPING_H

#include "include/drawScreen.h"

struct posData {
    int tableHor[10] = {};
    int tableVer[10] = {};
    char playerPosX = 0;
    char playerPosY = 0;
};

void startMap(drawData data, posData &pdata);

#endif //TICTACTOEV2_MAPPING_H
