//
// Created by huuti on 001, 01/03/2024.
//

#include <string>
#include <conio.h>
#include "include/drawScreen/inCaiDat.h"
#include "windows.h"
std::string settingSign[15] {
        "",
        "╿               ╿",
        "├───────────────┤",
        "|    CAI DAT    |",
        "└───────────────┘",
};
std::string setting[2] = {
        "| Nhac: √",
         "| TinhDepTrai: √"
};
void toggleSetting(int selected) {
    if (setting[selected].find("√") != std::string::npos) {
        setting[selected].replace(setting[selected].find("√"), 8, "✗");
//        settingState[selected] = false;
    } else {
        setting[selected].replace(setting[selected].find("✗"), 8, "√");
//        settingState[selected] = true;
    }
}
HANDLE _hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
void inCaiDat(drawData drData) {
    for (int i = 0; i <= 15; i++) {
        gotoXY(drData.x - 8, drData.y + i - 1);
        std::cout << "             ";
    }
    int yPos = drData.y-1;
    gotoXY(drData.x - 10, yPos);
    for (const auto & i : settingSign) {
        std::cout << i;
        gotoXY(drData.x - 10, yPos);
        yPos +=1;
    }
    yPos = drData.y+5;
    for (const auto & i : setting) {
        gotoXY(drData.x - 9, yPos);
        std::cout << i;
        yPos += 2;
    }
    bool End = false;
    int selected = 0;
    yPos = drData.y + 5;
    gotoXY(drData.x - 9, drData.y + 5);
    std::cout << setting[0] << " <";
    while (!End) {
        if (kbhit()){
            int ch = getch();
            if (ch == 72) {
                gotoXY(drData.x + 8, drData.y + 7);
                std::cout << " ";
                gotoXY(drData.x + 1, drData.y + 5);
                std::cout << "<";
                selected = 0;
            }
            if (ch == 80) {
                gotoXY(drData.x + 1, drData.y + 5);
                std::cout << " ";
                gotoXY(drData.x + 8, drData.y + 7);
                std::cout << "<";
                selected = 1;
            }
            if (ch == 13) {
                if (selected == 0) gotoXY(drData.x - 9, drData.y + 5); else gotoXY(drData.x - 9, drData.y + 7);
                toggleSetting(selected);
                std::cout << setting[selected];
            }
            if (ch == 27) {
                End = true;
            }
        }
    }
}
