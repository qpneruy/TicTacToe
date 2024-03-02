#include "include/mapping.h"

//
// Created by huuti on 003, 03/02/2024.
//
#include "include/touchLogic.h"
#include <conio.h>
#include <Windows.h>

int x_, y_;

void getEvent(posData &data) {
//    Pressed = false;
    HANDLE hStdin;
    DWORD fdwMode, eventRead;
    INPUT_RECORD Inrec;
    hStdin = GetStdHandle(STD_INPUT_HANDLE);
    fdwMode = ENABLE_EXTENDED_FLAGS;
    SetConsoleMode(hStdin, fdwMode);
    fdwMode = ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT;
    SetConsoleMode(hStdin, fdwMode);
//    while (!Pressed) {
        PeekConsoleInput(hStdin, &Inrec, 1, &eventRead);
        ReadConsoleInput(hStdin, &Inrec, 1, &eventRead);
        x_ = Inrec.Event.MouseEvent.dwMousePosition.X;
        y_ = Inrec.Event.MouseEvent.dwMousePosition.Y;
        switch (Inrec.EventType) {
            case MOUSE_EVENT: {
                if (Inrec.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED) {
                    data.playerPosX = x_;
                    data.playerPosY = y_;
//                    std::cout << " " << x_ << "  " << y_;
//                    Pressed = true;
                }
                break;
            }
//        }
//        return;
    }
}

int searchNearestPos(const int mapTable[9], int x, int n) {
    for (int i = 0; i < n; i++) {
        if (x > mapTable[i] && x < mapTable[i + 1]) {
            if (x - mapTable[i] == 1) return i;
            if (mapTable[i + 1] - x == 1) return i + 1;
            return -1;
        }
    }
    return -1;
}

void dacPos(const gameData& gdata, int &o_x, int &o_y) {
    bool found_1 = false, found_2 = false;
    if (gdata.drData.x + (gdata.drData.width * 4 / 2)+1 == gdata.poData.playerPosX || gdata.drData.x + (gdata.drData.width * 4 / 2)+2 == gdata.poData.playerPosX  ) {
        o_x = -1;
        o_y = -1;
        found_1 = true;
        found_2 = true;
    }
    if (gdata.poData.playerPosX == gdata.poData.tableHor[0] - 1) {
        o_x = 0;
        found_1 = true;
        found_2 = true;
    }
    if (!found_1) {
        for (int i = 0; i <= gdata.drData.width; i++) {
            if (gdata.poData.tableHor[i] == gdata.poData.playerPosX) {
                o_x = i;
                found_2 = true;
            }
        }
    }
    if (!found_2) o_x = searchNearestPos(gdata.poData.tableHor, gdata.poData.playerPosX, gdata.drData.width);
    if (o_x != -1) {
        for (int i = 0; i < gdata.drData.height; i++) {
            if (gdata.poData.tableVer[i] == gdata.poData.playerPosY) {
                o_y = i;
                return;
            }
        }
    }
    o_y = -1;

}
bool SyntaxCheck(std::string table[9][9], int y, int x) {
    if (table[y][x] != "X" && table[y][x] != "O"){
        return true;
    }
    return false;
}

