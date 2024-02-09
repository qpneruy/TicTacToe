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

#include <Windows.h>
void init_(drawData drData, posData &poData){

    SetWindowSize(95, 34);
    inMenuChinh(drData);
    inLogo();
    printInfo();
    inKhung(78, 34);
    startMap(drData, poData);
}
void LoadGame(drawData drData, posData poData, char table[9][9]) {
    gotoXY(0, 0);
    inBanCo(table, drData);
    inBangDiem(drData,0, 0);
    inBangThoiGian(drData, 0, 0);
}
using namespace std;
int main() {
    char table[9][9] = {};
    int width, height;
    int ch;
    int px, py;
    int intWin = 3;
    bool opr = true,
         xpr = false;
    drawData drawData{};
    posData locationData;
    Player Oplayer{};
    Player Xplayer{};

    drawData.x = 40;
    drawData.y = 11;
    init_(drawData, locationData);
    switch (menuHandle(drawData)) {
        case 0:
            clearScreen();
            inLogo();
            inKhung(78, 34);
            gotoXY(drawData.x - 12 , drawData.y);
            cout << "NHAP KICH THUOC BAN CO !\n";
            gotoXY(drawData.x - 11 , drawData.y + 1);
            cout << "      [N] x [M]        ";
            while (true) {
                gotoXY(drawData.x - 4, drawData.y + 1);
                height = getASCIINumber() - 48;
                cout << height;
                gotoXY(drawData.x + 2, drawData.y + 1);
                width = getASCIINumber() - 48;
                cout << (width != -35 && width != -40) ? width : ;
                ch = getch();
                if (ch == 13) {
                    drawData.height = height;
                    drawData.width = width;
                    break;
                }
                if (ch == 8) {
                    gotoXY(drawData.x - 11 , drawData.y + 1);
                    cout << "      [N] x [M]        ";
                    drawData.height = 0;
                    drawData.width = 0;
                    gotoXY(drawData.x - 4, drawData.y + 1);
                }
            }
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
 while (true){

 }
}