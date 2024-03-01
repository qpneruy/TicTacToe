//
// Created by huuti on 029, 29/02/2024.
//

#include "include/drawScreen/inBangXepHang.h"
std::string BucXepHang[6] = {    "",
                                 "       ┌───────┐",
                                 "┌──────|   1   |       ",
                                 "|  2   |       |──────┐",
                                 "|      |       |   3  |",
                                 "───────────────────────"};
std::string BangXepHang[15] {
        "",
        "____________________",
        " Top    Ten      Diem",
        "  1.  ____        _",
        "  2.  ____        _",
        "  3.  ____        _",
        "  4.  ____        _",
        "  5.  ____        _",
        "  6.  ____        _",
        "  7.  ____        _",
        "  8.  ____        _",
        "  9.  ____        _",
        "  10. ____        _  ",
        "                   "};
std::string leaderboardSign[15] {
        "",
        "╿               ╿",
        "├───────────────┤",
        "| Bang Xep Hang |",
        "└───────────────┘",
};
void inBangXepHang(drawData drData, leaderboard pld) {
    int yPos = drData.y-1;
    gotoXY(drData.x - 10, yPos);
    for (const auto & i : leaderboardSign) {
        std::cout << i;
        gotoXY(drData.x - 10, yPos);
        yPos +=1;
    }
    yPos = drData.y + 20;
    gotoXY(drData.x - 10, yPos);
    for (const auto & i : BucXepHang) {
        std::cout << i;
        gotoXY(drData.x - 12, yPos);
        yPos += 1;
    }
    yPos = drData.y + 5;
    for (const auto & i : BangXepHang) {
        std::cout<< i;
        gotoXY(drData.x-12, yPos);
        yPos +=1;
    }
    int count = 0;
    yPos = drData.y + 7;
    for (auto x : pld.leaderboardData) {
        ++count;
        gotoXY(drData.x - 7, yPos);
        std::cout << x.first;
        gotoXY(drData.x + 6, yPos);
        std::cout << x.second;
        yPos += 1;
        switch (count) {
            case 1:
                gotoXY(37, 30);
                std::cout << x.first;
                break;
            case 2:
                gotoXY(29, 31);
                std::cout << x.first;
                break;
            case 3:
                gotoXY(45, 32);
                std::cout << x.first;
                break;
        }
    }
    gotoXY(0, 0);
    std::cout << "";
}