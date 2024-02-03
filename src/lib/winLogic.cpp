//
// Created by huuti on 002, 02/02/2024.
//

#include "include/winLogic.h"
#include <iostream>

bool HorVerCheck(Player Data, char table[9][9], int width, int height, char Player) {
    int HorCount = 0, ZHorCount = 0;
    int VerCount = 0, ZVerCount = 0;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (table[i][j] == Player) HorCount++; else HorCount = 0;
            if (table[j][i] == Player) ZHorCount++; else ZHorCount = 0;
        }
        if (HorCount == Data.intWin || VerCount == Data.intWin) return true;
    }
    return false;
}