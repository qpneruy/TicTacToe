//
// Created by huuti on 001, 01/03/2024.
//

#include <string>
#include "include/drawScreen/inCaiDat.h"

std::string settingSign[15] {
        "",
        "╿               ╿",
        "├───────────────┤",
        "|    CAI DAT    |",
        "└───────────────┘",
};
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
    gotoXY(drData.x - 8, drData.y + 3);
    std::cout << "Nhac: ";
    gotoXY(drData.x - 9, drData.y + 4);
    std::cout << "⏎ Bat Hoac Tat";
}