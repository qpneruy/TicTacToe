//
// Created by huuti on 002, 02/02/2024.
//

#include "include/winLogic.h"
#include "include/drawScreen.h"
#include <iostream>
#include <synchapi.h>

TableData tableData;
char crossCheck(char intWin, char table[9][9], drawData drawData, char Player) {
    int RcrossCount, LcrossCount;
    int n = std::max(static_cast<int>(drawData.width), static_cast<int>(drawData.height));
    for (int i = -n; i <= n; i++) {
        RcrossCount = 0;
        LcrossCount = 0;
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
    int HorCount, VerCount;
    for (int i = 0; i < drawData.height; i++) {
        HorCount = 0;
        for (int j = 0; j < drawData.width; j++) {
            if (table[i][j] == Player) {
                ++HorCount;
                std::cout << i << " " << j << "\n";
                tableData.tablePath_R[HorCount].first = i;
                tableData.tablePath_R[HorCount].second = j;
            } else HorCount = 0;
            if (HorCount >= intWin ) {
                return 1;
            }
        }
    }
    for (int i = 0; i < drawData.width; i++ ){
        VerCount = 0;
        for (int j = 0; j < drawData.height; j++){
             if (table[j][i] == Player){
                 ++VerCount;
                 tableData.tablePath_L[VerCount].first = i;
                 tableData.tablePath_L[VerCount].second = j;
             }
        }
        if (VerCount >= intWin) {
            return 2;
        }
    }
    return -1;
}

bool isWin(char table[9][9], drawData drData, char Player) {
    char OresHV = HorVerCheck(drData.intWin, table, drData, Player);;
    if (OresHV != -1) {
    if (OresHV == 1) {
        for (int i = 1; i <= drData.intWin; i++) {
            table[tableData.tablePath_R[i].first][tableData.tablePath_R[i].second] = '=';
        }
    }
    if (OresHV == 2) {
        for (int i = 1; i <= drData.intWin; i++) {
            table[tableData.tablePath_L[i].second][tableData.tablePath_L[i].first] = '|';
        }
    }
        inBanCo(table, drData);
        return true;
    }
    char OresRL = crossCheck(drData.intWin, table, drData, Player);
    if (OresRL != -1) {
        if (OresRL == 1) {
            for (int i = 1; i <= drData.intWin; i++) {
                table[tableData.tablePath_R[i].second][tableData.tablePath_R[i].first] = '=';
                std::cout << tableData.tablePath_R[i].first << " " << tableData.tablePath_R[i].second << " \n";
            }
        }
        if (OresRL == 2) {
            for (int i = 1; i <= drData.intWin; i++) {
                table[tableData.tablePath_L[i].second][tableData.tablePath_L[i].first] = '|';
                std::cout << tableData.tablePath_L[i].first << " " << tableData.tablePath_L[i].second << " \n";
            }
        }
        inBanCo(table, drData);
        return true;
    }
    return false;
}
