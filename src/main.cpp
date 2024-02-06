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
#include "include/drawScreen.h"
#include "include/winLogic.h"
#include "include/mapping.h"
#include "include/touchLogic.h"
#include <conio.h>
#include <Windows.h>
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_ENTER 13
#define KEY_ESC 27
using namespace std;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
string MainMenu[9] = {"Tiep Tuc", "Choi Moi", "Cai Dat", "Tac Gia"};
void init_(drawData drData, posData &poData){
    char table[9][9] = {};
    SetWindowSize(80, 35);
    inLogo();
    inBangDiem(0,0);
    inBangThoiGian(0, 0);
    inBanCo(table, drData);
    printInfo();
    startMap(drData, poData);
}
int main() {
    char table[9][9] = {};
    int width, height;
    int px, py;
    bool opr = true,
         xpr = false;
    drawData drawData{};
    posData locationData;
    Player Oplayer{};
    Player Xplayer{};
    width = 9;
    height = 9;

    drawData.height = height;
    drawData.width = width;
    drawData.x = 40 - (width * 4 / 2) - 3;
    drawData.y = 9;
    init_(drawData, locationData);
    while (true) {
        getPosMouse(locationData);
        dacPos(drawData, locationData, locationData, px, py);
        if (px != -1 && py != -1) {
            if (opr) {
                table[py][px] = 'O';
                gotoXY(70, 20);
                cout << 'X';
                opr = false;
                xpr = true;
            } else if (xpr) {
                table[py][px] = 'X';
                gotoXY(70, 20);
                cout << 'O';
                xpr = false;
                opr = true;
            }
            inBanCo(table, drawData);
        }

    }
}