//
// Created by huuti on 001, 01/02/2024.
//

#ifndef TICTACTOEV2_DRAWSCREEN_H
#define TICTACTOEV2_DRAWSCREEN_H

#include <string>
#include <iostream>

struct drawData {
    int x{},
        y{},
        width{},
        height{};
    bool opr = false,
         xpr = false;
    int intWin{};
};

void inBanCo(char tableData[9][9], drawData data);

void inBangDiem(drawData data, short Oscore, short Xscore);

void SetWindowSize(short width, short height);

void inBangThoiGian(drawData drData, int XTime, int OTime);

void inKhung(int width, int height);

void gotoXY(int x, int y);

int menuHandle(drawData Data);

void inMenuChinh(drawData Data);

int getASCIINumber();

void clearScreen();

void printInfo();

void inLogo();

#endif //TICTACTOEV2_DRAWSCREEN_H
