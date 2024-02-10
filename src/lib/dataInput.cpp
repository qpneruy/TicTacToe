//
// Created by huuti on 010, 10/02/2024.
//

#include <conio.h>
#include <Windows.h>
#include "include/dataInput.h"

void getNumber(int &x) {
    x = getASCIINumber() - 48;
    std::cout << x;
}
void UserInput(drawData drData, posData poData) {
    int width, height, ch, intWin;
    clearScreen();
    inLogo();
    inKhung(78, 34);
    gotoXY(drData.x - 13, drData.y - 1);
    std::cout << "╿                        ╿";
    gotoXY(drData.x - 13, drData.y);
    std::cout << "NHAP KICH THUOC CUA BAN CO";
    gotoXY(drData.x - 11, drData.y + 1);
    std::cout << "   └---[?] x [?]---┘    ";
    while(true) {
        bool End = false;
        while (!End) {
            bool success = true;
            while (success) {
                gotoXY(drData.x - 3, drData.y + 1);
                getNumber(width);
                gotoXY(drData.x + 3, drData.y + 1);
                getNumber(height);
                if (width <= 9 && height <= 9 && width > 1 && height > 1) {
                    success = false;
                } else {
                    gotoXY(drData.x - 16, drData.y + 2);
                    std::cout << "KICH THUOC KHONG HOP LE!, Nhap Lai.";
                    Sleep(1500);
                    gotoXY(drData.x - 16, drData.y + 2);
                    std::cout << "                                    ";
                    gotoXY(drData.x - 11, drData.y + 1);
                    std::cout << "   └---[?] x [?]---┘      ";
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
                    drData.height = height;
                    drData.width = width;
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
                getNumber(intWin);
                if (intWin > std::max(drData.width, drData.height)) {
                    gotoXY(drData.x - 12, drData.y + 4);
                    std::cout << "       └---[?]---┘  ";
                    gotoXY(drData.x - 12, drData.y + 5);
                    std::cout << "SO DAU KHONG HOP LE!, Nhap Lai.";
                    Sleep(1500);
                    gotoXY(drData.x - 12, drData.y + 5);
                    std::cout << "                                ";
                } else success = false;
            }
            while (true) {
                ch = getch();
                if (ch == 8) {
                    gotoXY(drData.x - 12, drData.y + 4);
                    std::cout << "       └---[?]---┘  ";
                    intWin = 0;
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
        End = false;
        while (!End) {\
            if (kbhit()) {
                ch = getch();
           std::cout << ch;
                if (ch == 22477) {
                    gotoXY(drData.x, drData.y + 7);
                    std::cout << "               ↑";
                } else if (ch == 22475) {
                    gotoXY(drData.x, drData.y + 7);
                    std::cout << "↑              ";
                }
            }
        }
    }
}