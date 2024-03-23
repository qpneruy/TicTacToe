//
// Created by huuti on 003, 03/02/2024.
//
#include "include/mapping.h"
#include "include/touchLogic.h"
#include <Windows.h>

int x_, y_;
HANDLE hStdin;
DWORD fdwMode, eventRead;
INPUT_RECORD Inrec;
void getEvent(posData &data) {
    hStdin = GetStdHandle(STD_INPUT_HANDLE);
    fdwMode = ENABLE_EXTENDED_FLAGS;
    SetConsoleMode(hStdin, fdwMode);
    fdwMode = ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT;
    SetConsoleMode(hStdin, fdwMode);

    PeekConsoleInput(hStdin, &Inrec, 1, &eventRead);
    ReadConsoleInput(hStdin, &Inrec, 1, &eventRead);
    x_ = Inrec.Event.MouseEvent.dwMousePosition.X;
    y_ = Inrec.Event.MouseEvent.dwMousePosition.Y;
    switch (Inrec.EventType) {
        case MOUSE_EVENT: {
            if (Inrec.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED) {
                data.playerPosX = x_;
                data.playerPosY = y_;
            }
            break;
        }
        case KEY_EVENT: {
            if (Inrec.Event.KeyEvent.uChar.AsciiChar == 27) {
                data.playerPosX = -2;
                data.playerPosY = -2;
                return;
            }
        }
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

void dacPos(const gameData& gData, int &o_x, int &o_y) {
    bool found_1 = false, found_2 = false;
    if (gData.poData.playerPosX == 0 && gData.poData.playerPosY == 0){
        o_x = -2;
        o_y = -1;
        return;
    }
    if (gData.poData.playerPosX == -2 && gData.poData.playerPosY == -2) {
        o_x = -1;
        o_y = -1;
        return;
    }
    if (gData.drData.x + (gData.drData.width * 4 / 2) + 1 == gData.poData.playerPosX || gData.drData.x + (gData.drData.width * 4 / 2) + 2 == gData.poData.playerPosX  ) {
        o_x = -1;
        o_y = -1;
        found_1 = true;
        found_2 = true;
    }
    if (gData.poData.playerPosX == gData.poData.tableHor[0] - 1) {
        o_x = 0;
        found_1 = true;
        found_2 = true;
    }
    if (!found_1) {
        for (int i = 0; i <= gData.drData.width; i++) {
            if (gData.poData.tableHor[i] == gData.poData.playerPosX) {
                o_x = i;
                found_2 = true;
            }
        }
    }
    if (!found_2) o_x = searchNearestPos(gData.poData.tableHor, gData.poData.playerPosX, gData.drData.width);
    if (o_x != -1) {
        for (int i = 0; i < gData.drData.height; i++) {
            if (gData.poData.tableVer[i] == gData.poData.playerPosY) {
                o_y = i;
                return;
            }
        }
    }
    o_y = -1;

}
bool SyntaxCheck(std::string table[100][100], int y, int x) {
    if (table[y][x] != "X" && table[y][x] != "O"){
        return true;
    }
    return false;
}

