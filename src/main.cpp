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
#include "include/drawScreen.h"
#include "include/archive.h"
#include "include/dataInput.h"
#include "include/loadGame.h"
#include "include/drawScreen/inBangXepHang.h"

using namespace std;
void init_(gameData& gData) {
    init_file();
    SetWindowSize(80, 35);
    gData.drData.x = 40;
    gData.drData.y = 11;
}
int main() {
    gameData gData;
    init_(gData);
    gotoXY(40, 11);
    inManHinh(gData.drData);
    int selected = 0;
    inBangThoiGian(gData.drData, 0, 0);
    while (true) {
        gotoXY(0, 0);
        inBackGround(gData.drData);
        inMenuChinh(gData.drData);
        switch (menuHandle(gData.drData, selected)) {
            case 0:
//                gData = load();
//                LoadGame(gData, false);
                selected = 0;
//                esc();
                break;
            case 1:
                UserInput(gData.drData);
                LoadGame(gData, true);
                selected = 1;
                break;
            case 2:
                //chua xong
//                inCaiDat(gData.drData, SettingSate); // co san esc
                selected = 2;
                break;
            case 3:
                inManHinh(gData.drData);
                inBangXepHang(gData.drData, gData.player);
                esc();
                selected = 3;
                break;
            case 4:
                gotoXY(1, 30);
                std::cout << "Discord: https://discordapp.com/users/610841389164396565 (qpneruy / </Джихё>)\n"
                             "║This Verison of Game was make by VO HUYNH HUU TINH (qpneruy) \n"
                             "║Github: https://github.com/qpneruy       \n"
                             "║Repo: https://github.com/qpneruy/TicTacToe.git  ";
                esc();
                selected = 4;
                break;
        }
    }
}