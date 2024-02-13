//
// Created by huuti on 002, 02/02/2024.
//

#include "include/winLogic.h"
#include "include/drawScreen.h"
#include <iostream>
#include <synchapi.h>

TableData tableData;
char crossCheck(char intWin, char table[9][9], drawData drawData, char Player) {
    int RcrossCount = 0, LcrossCount = 0;
    int n = std::max(static_cast<int>(drawData.width), static_cast<int>(drawData.height));
    for (int i = -n; i <= n; i++) {
        for (int j = 0; j < n; j++) {
            if (table[j][n - j + i] == Player) {
                RcrossCount++;
                tableData.tablePath_R[RcrossCount].first = i;
                tableData.tablePath_R[RcrossCount].second = j;
            } else RcrossCount = 0;
            if (table[j][i + j] == Player) {
                LcrossCount++;
                tableData.tablePath_L[LcrossCount].first = i;
                tableData.tablePath_L[LcrossCount].second = j;
            } else LcrossCount = 0;
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
            if (table[i][j] == Player) {
                HorCount++;
                tableData.tablePath_R[HorCount].first = i;
                tableData.tablePath_R[HorCount].second = j;
            } else HorCount = 0;
            if (table[j][i] == Player) {
                VerCount++;
                tableData.tablePath_L[VerCount].first = i;
                tableData.tablePath_L[VerCount].second = j;
            } else VerCount = 0;
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
    if (OresHV == 1) tableData.hr = true; else if (OresHV == 2) tableData.vr = true;
    if (OresHV != -1) {
        for (int i = 1; i<=drData.intWin; i++) {
            if (tableData.hr) {
            table[tableData.tablePath_R[i].first][tableData.tablePath_R[i].second] = '=';
            }
            if (tableData.vr) {
                table[tableData.tablePath_L[i].first][tableData.tablePath_L[i].second] = '|';
            }
        }
        return true;
    }
    char OresRL = crossCheck(drData.intWin, table, drData, Player);
    if (OresRL == 1) tableData.cL = true; else if (OresRL == 2) tableData.cR = true;
    if (OresRL != -1) return true;

    return false;
}
