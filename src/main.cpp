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


void LoadGame(drawData drData, posData locationData) {
    char table[9][9] = {};
    startMap(drData, locationData);
    int px, py;
    int intWin = 9;
    bool opr = true,
            xpr = false;
    gotoXY(0, 0);
    inBanCo(table, drData);
    inBangDiem(drData, 0, 0);
    inBangThoiGian(drData, 0, 0);
    while (true) {
        getPosMouse(locationData);
        dacPos(drData, locationData, locationData, px, py);
        cout << py << " " << px;
        if (px != -1 && py != -1) {
            if (opr) {
                table[py][px] = 'O';
                gotoXY(71, drData.y + 10);
                cout << 'X';
                opr = false;
                xpr = true;
            } else if (xpr) {
                table[py][px] = 'X';
                gotoXY(71, drData.y + 10);
                cout << 'O';
                xpr = false;
                opr = true;
            }
            char currentPlayer = xpr ? 'O' : 'X';
            if (crossCheck(intWin, table, drData, currentPlayer) ||
            HorVerCheck(intWin, table, drData, currentPlayer)) {
                // win logic
                break;
            }
            inBanCo(table, drData);
        }

    }
}

int main() {
    drawData drawData{};
    posData locationData;
    Player Oplayer{};
    Player Xplayer{};

    drawData.x = 40;
    drawData.y = 11;
    init_(drawData, locationData);
    switch (menuHandle(drawData)) {
        case 0:
            UserInput(drawData, locationData);
            break;
        case 1:

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