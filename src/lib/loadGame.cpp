//
// Created by huuti on 028, 28/02/2024.
//

#include "include/loadGame.h"
#include "include/winLogic.h"
#include "include/touchLogic.h"

void LoadGame(gameData &gData) {
    char table[9][9] = {};
    startMap(gData.drData, gData.poData);
    int px, py;
    gotoXY(0, 0);
    inLogo();
    inBackGround(gData.drData);
    inKhung(78, 34);
    inBanCo(table, gData.drData);
    inBangDiem(gData.drData, 0, 0);
    inBangThoiGian(gData.drData, 0, 0);
    while (true) {
        getPosMouse(gData.poData);
//        cout << poData.playerPosX << " " << poData.playerPosY;
        dacPos(gData, px, py);
        if (px != -1 && py != -1 && SyntaxCheck(table, py, px)) {
            gotoXY(5, 21);
            std::cout << "                 ";
            gotoXY(7, 22);
            std::cout << "                 ";
//            if (gData.drData.opr) {
                table[py][px] = 'O';
                gotoXY(71, gData.drData.y + 10);
                std::cout << 'X';
//                gData.drData.opr = false;
//                gData.drData.xpr = true;
//            } else if (gData.drData.xpr) {
//                table[py][px] = 'X';
//                gotoXY(71, gData.drData.y + 10);
//                std::cout << 'O';
//                gData.drData.xpr = false;
//                gData.drData.opr = true;
//            }
//            char currentPlayer = gData.drData.xpr ? 'O' : 'X';
            inBanCo(table, gData.drData);
            if (isWin(table, gData.drData, 'O')) {
                inBanCo(table, gData.drData);
                break;
            }

        } else {
            ThongBao();
        }

    }
}