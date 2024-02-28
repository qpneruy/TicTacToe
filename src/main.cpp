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
//       ░░░╚═╝░░░╚═╝░╚════╝░░░░╚═╝░░░╚═╝░░╚═╝░╚════╝░░░░╚═╝░░░░╚════╝░╚══════╝     ||
//====================================================================================
#include <iostream>
#include <conio.h>
#include "include/drawScreen.h"
#include "include/archive.h"
#include "include/dataInput.h"
#include "include/loadGame.h"
using namespace std;
void init_(const gameData& gData) {
    SetWindowSize(80, 35);
    inLogo();
//    inBackGround(gData.drData);
    inMenuChinh(gData.drData);
    inKhung(78, 34);
}



int main() {
    gameData gData;
    gData.drData.x = 40;
    gData.drData.y = 11;
    init_(gData);
    gotoXY(40, 11);
//   inBangXepHang(gData.drData);
    switch (menuHandle(gData.drData)) {
        case 0:
            gData = load();
            break;
        case 1:
            UserInput(gData.drData); // thay cac tham so truyen vao bang Struct gameData
            LoadGame(gData);
            break;
        case 2:
            break;
        case 3:
            inBangXepHang(gData.drData);
            break;
        case 4:
            break;
    }
    while (true) {
    }
}