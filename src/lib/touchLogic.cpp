#include "include/mapping.h"

//
// Created by huuti on 003, 03/02/2024.
//
#include "include/touchLogic.h"

#include <Windows.h>
int x_, y_;
bool Pressed = false;
void getPosMouse(posData &data) {
    Pressed = false;
    HANDLE hStdin;
    DWORD fdwMode, eventRead;
    INPUT_RECORD Inrec;
    hStdin = GetStdHandle(STD_INPUT_HANDLE);
    fdwMode = ENABLE_EXTENDED_FLAGS;
    SetConsoleMode(hStdin, fdwMode);
    fdwMode = ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT;
    SetConsoleMode(hStdin, fdwMode);
    while (!Pressed) {
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
                    Pressed = true;
                }
                break;
            }
        }
    }
}
int searchNearestPos(const int mapTable[9], int x, int n){
   for (int i = 0; i<n-1 ; i++ ){
       if (x > mapTable[i] && x < mapTable[i+1]) {
           if (x - mapTable[i] == 1) return i;
           if (mapTable[i+1] - x == 1) return i+1;
           return -1;
       }
   }
}
void dacPos(drawData drData, posData poData, int x, int y, int &o_x, int &o_y) {
    bool found = false;
    for (int i = 0; i<drData.width; i++) {
        if (poData.tableHor[i] == x) {
            o_x = i;
            found = true;
        }
    }
    if (!found) o_x = searchNearestPos(poData.tableHor, x, drData.width);
    if (o_x != -1) {
        for (int i = 0; i < drData.height; i++) {
            if (poData.tableVer[i] == y) {
                o_y = i;
                return;
            }
        }
    }
    o_y = -1;

}


