//
// Created by huuti on 002, 02/02/2024.
//

#include "include/winLogic.h"
#include "include/drawScreen.h"
#include <iostream>

bool crossCheck(int intWin, char table[9][9], drawData drawData, char Player) {
    int RcrossCount = 0, LcrossCount = 0;
    int n = std::max(drawData.width, drawData.height);
    for (int i = -n; i <= n; i++) {
        for (int j = 0; j < n; j++) {
            if (table[j][n - j + i] == Player) RcrossCount++; else RcrossCount = 0;
            if (table[j][i + j] == Player) LcrossCount++; else LcrossCount = 0;
            if (LcrossCount >= intWin || RcrossCount >= intWin) return true;
        }
    }
    return false;
}

bool HorVerCheck(int intWin, char table[9][9], drawData drawData, char Player) {
    int HorCount = 0;
    int VerCount = 0;
    for (int i = 0; i < drawData.height; i++) {
        for (int j = 0; j < drawData.width; j++) {
            if (table[i][j] == Player) HorCount++; else HorCount = 0;
            if (table[j][i] == Player) VerCount++; else VerCount = 0;
            if (HorCount >= intWin || VerCount >= intWin) {
                return true;
            }
        }

    }
    return false;
}