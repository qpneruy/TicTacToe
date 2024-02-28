//
// Created by huuti on 003, 03/02/2024.
//
#include "include/mapping.h"


void startMap(drawData drData, posData &poData) {
    poData.tableHor[0] = 40 - (drData.width * 4 / 2) + 2;
    poData.tableVer[0] = drData.y + 3;
    for (int i = 1; i <= drData.width; i++) {
        poData.tableHor[i] = poData.tableHor[i - 1] + 4;
    }
    for (int i = 1; i <= drData.height; i++) {
        poData.tableVer[i] = poData.tableVer[i - 1] + 2;
    }
}

