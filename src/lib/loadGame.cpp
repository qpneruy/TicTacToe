//
// Created by huuti on 028, 28/02/2024.
//

#include <conio.h>
#include "include/loadGame.h"
#include "include/winLogic.h"
#include "include/touchLogic.h"
void LoadGame(gameData &gData, bool isNewGame) {
    if (isNewGame) {
        for (int i = 0; i < gData.drData.height; ++i) {
            for (int j = 0; j < gData.drData.width; ++j) {
                gData.table[i][j] = "";
            }
        }
    }
    bool playerWin = false;
    startMap(gData.drData, gData.poData);
    int px, py;
    gotoXY(0, 0);
    inLogo();
    inBackGround(gData.drData);
    inKhung(78, 34);
    inBanCo(gData.table, gData.drData);
    inBangDiem(gData.drData, gData.O.score, gData.X.score);
    inBangThoiGian(gData.drData, 0, 0);
    std::string currentPlayer = gData.drData.xpr ? "O" : "X";
    int cnt = 0;
    while (!playerWin) {
        if (kbhit()){
            int ch = getch();
            if (ch == 27) {
                save(gData);
                return;
            }
        }
        getEvent(gData.poData);
        dacPos(gData, px, py);
        if (px != -1 && py != -1 && SyntaxCheck(gData.table, py, px)) {
            cnt = 0;
            gotoXY(5, 21);
            std::cout << "                 ";
            gotoXY(7, 22);
            std::cout << "                 ";
            if (gData.drData.opr) {
                gData.table[py][px] = 'O';
                gotoXY(71, gData.drData.y + 10);
                std::cout << 'X';
                gData.drData.opr = false;
                gData.drData.xpr = true;
            } else if (gData.drData.xpr) {
                gData.table[py][px] = 'X';
                gotoXY(71, gData.drData.y + 10);
                std::cout << 'O';
                gData.drData.xpr = false;
                gData.drData.opr = true;
            }
            currentPlayer = gData.drData.xpr ? "O" : "X";
            inBanCo(gData.table, gData.drData);
            if (isWin(gData.table, gData.drData, currentPlayer)) {
                inBanCo(gData.table, gData.drData);
                playerWin = true;
            }
        } else if (px == -1 && py == -1){
            if (cnt == 0) ThongBao();
            ++cnt;
        }

    }

//    if (playerWin) {
//        if (currentPlayer == "O") gData.O.score++; else gData.X.score++;
//    }
}