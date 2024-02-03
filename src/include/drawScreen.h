//
// Created by huuti on 001, 01/02/2024.
//

#ifndef TICTACTOEV2_DRAWSCREEN_H
#define TICTACTOEV2_DRAWSCREEN_H

#include <string>
#include <iostream>
struct drawData {
    int x;
    int y;
    int width;
    int height;
};

void inBanCo(char tableData[9][9], drawData data);

void inBangDiem(short Oscore, short Xscore, char peri);

void SetWindowSize(short width, short height);

void inBangThoiGian(int XTime, int OTime);

void gotoXY(int x, int y);

void clearScreen();

void printInfo();

void inLogo();

#endif //TICTACTOEV2_DRAWSCREEN_H
