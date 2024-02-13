//
// Created by huuti on 003, 03/02/2024.
//
#include "include/mapping.h"


void startMap(drawData drdata, posData &podata) {
    podata.tableHor[0] = 40 - (drdata.width * 4 / 2) + 2;
    podata.tableVer[0] = drdata.y + 3;
    for (int i = 1; i <= drdata.width; i++) {
        podata.tableHor[i] = podata.tableHor[i - 1] + 4;
    }
    for (int i = 1; i <= drdata.height; i++) {
        podata.tableVer[i] = podata.tableVer[i - 1] + 2;
    }
}

