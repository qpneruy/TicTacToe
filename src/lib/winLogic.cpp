//
// Created by huuti on 002, 02/02/2024.
//

#include "include/winLogic.h"
#include "include/drawScreen.h"
#include <iostream>
TableData tableDaTa;
char crossCheck(char intWin, char table[9][9], drawData drawData, char Player) {
    int RcrossCount = 0, LcrossCount = 0;
    int n = std::max(static_cast<int>(drawData.width), static_cast<int>(drawData.height));
    for (int i = -n; i <= n; i++) {
        for (int j = 0; j < n; j++) {
            if (table[j][n - j + i] == Player) RcrossCount++; else RcrossCount = 0;
            if (table[j][i + j] == Player) LcrossCount++; else LcrossCount = 0;
            if (LcrossCount >= intWin ) {
                return 1;
            } else if (RcrossCount >= intWin) {
                return 2;
            }
        }
    }
    return -1;
}

char HorVerCheck(char intWin, char table[9][9], drawData drawData, char Player) {
    int HorCount = 0;
    int VerCount = 0;
    for (int i = 0; i < drawData.height; i++) {
        for (int j = 0; j < drawData.width; j++) {
            if (table[i][j] == Player) HorCount++; else HorCount = 0;
            if (table[j][i] == Player) VerCount++; else VerCount = 0;
            if (HorCount >= intWin ) {
                return 1;
            } else if (VerCount >= intWin) {
                return 2;
            }
        }
    }
    return -1;
}

bool isWin(char table[9][9], drawData drData, char Player) {
    char OresHV = HorVerCheck(drData.intWin, table, drData, Player);
    char OresRL = crossCheck(drData.intWin, table, drData, Player);
    (OresHV == 1) ? tableDaTa.hr = true : tableDaTa.vr = true;
    (OresRL == 1) ? tableDaTa.cR = true : tableDaTa.cL = true;
    if (OresHV != -1 || OresRL != -1) {
        return true;
    } else return false;

}
