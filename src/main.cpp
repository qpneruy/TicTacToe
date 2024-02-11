//====================================================================================
//  Discord: https://discordapp.com/users/610841389164396565 (qpneruy / </Джихё>)   ||
//  This Verison of Game was make by VO HUYNH HUU TINH (qpneruy)                    ||
//  Github: https://github.com/qpneruy                                              ||
//  Repo: https://github.com/qpneruy/TicTacToe.git                                  ||
//       ████████╗██╗░█████╗░████████╗░█████╗░░█████╗░████████╗░█████╗░███████╗     ||
//       ╚══██╔══╝██║██╔══██╗╚══██╔══╝██╔══██╗██╔══██╗╚══██╔══╝██╔══██╗██╔════╝     ||
//       ░░░██║░░░██║██║░░╚═╝░░░██║░░░███████║██║░░╚═╝░░░██║░░░██║░░██║█████╗░░     ||
//       ░░░██║░░░██║██║░░██╗░░░██║░░░██╔══██║██║░░██╗░░░██║░░░██║░░██║██╔══╝░░     ||
//       ░░░██║░░░██║╚█████╔╝░░░██║░░░██║░░██║╚█████╔╝░░░██║░░░╚█████╔╝███████╗     ||
//       ░░░╚═╝░░░╚═╝░╚════╝░░░░╚═╝░░░╚═╝░░╚═╝░╚════╝░░░░╚═╝░░░░╚════╝░╚══════╝     ||     ||
//====================================================================================
#include <iostream>
#include <conio.h>
#include "include/drawScreen.h"
#include "include/winLogic.h"
#include "include/mapping.h"
#include "include/touchLogic.h"
#include "include/dataInput.h"
#include <Windows.h>
using namespace std;
void init_(drawData drData, posData &poData) {

    SetWindowSize(95, 34);
    inMenuChinh(drData);
    inLogo();
    inKhung(78, 34);
}


void LoadGame(drawData drData, posData poData) {
    char table[9][9] = {};
    startMap(drData, poData);
    int px, py;


    gotoXY(0, 0);
    inBanCo(table, drData);
    inBangDiem(drData, 0, 0);
    inBangThoiGian(drData, 0, 0);
    while (true) {
        getPosMouse(poData);
        dacPos(drData, poData, poData, px, py);
        if (px != -1 && py != -1) {
            gotoXY(5, 21);
            cout << "                 ";
            gotoXY(7, 22);
            cout << "                 ";
            if (drData.opr) {
                table[py][px] = 'O';
                gotoXY(71, drData.y + 10);
                cout << 'X';
                drData.opr = false;
                drData.xpr = true;
            } else if (drData.xpr) {
                table[py][px] = 'X';
                gotoXY(71, drData.y + 10);
                cout << 'O';
                drData.xpr = false;
                drData.opr = true;
            }
            char currentPlayer = drData.xpr ? 'O' : 'X';
            if (isWin(table, drData, currentPlayer)) {
                // win logic
                break;
            }
            inBanCo(table, drData);
            cout << px << " " << py;
        } else {
            ThongBao();
        }

    }
}

int main() {
    drawData drawData{};
    posData poData;
    Player Oplayer{};
    Player Xplayer{};
    drawData.x = 40;
    drawData.y = 11;
//    drawData.height = 9;
//    drawData.width = 9;
//    drawData.xpr = true;
//    drawData.intWin = 9;

    init_(drawData, poData);
    switch (menuHandle(drawData)) {
        case 0:

            break;
        case 1:
            UserInput(drawData);
            LoadGame(drawData, poData);
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
    }
    while (true) {

    }
}