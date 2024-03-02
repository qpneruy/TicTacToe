
#include "include/winLogic.h"
#include "include/drawScreen.h"
#include <iostream>

TableData tableData;
bool crossCheck(int intWin, std::string table[100][100], drawData drawData, std::string Player) {
    int RcrossCount, LcrossCount;
    int n = drawData.intWin;
    for (int i = 0; i < drawData.height; i++) {
        for (int j = 0; j < drawData.width; j++) {
            RcrossCount = 0;
            LcrossCount = 0;
            for (int k = 0; k < intWin; k++) {
                // Kiểm tra đường chéo chính
                if (i + k < drawData.height && j + k < drawData.width &&
                    table[i + k][j + k] == Player) {
                    RcrossCount++;
                } else {
                    RcrossCount = 0;
                }
                // Kiểm tra đường chéo phụ
                if (i - k >= 0 && j + k < drawData.width &&
                    table[i - k][j + k] == Player) {
                    LcrossCount++;
                } else {
                    LcrossCount = 0;
                }
                if (RcrossCount >= intWin || LcrossCount >= intWin) {
                    return true;
                }
            }
        }
    }
    return false;
}
bool drawCheck(std::string table[100][100], drawData drData) {
    int intDraw = drData.width * drData.height, count = 0;
    for (int i = 0; i < drData.height; i++) {
        for (int j = 0; j < drData.width; j++) {
            if (table[i][j] == "X" || table[i][j] == "O") {
                ++count;
            }
        }
    }
    return count == intDraw;
}
bool drawC(std::string table[100][100], drawData drData) {
    if (drawCheck(table, drData)) {
        for (int i = 0; i < drData.height; i++) {
            for (int j = 0; j < drData.width; j++) {
                table[i][j] = "*";
            }
        }
        return true;
    }
    return false;
}
char HorVerCheck(int intWin, std::string table[100][100], drawData drawData, std::string Player) {
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
            } else VerCount = 0;
        }
        if (VerCount >= intWin) {
            return 2;
        }
    }
    return -1;
}

bool isWin(std::string table[100][100], drawData drData, std::string Player) {
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
    if (crossCheck(drData.intWin, table, drData, Player)) return true;
    return false;
}
