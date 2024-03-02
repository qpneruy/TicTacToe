//
// Created by huuti on 028, 28/02/2024.
//

#include <conio.h>
#include <synchapi.h>
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
    inBangDiem(gData.drData, gData.O.score, gData.X.score);
    inBanCo(gData.table, gData.drData);
    inBangThoiGian(gData.drData, 0, 0);
    std::string currentPlayer = gData.drData.xpr ? "O" : "X";
    int cnt = 0;
    while (true) {
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
            gotoXY(5, 15);
            std::cout << "             ";
            gotoXY(7, 17);
            std::cout << "           ";
//            if (gData.drData.opr) {
                gData.table[py][px] = 'O';
                gotoXY(71, gData.drData.y + 10);
                std::cout << 'X';
                gData.drData.opr = false;
                gData.drData.xpr = true;
//            } else if (gData.drData.xpr) {
//                gData.table[py][px] = 'X';
//                gotoXY(71, gData.drData.y + 10);
//                std::cout << 'O';
//                gData.drData.xpr = false;
//                gData.drData.opr = true;
//            }
            currentPlayer = gData.drData.xpr ? "O" : "X";
            inBanCo(gData.table, gData.drData);
            if (isWin(gData.table, gData.drData, currentPlayer)) {
                inBanCo(gData.table, gData.drData);
                playerWin = true;
            }
        } else if (px == -1 && py == -1){
            if (cnt == 0) inThongBao();
            ++cnt;
        }
        if (playerWin) {
            if (currentPlayer == "X") gData.X.score++; else gData.O.score++;
            switch (inMenuKetThuc()) {
                case 0:
                    for (int i = 0; i < gData.drData.height; ++i) {
                        for (int j = 0; j < gData.drData.width; ++j) {
                            gData.table[i][j] = "";
                        }
                    }
                    return;
                case 1:
                    for (int i = 0; i < gData.drData.height; ++i) {
                        for (int j = 0; j < gData.drData.width; ++j) {
                            gData.table[i][j] = "";
                        }
                    }
                    inBangDiem(gData.drData, gData.O.score, gData.X.score);
                    playerWin = false;
                    break;
                case 2:
                    inBackGround(gData.drData);
                    inKhung(78, 34);
                    gotoXY(27, 15);
                    std::cout << "Nhap Ten: ";
                    gotoXY(27, 16);
                    std::cout << "Khong qua 6 Ky Tu!\n";
                    gotoXY(26, 15);
                    std::string st;
                    while (true) {
                        std::cin >> st;
                        if (st.length() <= 6) break; else {
                            std::cout << "Qua 6 Ky tu! Nhap lai.";
                            Sleep(500);
                            gotoXY(26, 17);
                            std::cout << "                       ";
                        }
                    }
                    gotoXY(37, 15);
                    std::cout << st;
                    gotoXY(26, 18);
                    std::cout << "Da Cap Nhat Bang Xep Hang!";
                    if (currentPlayer == "X") {
                        gData.player.add_player(st, gData.X.score);
                    } else {
                        gData.player.add_player(st, gData.O.score);
                    }
                    esc();
                    return;

            }
        }

    }

}