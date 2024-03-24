//
// Created by huuti on 010, 10/02/2024.
//
#include <conio.h>
#include <windows.h>
#include "include/dataInput.h"

void getNumber(int &x) {
    x = getASCIINumber() - 48;
}
void UserInput(drawData &drData) {
    int width, height, ch;
    bool ThisIsRealEndTrustMe = false;
    clearScreen();
    gotoXY(0, drData.y);
    inBackGround(drData);
    inLogo();
    inKhung(78, 34);
    gotoXY(drData.x - 13, drData.y - 1);
    std::cout << "╿                        ╿";
    gotoXY(drData.x - 13, drData.y);
    std::cout << "NHAP KICH THUOC CUA BAN CO";
    gotoXY(drData.x - 11, drData.y + 1);
    std::cout << "   └---[?] x [?]---┘    ";
    while(!ThisIsRealEndTrustMe) {
        bool End = false;
        while (!End) {
            bool isRwidth = false;
            bool success = true;
            while (success) {
                if (!isRwidth) {
                    gotoXY(drData.x - 3, drData.y + 1);
                    getNumber(width);
                }
                if (width > 1 && width <= 9) {
                    if (!isRwidth) std::cout << width;
                    isRwidth = true;
                    gotoXY(drData.x + 3, drData.y + 1);
                    getNumber(height);
                    if (height > 1 && height <= 9) {
                        std::cout << height;
                        success = false;
                    }
               }
            }
            while (true) {
                ch = getch();
                if (ch == 8) {
                    gotoXY(drData.x - 11, drData.y + 1);
                    std::cout << "   └---[?] x [?]---┘      ";
                    drData.height = 0;
                    drData.width = 0;
                    gotoXY(drData.x - 4, drData.y + 1);
                    break;
                }
                if (ch == 13) {
                    drData.width = static_cast<char>(height);
                    drData.height = static_cast<char>(width);
                    End = true;
                    break;
                }
            }
        }
        End = false;
        while (!End) {
            bool success = true;
            gotoXY(drData.x - 12, drData.y + 1);
            std::cout << "╿";
            gotoXY(drData.x + 9, drData.y + 1);
            std::cout << "  ╿";
            gotoXY(drData.x - 12, drData.y + 2);
            std::cout << "╽                      ╽";
            gotoXY(drData.x - 12, drData.y + 3);
            std::cout << "NHAP SO DAU CAN DE THANG";
            gotoXY(drData.x - 12, drData.y + 4);
            std::cout << "       └---[?]---┘  ";
            while (success) {
                gotoXY(drData.x, drData.y + 4);
                int intWin;
                getNumber(intWin);
                if (intWin <= std::max(height, width) && intWin > 1) {
                    success = false;
                    std::cout << intWin;
                    drData.intWin = static_cast<char>(intWin);
                } else {
                    gotoXY(drData.x - 12, drData.y + 4);
                    std::cout << "       └---[?]---┘  ";
                    gotoXY(drData.x - 12, drData.y + 5);
                }
            }
            while (true) {
                ch = getch();
                if (ch == 8) {
                    gotoXY(drData.x - 12, drData.y + 4);
                    std::cout << "       └---[?]---┘  ";
                    drData.intWin = 0;
                    break;
                }
                if (ch == 13) {
                    End = true;
                    break;
                }
            }
        }
        gotoXY(drData.x - 12, drData.y+4);
        std::cout << "╿";
        gotoXY(drData.x+8 , drData.y+4);
        std::cout <<  "   ╿";
        gotoXY(drData.x - 12, drData.y+5);
        std::cout << "╽                      ╽";
        gotoXY(drData.x - 12, drData.y+6);
        std::cout << "CHON NGUOI CHOI DI TRUOC";
        gotoXY(drData.x - 12, drData.y+7);
        std::cout << "   └---[X]-----[O]---┘  ";
        gotoXY(drData.x - 4, drData.y+8);
        std::cout << "↑        ";
        End = false;
        int count = 0;
        while (!End) {
            if (kbhit()) {
                ch = getch();
                if (ch == 77) {
                    count = 1;
                    gotoXY(drData.x - 8, drData.y + 8);
                    std::cout << "            ↑";
                } else if (ch == 75) {
                    gotoXY(drData.x- 4, drData.y + 8);
                    std::cout << "↑        ";
                    count = -1;
                }
                if (ch == 13) {
                    (count == 1) ? drData.opr = true : drData.xpr = true;
                    End = true;
                    ThisIsRealEndTrustMe = true;
                    gotoXY(drData.x - 13, drData.y);
                    std::cout << "                               ";
                    gotoXY(drData.x - 13, drData.y - 1);
                    std::cout << "                               ";
                }
            }
        }
    }
    clearScreen();
}

std::string userNameInput() {
    int count = 0;
    int ch;
    std::string name;
    gotoXY(37, 15);
    std::cout << "_ _ _ _ _ _";
    gotoXY(37, 15);
    while (count < 6) {
        if (kbhit()) {
            ch = getch();
            if (ch == 13) {
                if (!name.empty()) {
                    return name;
                } else {
                    gotoXY(27, 16);
                    std::cout << "Vui Long Nhap Ten!";
                    Sleep(200);
                    gotoXY(27, 16);
                    std::cout << "                   ";
                }
            }
            count++;
            std::cout << char(ch);
            name += char(ch);
            gotoXY(count * 2 + 37, 15);
        }
    }
    return name;
}