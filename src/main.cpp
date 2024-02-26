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
#include "include/archive.h"
#include "include/dataInput.h"
#include <Windows.h>
using namespace std;
void init_(drawData drData, posData &poData) {
    SetWindowSize(95, 34);
    inLogo();
    inBackGround(drData);
    inMenuChinh(drData);
    inKhung(78, 34);
}


void LoadGame(drawData drData, posData poData) {
    char table[9][9] = {};
    startMap(drData, poData);
    int px, py;
    gotoXY(0, 0);
    inLogo();
    inBackGround(drData);
    inKhung(78, 34);
    inBanCo(table, drData);
    inBangDiem(drData, 0, 0);
    inBangThoiGian(drData, 0, 0);
    while (true) {
        getPosMouse(poData);
//        cout << poData.playerPosX << " " << poData.playerPosY;
        dacPos(drData, poData, poData, px, py);
        if (px != -1 && py != -1 && SyntaxCheck(table, py, px)) {
            gotoXY(5, 21);
            cout << "                 ";
            gotoXY(7, 22);
            cout << "                 ";
//            if (drData.opr) {
                table[py][px] = 'O';
                gotoXY(71, drData.y + 10);
                cout << 'X';
//                drData.opr = false;
//                drData.xpr = true;
//            } else if (drData.xpr) {
//                table[py][px] = 'X';
//                gotoXY(71, drData.y + 10);
//                cout << 'O';
//                drData.xpr = false;
//                drData.opr = true;
//            }
            char currentPlayer = drData.xpr ? 'O' : 'X';
            inBanCo(table, drData);
            if (isWin(table, drData, currentPlayer)) {
                inBanCo(table, drData);
                break;
            }

        } else {
            ThongBao();
        }

    }
}
std::sort();
int main() {
//    ios_base::sync_with_stdio(false);
//    cout.tie(nullptr);
    drawData drData{};
    posData poData;
    Player Oplayer{};
    Player Xplayer{};
    string  table[9][9] = {};
    table[0][1] = "X";
    table[0][2] = "O";
    table[1][2] = "X";
    table[2][2] = "O";
    leaderboard ldpo;
    leaderboard ldpx;
    drData.x = 40;
    drData.y = 11;
    drData.height = 9;
    drData.width = 9;
    drData.xpr = true;
    drData.intWin = 9;
    ldpx.add_player("huutinh", 100);
save(table, drData, Oplayer, Xplayer, ldpx, ldpo);
    load(table, drData, Oplayer, Xplayer, ldpx, ldpo);
//    init_(drData, poData);
//    startMap(drData, poData);
//    switch (menuHandle(drData)) {
//        case 0:
//            break;
//        case 1:
//            UserInput(drData);
//            LoadGame(drData, poData);
//            break;
//        case 2:
//            break;
//        case 3:
//            break;
//        case 4:
//            break;
//    }
    while (true) {

    }
}