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
        height{},
        intWin{};
    bool opr = false,
         xpr = false;
};
int inMenuKetThuc();
void inBanCo(std::string tableData[100][100], drawData data);

void inBangDiem(drawData data, int Oscore, int Xscore);

void SetWindowSize(short width, short height);

void inBangThoiGian(drawData drData, int XTime, int OTime);


void inThongBao();

void inKhung(int width, int height);

void gotoXY(int x, int y);


int menuHandle(drawData Data, int selected);

void inMenuChinh(drawData Data);

int getASCIINumber();

void clearScreen();

void inBackGround(drawData Data);
void inManHinh(drawData drData);
void inLogo();
void esc();
#endif //TICTACTOEV2_DRAWSCREEN_H
