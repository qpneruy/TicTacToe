#include <iostream>
#include <windows.h>
#include "include/drawScreen.h"
using namespace std;
struct PlayerPos {
    int PosX;
    int PosY;
};
struct Data {
    PlayerPos XPLayer;
    PlayerPos OPLayer;
    int intWin;

};
void SetWindowSize(SHORT width, SHORT height) {
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    SMALL_RECT WindowSize;
    WindowSize.Top = 0;
    WindowSize.Left = 0;
    WindowSize.Right = width;
    WindowSize.Bottom = height;

    SetConsoleWindowInfo(hStdout, 1, &WindowSize);
}


bool HorVerCheck(Data Data, char table[9][9], int width, int height, char Player) {
    int HorCount = 0, ZHorCount = 0;
    int VerCount = 0, ZVerCount = 0;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++){
            if (table[i][j] == Player) HorCount++; else HorCount = 0;
            if (table[j][i] == Player) ZHorCount++; else ZHorCount = 0;
        }
        if (HorCount == Data.intWin || VerCount == Data.intWin) return true;
    }
    return false;
}

int main() {
    Data Data;
    char a[9][9] = {};
    a[5-1][9-1] = 'X';
    a[5-1][8-1] = 'X';
    a[5-1][7-1] = 'X';
    a[5-1][6-1] = 'O';

    a[9-1][5-1] = 'X';
    a[8-1][5-1] = 'X';
    a[7-1][5-1] = 'X';
    a[6-1][5-1] = 'O';
    inBanCo(a, 9, 8);
//    Data.intWin = 4;
//    cout << " >>>" << HorVerCheck(Data, a, 9, 8, 'X') << " <<";

    std::cin.get();
    return 0;
}