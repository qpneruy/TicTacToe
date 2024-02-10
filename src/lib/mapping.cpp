//
// Created by huuti on 003, 03/02/2024.
//
#include "include/mapping.h"


void startMap(drawData drdata, posData &pdata) {
    pdata.tableHor[0] = 40 - (drdata.width * 4 / 2) + 1;
    pdata.tableVer[0] = drdata.y + 3;
    for (int i = 1; i <= drdata.width; i++) {
        pdata.tableHor[i] = pdata.tableHor[i - 1] + 4;
    }
    for (int i = 1; i <= drdata.height; i++) {
        pdata.tableVer[i] = pdata.tableVer[i - 1] + 2;
    }
}

