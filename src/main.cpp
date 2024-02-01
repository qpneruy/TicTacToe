#include <iostream>
#include <windows.h>
#include "include/drawScreen.h"
using namespace std;
struct Player {
    int PosX;
    int PosY;
    int score;
};
struct Data {
    Player XPLayer;
    Player OPLayer;
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
void gotoXY(int x, int y) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD CursorPosition;
    CursorPosition.X = x;
    CursorPosition.Y = y;
    SetConsoleCursorPosition(hConsole, CursorPosition);
}
void clearScreen() {
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord = {
            0,
            0
    };
    DWORD count;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hStdOut, & csbi);
    FillConsoleOutputCharacter(hStdOut, ' ', csbi.dwSize.X * csbi.dwSize.Y, coord, & count);
    SetConsoleCursorPosition(hStdOut, coord);
}
void inBangDiem(Data data, int x){
    string line1 = "      |";
    string line2 = "      |";
    if (data.XPLayer.score < 10) line1 = " " + line1;
    if (data.OPLayer.score < 10) line2 = " " + line2;
    gotoXY(x, 1);
    cout << " ______________";
    gotoXY(x, 2);
    cout << "/     DIEM     \\";
    gotoXY(x, 3);
    cout << "+----+---------+";
    gotoXY(x, 4);
    cout << "| X: | " << data.XPLayer.score << line1;
    gotoXY(x, 5);
    cout << "+----+---------+";
    gotoXY(x, 6);
    cout << "| O: | " <<  data.OPLayer.score << line2;
    gotoXY(x, 7);
    cout << "+----+---------+";
}
int main() {
    char a[9][9] = {};

    Data Data;
    int x, y, z;
    SetWindowSize(80, 35);
    while (cin >> x >> y) {
        clearScreen();
        inBanCo(a, x, y, 40-(x * 4 / 2)-5);
        inBangDiem(Data, 40+(x * 4 / 2)+6);
        gotoXY(0, 0);
    }
    std::cin.get();
    return 0;
}