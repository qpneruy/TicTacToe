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

void gotoXY(int _x, int _y) {
    auto x = (short) _x;
    auto y = (short) _y;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD CursorPosition;
    CursorPosition.X = x;
    CursorPosition.Y = y;
    SetConsoleCursorPosition(hConsole, CursorPosition);
}

void inBanCo(char tableData[9][9], drawData data) {

    gotoXY(data.x - (data.width * 4 / 2), data.y - 1);
    std::cout << "╿\n";
    gotoXY(data.x - (data.width * 4 / 2), data.y);
    std::cout << "┋\n";
    gotoXY(data.x - (data.width * 4 / 2), data.y + 1);
    std::cout << "╽\n";


    gotoXY(data.x + (data.width * 4 / 2), data.y - 1);
    std::cout << "╿\n";
    gotoXY(data.x + (data.width * 4 / 2), data.y);
    std::cout << "┋\n";
    gotoXY(data.x + (data.width * 4 / 2), data.y + 1);
    std::cout << "╽\n";

    for (int i = 40 - (data.width * 4 / 2) + 2; i < 40 + (data.width * 4 / 2) - 1; i++) {
        gotoXY(i, data.y + 1);
        std::cout << "_";
    }
    std::cout << "\n";
    for (int i = 0; i <= data.height; i++) {
        gotoXY(data.x - (data.width * 4 / 2) - 2, data.y += 2);
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
        } else {
            for (int o = 0; o <= data.width; o++) {
                if (o == 0) { std::cout << "├"; } // "+" + (2)
                else {
                    if (o == data.width) std::cout << "───┤▒"; else std::cout << "───┼"; // (2): ----+----+----+...
                }
            }
        }
        gotoXY(data.x - (data.width * 4 / 2) - 2, data.y + 1);
        if (i != data.height) {
            std::cout << "  ";
            for (int j = 0; j < data.width; j++) {
                if (tableData[i][j] != ' ') { std::cout << "| " << tableData[i][j] << " "; }
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
        "╽____┌DIEM┐____╽ ",
        "├-───┬────────-┤║",
        "| X: |         |║",
        "├-───┼────────-┤║",
        "| O: |         |║",
        "├-───┴────────-┤║",
        "┋              ┋║",
        "├-────────────-┤║",
        "|   LUOT:      |║",
        "└-─────────────┘║",
        "════════════════╝"
};

void inBangDiem(drawData data, short Oscore, short Xscore) {
    for (int i = 0; i <= 13; i++) {
        gotoXY(data.x + 21, data.y + i - 1);
        std::cout << BangDiemSt[i];
        if (i == 7) {
            gotoXY(data.x + 21 + 7, data.y + 4);
            std::cout << Xscore;
        }
        if (i == 9) {
            gotoXY(data.x + 21 + 7, data.y + 6);
            std::cout << Oscore;
        }
    }

}

std::string ThoiGianSt[] = {
        "  ╿              ╿ ",
        "  ┋              ┋ ",
        "  ┋              ┋ ",
        "  ╽_┌THOI GIAN┐__╽ ",
        " ║├-────────────-┤║ ",
        " ║| O:           |║ ",
        " ║├-────────────-┤║",
        " ║| X:           |║ ",
        " ║└──────────────┘║ ",
        " ╚════════════════╝"
};

std::string formatTime(int seconds) {
    int minutes = seconds / 60;
    seconds %= 60;
    std::stringstream ss;
    ss << std::setw(2) << std::setfill('0') << minutes << ":" << std::setw(2) << std::setfill('0') << seconds;
    return ss.str();
}

void inBangThoiGian(drawData drData, int XTime, int OTime) {

    for (int i = 0; i <= 9; i++) {
        gotoXY(1, drData.y + i - 1);
        std::cout << ThoiGianSt[i];
    }
    gotoXY(8, drData.y + 4);
    std::cout << formatTime(XTime);
    gotoXY(8, drData.y + 6);
    std::cout << formatTime(OTime);
}

void inLogo() {
    gotoXY(0, 0);
    std::cout << "                                                                                \n"
                 "  ░░░████████╗██╗░█████╗░████████╗░█████╗░░█████╗░████████╗░█████╗░███████╗░░░  \n"
                 "  ░░░╚══██╔══╝██║██╔══██╗╚══██╔══╝██╔══██╗██╔══██╗╚══██╔══╝██╔══██╗██╔════╝░░░  \n"
                 "  ░░░░░░██║░░░██║██║░░╚═╝░░░██║░░░███████║██║░░╚═╝░░░██║░░░██║░░██║█████╗░░░░░  \n"
                 "  ░░░░░░██║░░░██║██║░░██╗░░░██║░░░██╔══██║██║░░██╗░░░██║░░░██║░░██║██╔══╝░░░░░  \n"
                 "  ░░░░░░██║░░░██║╚█████╔╝░░░██║░░░██║░░██║╚█████╔╝░░░██║░░░╚█████╔╝███████╗░░░  \n"
                 "  ░░░░░░╚═╝░░░╚═╝░╚════╝░░░░╚═╝░░░╚═╝░░╚═╝░╚════╝░░░░╚═╝░░░░╚════╝░╚══════╝░░░  \n"
                 "  ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░  \n"
                 " ______________________________________________________________________________ \n"
                 " ══════════════════════════════════════════════════════════════════════════════ ";
}

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
std::string MainMenu[] = {"╿           ╿\n",
                          "┋           ┋\n",
                          "┋           ┋\n",
                          "┋           ┋\n",
                          "╽           ╽\n",
                          "╟-─────────-╢\n",
                          "║ Tiep Tuc  ║\n",
                          "║           ║\n",
                          "║ Choi Moi  ║\n",
                          "║           ║\n",
                          "║ Cai Dat   ║\n",
                          "║           ║\n",
                          "║ Giup Do   ║\n",
                          "║           ║\n",
                          "║ Tac Gia   ║\n",
                          "╚═══════════╝\n"};

void inMenuChinh(drawData Data) {
    gotoXY(0, Data.y);
    std::cout << "                                                                                \n"
                 "                                                                                \n"
                 "                                                                                \n"
                 "                                                                                \n"
                 "       .''.      .                                                              \n"
                 "      :_\\/_:   _\\(/_  .:.                                                     \n"
                 "  .''.: /\\ :/   ./)\\   ':'                                     .''.           \n"
                 "  :_\\/_:'.:::.  /  .*''*                              *''*    :_\\/_:     .    \n"
                 "  : /\\ : ::::: /   *_\\/_*/                           *_\\/_*   : /\\ :  .'.:.'. \n"
                 "  \\'..'  ':::'    \\* /\\ *                            * /\\ * :  '..'.  -=:o:=- \n"
                 "       *           \\*..*                               * '.\\'/.' _\\(/_'.':'.' \n"
                 "        *             *                                    -= o =-  /)\\    '   \n"
                 "        *             *                                       *            *    \n"
                 "       *             *                                        *            *    \n"
                 "       *        |   *                                          *           *    \n"
                 "  _  *          =   *                                          *         *     \n"
                 " | |..         ===  *                                       ' ._____     *     \n"
                 " |    |         |    *                                        |.   |' .---\"|   \n"
                 " |    | .       | .  * _                               .--'| '||   | _|    |   \n"
                 " |    |   .     |  .-'|                                |   |  |    ||      |   \n"
                 " |    .-----. . |  |' |  ||                      ' |   |   |  |    ||      |    \n"
                 " |  .'  | |  './\"\\ |  '-.\"\".        -2024-        .\". '|   |-.|    ||      | \n"
                 " |   |       | | | |    |  |                      | |  |   |  |    ||      |-- \n"
                 " |   |       |/   \\|    |  |                      | |  |   |  |    ||      |  . \n";
    for (int i = 0; i <= 15; i++) {
        gotoXY(Data.x - 8, Data.y + i - 1);
        std::cout << MainMenu[i];
    }
}

std::string MainMenuStr[] = {"Tiep Tuc", "Choi Moi", "Cai Dat", "Giup Do", "Tac Gia", ""};

int menuHandle(drawData Data) {
    int ch;
    int index = 0;
    int pointY = Data.y + 5;
    gotoXY(Data.x - 7, pointY);
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY |
                                      BACKGROUND_INTENSITY);
    std::cout << " > " << MainMenuStr[0];
    while (true) {
        if (kbhit()) {
            ch = getch();
            if (ch == KEY_UP) {
                pointY -= 2;
                --index;
                if (pointY <= Data.y + 3) {
                    gotoXY(Data.x - 7, pointY + 2);
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                    std::cout << " " << MainMenuStr[index + 1] << "  ";
                    index = 4;
                    pointY = Data.y + 13;
                }
                gotoXY(Data.x - 7, pointY + 2);
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                std::cout << " " << MainMenuStr[index + 1] << "  ";
                gotoXY(Data.x - 7, pointY);
                SetConsoleTextAttribute(hConsole,
                                        FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY |
                                        BACKGROUND_INTENSITY);
                std::cout << " > " << MainMenuStr[index];
            }
            if (ch == KEY_DOWN) {
                pointY += 2;
                ++index;
                if (pointY >= Data.y + 15) {
                    gotoXY(Data.x - 7, pointY - 2);
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                    std::cout << " " << MainMenuStr[index - 1] << "  ";
                    index = 0;
                    pointY = Data.y + 5;
                }
                gotoXY(Data.x - 7, pointY - 2);
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                std::cout << " " << MainMenuStr[index - 1] << "  ";
                gotoXY(Data.x - 7, pointY);
                SetConsoleTextAttribute(hConsole,
                                        FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY |
                                        BACKGROUND_INTENSITY);
                std::cout << " > " << MainMenuStr[index];
            }
            if (ch == KEY_ENTER) {
                gotoXY(Data.x - 7, Data.y + 5 + index * 2);
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                std::cout << "                        ";
                return index;
            }
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

void inKhung(int width, int height) {

    for (int i = 1; i <= width; i++) {
        gotoXY(i, 0);
        std::cout << "─";
        gotoXY(i, height + 1);
        std::cout << "═";
    }
    for (int i = 1; i <= height; i++) {
        gotoXY(0, i);
        std::cout << "║";
        gotoXY(79, i);
        std::cout << "║";
    }
    gotoXY(width + 1, 0);
    std::cout << "╖";
    gotoXY(width + 1, height + 1);
    std::cout << "╝";
    gotoXY(0, 0);
    std::cout << "╓";
    gotoXY(0, height + 1);
    std::cout << "╚";
}

int getASCIINumber() {
    while (true) {
        if (kbhit()) return getch();
    }
}

void ThongBao() {
    gotoXY(5, 21);
    std::cout << "Vi Tri Khong";
    gotoXY(7, 22);
    std::cout << "Hop Le!";
}