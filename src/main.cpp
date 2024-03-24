//====================================================================================
//  SAN PHAM CUU HUU TINH                                                           ||
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
    inManHinh();
    gData.drData.height = 3;
    gData.drData.width = 3;
    gData.drData.opr = true;
    gData.drData.intWin = 3;
    init_file();
    gData = load();
    int selected = 0;
    inBangThongBao(gData.drData);
    while (true) {
        gotoXY(0, 0);
        inBackGround(gData.drData);
        inMenuChinh(gData.drData);
        switch (menuHandle(gData.drData, selected)) {
            case 0:
                LoadGame(gData, false);
                selected = 0;
                break;
            case 1:
                UserInput(gData.drData);
                LoadGame(gData, true);
                selected = 1;
                break;
//            case 2:
////              inCaiDat(gData.drData, SettingSate); // co san esc
//                selected = 2;
//                break;
            case 2:
                inManHinh();
                inBangXepHang(gData.drData, gData.player);
                esc();
                selected = 2;
                break;
            case 3:
                gotoXY(1, 30);
//                std::cout << "Discord: https://discordapp.com/users/610841389164396565 (qpneruy / </Джихё>)\n"
//                             "║This Verison of Game was make by VO HUYNH HUU TINH (qpneruy) \n"
//                             "║Github: https://github.com/qpneruy       \n"
//                             "║Repo: https://github.com/qpneruy/TicTacToe.git  ";
                std::cout << "SAN PHAM CUA HUU TINH";
                esc();
                selected = 3;
                break;
        }
    }
}