//
// Created by huuti on 001, 01/02/2024.
//
#include <iostream>
#include <windows.h>
#include <iomanip>
#include <conio.h>
#include "include/drawScreen.h"
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_ENTER 13
#define KEY_ESC 27
void gotoXY(int x, int y) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD CursorPosition;
    CursorPosition.X = x;
    CursorPosition.Y = y;
    SetConsoleCursorPosition(hConsole, CursorPosition);
}

void inBanCo(char tableData[9][9], drawData data) {
    for (int i = 0; i < 3; i++) {
        gotoXY(40 - (data.width * 4 / 2) - 1, data.y - i + 1);
        std::cout << "┋";
    }
    for (int i = 0; i < 3; i++) {
        gotoXY(40 + (data.width * 4 / 2) - 1, data.y - i + 1);
        std::cout << "┋";
    }
    for (int i = 40 - (data.width * 4 / 2) + 1; i < 40 + (data.width * 4 / 2) - 2; i++) {
        gotoXY(i, data.y+1);
        std::cout << "_";
    }
    std::cout << "\n";
    for (int i = 0; i <= data.height; i++) {
        gotoXY(data.x, data.y += 2);
        std::cout << "  ";
        if (i == 0) {
            for (int o = 0; o < data.width; o++) {
                if (o == 0) std::cout << "├"; else std::cout << "───┬";
            }
            std::cout << "───┤▒";
        } else if (i == data.height) {
            for (int o = 0; o < data.width; o++) {
                if (o == 0) std::cout << "└"; else std::cout << "───┴";
            }
            std::cout << "───┘▒";
        } else{
            for (int o = 0; o <= data.width; o++) {
                if (o == 0) { std::cout << "├"; } // "+" + (2)
                else {
                    if (o == data.width) std::cout << "───┤▒"; else std::cout << "───┼"; // (2): ----+----+----+...
                }
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
            std::cout << "|▒"; // (1) + "|"; -> | .. | .. | .. |
        }
    }
}

std::string BangDiemSt[] = {
        "╿              ╿ ",
        "┋              ┋ ",
        "┋              ┋ ",
        "╽ ____________ ╽ ",
        "├──────────────┤║",
        "|     DIEM     |║",
        "├────┬─────────┤║",
        "| X: |         |║",
        "├────┼─────────┤║",
        "| O: |         |║",
        "├────┴─────────┤║",
        "┋              ┋║",
        "├──────────────┤║",
        "|   LUOT:      |║",
        "└──────────────┘║",
        "════════════════╝"
};

void inBangDiem(drawData data, short Oscore, short Xscore) {
    for (int i = 0; i <= 15; i++) {
        gotoXY(60, data.y + i - 1);
        std::cout << BangDiemSt[i];
        if (i == 7) {
            gotoXY(60 + 7, data.y + 6);
            std::cout << Xscore;
        }
        if (i == 9) {
            gotoXY(60 + 7,  data.y + 8);
            std::cout << Oscore;
        }
    }

}

std::string ThoiGianSt[] = {
        " ╿                ╿ ",
        " ┋                ┋ ",
        " ┋                ┋ ",
        " ╽ ______________ ╽ ",
        " |+--------------+| ",
        " || O:           || ",
        " || X:           || ",
        " |+--------------+| ",
        " \\________________/"
};

std::string formatTime(int seconds) {
    int minutes = seconds / 60;
    seconds %= 60;
    std::stringstream ss;
    ss << std::setw(2) << std::setfill('0') << minutes << ":" << std::setw(2) << std::setfill('0') << seconds;
    return ss.str();
}

void inBangThoiGian(drawData drData, int XTime, int OTime) {

    for (int i = 0; i <= 8; i++) {
        gotoXY(0, drData.y + i - 1);
        std::cout << ThoiGianSt[i];
    }
    gotoXY(6, drData.y);
    std::cout << formatTime(XTime);
    gotoXY(6, drData.y  );
    std::cout << formatTime(OTime);
}

void inLogo() {
    std::cout << "╓──────────────────────────────────────────────────────────────────────────────╖\n"
                 "║                                                                              ║\n"
                 "║ ░░░████████╗██╗░█████╗░████████╗░█████╗░░█████╗░████████╗░█████╗░███████╗░░░ ║\n"
                 "║ ░░░╚══██╔══╝██║██╔══██╗╚══██╔══╝██╔══██╗██╔══██╗╚══██╔══╝██╔══██╗██╔════╝░░░ ║\n"
                 "║ ░░░░░░██║░░░██║██║░░╚═╝░░░██║░░░███████║██║░░╚═╝░░░██║░░░██║░░██║█████╗░░░░░ ║\n"
                 "║ ░░░░░░██║░░░██║██║░░██╗░░░██║░░░██╔══██║██║░░██╗░░░██║░░░██║░░██║██╔══╝░░░░░ ║\n"
                 "║ ░░░░░░██║░░░██║╚█████╔╝░░░██║░░░██║░░██║╚█████╔╝░░░██║░░░╚█████╔╝███████╗░░░ ║\n"
                 "║ ░░░░░░╚═╝░░░╚═╝░╚════╝░░░░╚═╝░░░╚═╝░░╚═╝░╚════╝░░░░╚═╝░░░░╚════╝░╚══════╝░░░ ║\n"
                 "║ ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░ ║\n"
                 "║______________________________________________________________________________║\n"
                 "║══════════════════════════════════════════════════════════════════════════════║";
}

void printInfo() {
    gotoXY(0, 35);
    std::cout << "";
}
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
std::string MainMenu[9] = {"Tiep Tuc", "Choi Moi", "Cai Dat", "Tac Gia"};
short inMeluChinh() {
    int y = 15;
    for (int i = 0; i<4; i++ ) {

        gotoXY(40 -( MainMenu[i].length()/ 2), y);
        y += 2;
        std::cout << MainMenu[i];
    }
    int ch;
    short count = 0;
    y = 15;
    gotoXY(40 -( MainMenu[count].length()/ 2), y);
    SetConsoleTextAttribute(hConsole,
                            FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY |
                            BACKGROUND_INTENSITY);
    std::cout << "> " << MainMenu[0];
    while (true) {
        if (kbhit()) {
            ch = getch();
            if (ch == KEY_DOWN) {
                y += 2;
                count++;
                if (count > 3) {
                    count = 0;
                    y = 15;
                    gotoXY(40 -( MainMenu[3].length()/ 2), y+6);
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                    std::cout << " " << MainMenu[3] << " ";
                }

                gotoXY(40 -( MainMenu[(count - 1)].length()/ 2), y-2);
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                std::cout << " " << MainMenu[count - 1] << " ";
                gotoXY(40 -( MainMenu[count].length()/ 2), y);
                SetConsoleTextAttribute(hConsole,
                                        FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY |
                                        BACKGROUND_INTENSITY);
                std::cout << "> " << MainMenu[count];
            }
            if (ch == KEY_UP) {
                count--;
                if (count < 0) {
                    count = 3;
                    y = 23;
                    gotoXY(40 -( MainMenu[0].length()/ 2), 15);
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                    std::cout << " " << MainMenu[0] << " ";
                }
                y -= 2;
                gotoXY(40 - (MainMenu[count + 1].length() / 2), y + 2);
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                std::cout << " " << MainMenu[count + 1] << " ";
                gotoXY(40 -( MainMenu[count].length()/ 2), y);
                SetConsoleTextAttribute(hConsole,
                                        FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY |
                                        BACKGROUND_INTENSITY);
                std::cout << "> " << MainMenu[count];
            }
            if (ch == KEY_ENTER) return count;
        }
    }
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

