//
// Created by huuti on 001, 01/02/2024.
//
#include <iostream>
#include <windows.h>
#include <iomanip>
#include "include/drawScreen.h"

void gotoXY(int x, int y) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD CursorPosition;
    CursorPosition.X = x;
    CursorPosition.Y = y;
    SetConsoleCursorPosition(hConsole, CursorPosition);
}

void inBanCo(char tableData[9][9], drawData data) {
    for (int i = 0; i < 4; i++) {
        gotoXY(40 - (data.width * 4 / 2) - 1, 10 - i);
        std::cout << "8";
    }
    for (int i = 0; i < 4; i++) {
        gotoXY(40 + (data.width * 4 / 2) - 1, 10 - i);
        std::cout << "8";
    }
    for (int i = 40 - (data.width * 4 / 2) + 1; i < 40 + (data.width * 4 / 2) - 2; i++) {
        gotoXY(i, 10);
        std::cout << "_";
    }
    std::cout << "\n";
    for (int i = 0; i <= data.height; i++) {
        gotoXY(data.x, data.y += 2);
        std::cout << "  ";
        for (int o = 0; o <= data.width; o++) {
            if (o == 0) { std::cout << "+"; } // "+" + (2)
            else {
                std::cout << "---+"; // (2): ----+----+----+...
            }
        }
        gotoXY(data.x, data.y + 1);
        if (i != data.height) {
            std::cout << "  ";
            for (int j = 0; j < data.width; j++) {
                if (tableData[i][j] == 'X' || tableData[i][j] == 'O') { std::cout << "| " << tableData[i][j] << " "; }
                else {
                    std::cout << "|   ";
                } // (1): | .. | .. | .. | ...
            }
            std::cout << "|"; // (1) + "|"; -> | .. | .. | .. |
        }
    }
}

std::string BangDiemSt[] = {
        "8              8 ",
        "8              8 ",
        "8              8 ",
        "8 ____________ 8 ",
        "+--------------+ |",
        "|     DIEM     | |",
        "+----+---------+ |",
        "| X: |         | |",
        "+----+---------+ |",
        "| O: |         | |",
        "+----+---------+ |",
        "8              8 |",
        "+--------------+ |",
        "|   LUOT:      | |",
        "+--------------+ |",
        "_________________/"
};

void inBangDiem(short Oscore, short Xscore) {
    for (int i = 0; i <= 15; i++) {
        gotoXY(60, 7 + i);
        std::cout << BangDiemSt[i];
        if (i == 7) {
            gotoXY(60 + 7, 14);
            std::cout << Xscore;
        }
        if (i == 9) {
            gotoXY(60 + 7, 16);
            std::cout << Oscore;
        }
    }

}

std::string ThoiGianSt[] = {
        " 8              8  ",
        " 8              8  ",
        " 8              8  ",
        " 8 ____________ 8  ",
        "|+--------------+| ",
        "|| O:           || ",
        "|| X:           || ",
        "|+--------------+| ",
        "\\________________/"
};

std::string formatTime(int seconds) {
    int minutes = seconds / 60;
    seconds %= 60;
    std::stringstream ss;
    ss << std::setw(2) << std::setfill('0') << minutes << ":" << std::setw(2) << std::setfill('0') << seconds;
    return ss.str();
}

void inBangThoiGian(int XTime, int OTime) {

    for (int i = 0; i <= 8; i++) {
        gotoXY(0, 7 + i);
        std::cout << ThoiGianSt[i];
    }
    gotoXY(6, 12);
    std::cout << formatTime(XTime);
    gotoXY(6, 13);
    std::cout << formatTime(OTime);
}

void inLogo() {
    std::cout << "               _____ ___ ____ _____  _    ____ _____ ___  _____\n"
                 "              |_   _|_ _/ ___|_   _|/ \\  / ___|_   _/ _ \\| ____|\n"
                 "                | |  | | |     | | / _ \\| |     | || | | |  _|\n"
                 "                | |  | | |___  | |/ ___ \\ |___  | || |_| | |___\n"
                 "                |_| |___\\____| |_/_/   \\_\\____| |_| \\___/|_____|\n"
                 " _______________________________________________________________________________\n"
                 "--------------====================================================-----------------\n";
}

void printInfo() {
    gotoXY(0, 35);
    std::cout << "___-Author: qpneruy-_____________---2024---____________________-Ver 1.0.0-___________";
}

void clearScreen() {
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord = {0, 0};
    DWORD count;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hStdOut, &csbi);
    FillConsoleOutputCharacter(hStdOut, ' ', csbi.dwSize.X * csbi.dwSize.Y, coord, &count);
    SetConsoleCursorPosition(hStdOut, coord);
}

void SetWindowSize(SHORT width, SHORT height) {
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    SMALL_RECT WindowSize;
    WindowSize.Top = 0;
    WindowSize.Left = 0;
    WindowSize.Right = width;
    WindowSize.Bottom = height;

    SetConsoleWindowInfo(hStdout, 1, &WindowSize);
}

