//
// Created by huuti on 002, 02/02/2024.
//

#include "include/winLogic.h"
#include "include/drawScreen.h"
#include <iostream>

TableData tableData;
//char crossCheck(int intWin, char table[9][9], drawData drawData, char Player) {
//    int RcrossCount, LcrossCount;
//    char n = drawData.intWin;
//    for (int i = -n; i < n; i++) {
//        RcrossCount = 0;
//        LcrossCount = 0;
//        for (int j = 0; j < drawData.intWin; j++) {
//            if (abs(n-j+i) <= drawData.intWin) {
//                if (table[j][abs(n-j+i)] == Player) {
//                    RcrossCount++;
//                    tableData.tablePath_R[RcrossCount].first = j;
//                    tableData.tablePath_R[RcrossCount].second = n - j + i;
//                } else RcrossCount = 0;
//            }
//            if (table[j][i + j] == Player) {
//                LcrossCount++;
//                gotoXY(10, 10);
////                std::cout << j << " " << j + i << " "  << LcrossCount << "\n";
//                tableData.tablePath_L[LcrossCount].first = j;
//                tableData.tablePath_L[LcrossCount].second = i + j;
//            } else LcrossCount = 0;
//            if (RcrossCount >= intWin ) {
//                return 1;
//            } else if (LcrossCount >= intWin) {
//                return 2;
//            }
//        }
//    }
//    return -1;
//}
bool crossCheck(int intWin, char table[9][9], drawData drawData, char Player) {
    int l = 0, cnt = 0, tsCC, tsCR;
    int LcrossCount = 0;
    if (drawData.height >= drawData.width) {
        tsCC = drawData.height;
        tsCR = drawData.width;
    } else if (drawData.width > drawData.height) {
        tsCC = drawData.width;
        tsCR = drawData.height;
    }
    for (int u = -tsCC; u <= tsCC; u++) {
        l = 0;
        for (int i = 0; i < tsCC + 1; i++) {
            for (int j = 0; j < tsCR + 1; j++) {
                int kq = i + 1;
                if (i - kq + 1 == j) {
                    l++;
                    if (table[i + u][l - 1] == Player) {
                        ++LcrossCount;
                        tableData.tablePath_L[LcrossCount].first = i + u;
                        tableData.tablePath_L[LcrossCount].second = l - 1;
                        if (cnt == intWin) {
                            return true;
                        }
                    } else {
                        cnt = 0;
                    }
                }

            }
        }
    }
    return false;
}
char crossProcess(int intWin, char table[9][9], drawData drawData, char Player) {
    char R_table[9][9] = {};
    for (int i = 0; i < drawData.height; i++) {
        for (int j = drawData.width - 1; j >= 0; j--) {
            R_table[i][drawData.width - j - 1] = table[i][j];
        }
    }
    crossCheck(intWin, table, drawData, Player);
    crossCheck(intWin, R_table, drawData, Player);
}
char HorVerCheck(int intWin, char table[9][9], drawData drawData, char Player) {
    int HorCount, VerCount;
    for (int i = 0; i < drawData.height; i++) {
        HorCount = 0;
        for (int j = 0; j < drawData.width; j++) {
            if (table[i][j] == Player) {
                ++HorCount;
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

//    if (OresRL != -1) {
//        if (OresRL == 1) {
//            for (int i = 1; i <= drData.intWin; i++) {
//                table[tableData.tablePath_R[i].first][tableData.tablePath_R[i].second] = '/';
//            }
//        }
//        if (OresRL == 2) {
//            for (int i = 1; i <= drData.intWin; i++) {
//                table[tableData.tablePath_L[i].first][tableData.tablePath_L[i].second] = '\\';
//            }
//        }
//        inBanCo(table, drData);
//        return true;
//    }
    return false;
}
