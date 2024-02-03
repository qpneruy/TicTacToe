//====================================================================================
//  Discord: https://discordapp.com/users/610841389164396565 (qpneruy / </Джихё>)   ||
//  This Verison of Game was make by VO HUYNH HUU TINH (qpneruy)                    ||
//  Github: https://github.com/qpneruy                                              ||
//  Repo: https://github.com/qpneruy/TicTacToe.git                                  ||
//      ████████╗██╗░█████╗░████████╗░█████╗░░█████╗░████████╗░█████╗░███████╗      ||
//      ╚══██╔══╝██║██╔══██╗╚══██╔══╝██╔══██╗██╔══██╗╚══██╔══╝██╔══██╗██╔════╝      ||
//      ░░░██║░░░██║██║░░╚═╝░░░██║░░░███████║██║░░╚═╝░░░██║░░░██║░░██║█████╗░░      ||
//      ░░░██║░░░██║██║░░██╗░░░██║░░░██╔══██║██║░░██╗░░░██║░░░██║░░██║██╔══╝░░      ||
//      ░░░██║░░░██║╚█████╔╝░░░██║░░░██║░░██║╚█████╔╝░░░██║░░░╚█████╔╝███████╗      ||
//      ░░░╚═╝░░░╚═╝░╚════╝░░░░╚═╝░░░╚═╝░░╚═╝░╚════╝░░░░╚═╝░░░░╚════╝░╚══════╝      ||
//====================================================================================
#include <iostream>
#include <windows.h>
#include "include/drawScreen.h"
#include "include/winLogic.h"
#include "include/mapping.h"
#include "include/touchLogic.h"
using namespace std;



int main() {
    char table[9][9] = {};
    Player Data{};
    int width, height, z;
    SetWindowSize(80, 35);
    inLogo();
    width = 9;
    height = 9+1;

    drawData drawData{};
    posData locationData;
    drawData.height = height;
    drawData.width = width;
    drawData.x = 40 - (width * 4 / 2) - 3;
    drawData.y = 9;


    inBangDiem(999, 0, 'O');
    inBangThoiGian(150, 0);
    printInfo();
    int px, py;
    gotoXY(0, 30);
    startMap(drawData, locationData);
//    for (int i = 0; i < drawData.width; i++) {
//        cout << locationData.tableHor[i] << " ";
//    }
//    cout << "\n";
//    for (int i = 0; i < drawData.height; i++) {
//        cout << locationData.tableVer[i] << " ";
//    }
    bool luotx = true, luoto = false;
    while (true) {
        getPosMouse(locationData);
        dacPos(drawData, locationData, locationData.playerPosX, locationData.playerPosY, px, py);
        inBanCo(table, drawData);
        cout << luotx << " " << luoto;
    }

}