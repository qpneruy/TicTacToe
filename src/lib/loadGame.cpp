//
// Created by huuti on 028, 28/02/2024.
//
#include <synchapi.h>
#include "include/loadGame.h"
#include "include/winLogic.h"
#include "include/touchLogic.h"
#include "include/dataInput.h"
void LoadGame(gameData &gData, bool isNewGame) {
    gData.drData.x = 40;
    gData.drData.y = 11;
    if (isNewGame) {
        gData.O.score = 0;
        gData.X.score = 0;
        for (int i = 0; i < gData.drData.height; ++i) {
            for (int j = 0; j < gData.drData.width; ++j) {
                gData.table[i][j].clear();
            }
        }
    }
    bool isNofication = false,
         playerWin = false,
         draw = false;
    int  px = -1, py = -1;
    startMap(gData.drData, gData.poData); gotoXY(0, 0);

    inLogo(); inBackGround(gData.drData);
    inKhung(78, 34);
    inBangDiem(gData.drData, gData.O.score, gData.X.score);
    inBanCo(gData.table, gData.drData); inBangThongBao(gData.drData);

    std::string currentPlayer = gData.drData.xpr ? "O" : "X";
    while (true) {
        getEvent(gData.poData);
        if (gData.poData.playerPosX == -2 & gData.poData.playerPosY == -2) {
            gData.poData.playerPosX = -1; gData.poData.playerPosY = -1;
            save(gData); gData = {};
            gData.drData.x = 40; gData.drData.y = 11;
            return;
        }
        dacPos(gData, px, py);
        if (px >= 0 && py >= 0 && SyntaxCheck(gData.table, py, px)) {
            isNofication = false;
            gotoXY(5, 15);
            std::cout << "             ";
            gotoXY(7, 17);
            std::cout << "           ";
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
                gotoXY(7, 16);
                std::cout <<  currentPlayer << " Thang!";
                playerWin = true;
            }
            if (drawC(gData.table, gData.drData)) {
                for (int i = 0; i < gData.drData.height; i++) {
                    for (int j = 0; j < gData.drData.width; j++) {
                        gData.table[i][j] = "*";
                    }
                    gotoXY(4, 16);
                    std::cout << "     Hoa!     ";
                    Sleep(300);
                    playerWin = true;
                    inBanCo(gData.table, gData.drData);
                }
                draw = true;
            } else draw = false;
        } else if (px == -1){
            if (!isNofication) inThongBao();
            isNofication = true;
        }
        if (playerWin) {
            for (int i = 0; i < gData.drData.height; ++i) {
                for (int j = 0; j < gData.drData.width; ++j) {
                    gData.table[i][j].clear();
                }
            }
            if (!draw) {
            if (currentPlayer == "X") gData.X.score++; else gData.O.score++; }
            switch (inMenuKetThuc()) {
                case 0:
                    gData.O.score = 0;
                    gData.X.score = 0;
                    return;
                case 1:
                    gData.poData.playerPosY = -100;
                    gData.poData.playerPosX = -100;
                    inBangDiem(gData.drData, gData.O.score, gData.X.score);
                    playerWin = false;
                    inBanCo(gData.table, gData.drData);
                    break;
                case 2:
                    inBackGround(gData.drData);
                    inKhung(78, 34);
                    gotoXY(27, 15);
                    std::cout << "Nhap Ten:";
                    gotoXY(27, 16);
                    std::cout << "Khong qua 6 Ky Tu!\n";
                    std::string playerName = userNameInput();
                    gotoXY(26, 18);
                    std::cout << "Da Cap Nhat Bang Xep Hang!";
                    gotoXY(26, 19);
                    std::cout << "      -ESC DE THOAT-";
                    if (gData.X.score > gData.O.score) {
                        gData.player.add_player(playerName, gData.X.score);
                    } else {
                        gData.player.add_player(playerName, gData.O.score);
                    }
                    esc();
                    save(gData);
                    return;

            }
            // Xoa thong bao chien thang
            gotoXY(4, 16);
            std::cout << "           ";
        }

    }

}