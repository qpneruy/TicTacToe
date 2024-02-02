//====================================================================================
//  Discord: https://discordapp.com/users/610841389164396565 (qpneruy / </Джихё>)   ||
//  This Verison of Game was make by VO HUYNH HUU TINH (qpneruy)                    ||
//  Github: https://github.com/qpneruy                                              ||
//  Repo: https://github.com/qpneruy/TicTacToe.git                                  ||
//      ████████╗██╗░█████╗░████████╗░█████╗░░█████╗░████████╗░█████╗░███████╗      ||
//      ╚══██╔══╝██║██╔══██╗╚══██╔══╝██╔══██╗██╔══██╗╚══██╔══╝██╔══██╗██╔════╝      ||
//      ░░░██║░░░██║██║░░╚═╝░░░██║░░░███████║██║░░╚═╝░░░██║░░░██║░░██║█████╗░░      ||
//      ░░░██║░░░██║██║░░██╗░░░██║░░░██╔══██║██║░░██╗░░░██║░░░██║░░██║██╔══╝░░      ||
//      ░░░██║░░░██║╚█████╔╝░░░██║░░░██║░░██║╚█████╔╝░░░██║░░░╚█████╔╝███████╗      ||
//      ░░░╚═╝░░░╚═╝░╚════╝░░░░╚═╝░░░╚═╝░░╚═╝░╚════╝░░░░╚═╝░░░░╚════╝░╚══════╝      ||
//====================================================================================
#include <iostream>
#include <windows.h>
//#include "include/drawScreen.h"

using namespace std;
struct Player {
    int PosX;
    int PosY;
    int score;
};
struct Data {
    Player XPLayer;
    Player OPLayer;
    int intWin;

};
void SetWindowSize(SHORT width, SHORT height) {
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    SMALL_RECT WindowSize;
    WindowSize.Top = 0;
    WindowSize.Left = 0;
    WindowSize.Right = width;
    WindowSize.Bottom = height;

    SetConsoleWindowInfo(hStdout, 1, &WindowSize);
}


bool HorVerCheck(Data Data, char table[9][9], int width, int height, char Player) {
    int HorCount = 0, ZHorCount = 0;
    int VerCount = 0, ZVerCount = 0;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++){
            if (table[i][j] == Player) HorCount++; else HorCount = 0;
            if (table[j][i] == Player) ZHorCount++; else ZHorCount = 0;
        }
        if (HorCount == Data.intWin || VerCount == Data.intWin) return true;
    }
    return false;
}
void gotoXY(int x, int y) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD CursorPosition;
    CursorPosition.X = x;
    CursorPosition.Y = y;
    SetConsoleCursorPosition(hConsole, CursorPosition);
}
void clearScreen() {
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord = {
            0,
            0
    };
    DWORD count;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hStdOut, & csbi);
    FillConsoleOutputCharacter(hStdOut, ' ', csbi.dwSize.X * csbi.dwSize.Y, coord, & count);
    SetConsoleCursorPosition(hStdOut, coord);
}
void inBangDiem(Data data, int x){
    string line1 = "      |";
    string line2 = "      |";
    if (data.XPLayer.score < 10) line1 = " " + line1;
    if (data.OPLayer.score < 10) line2 = " " + line2;
    gotoXY(x, 11);
    cout << "+--------------+";
    gotoXY(x, 12);
    cout << "|     DIEM     |";
    gotoXY(x, 13);
    cout << "+----+---------+";
    gotoXY(x, 14);
    cout << "| X: | " << data.XPLayer.score << line1;
    gotoXY(x, 15);
    cout << "+----+---------+";
    gotoXY(x, 16);
    cout << "| O: | " <<  data.OPLayer.score << line2;
    gotoXY(x, 17);
    cout << "+----+---------+";
}
void inBanCo(char tableData[9][9], int width, int height, int x, int y) {
    std::cout << "\n";
    for (int i = 0; i <= height; i++) {
        gotoXY(x, y += 2);
        std::cout <<"  ";
        for (int o = 0; o <= width; o++) {
            if (o == 0) {  std::cout << "+"; } // "+" + (2)
            else {
                std::cout << "---+"; // (2): ----+----+----+...
            }
        }
        gotoXY(x, y+1);
        if (i != height) {
            cout << "  ";
            for (int j = 0; j < width; j++) {
                if (tableData[i][j] == 'X' || tableData[i][j] == 'O'){  std::cout << "| " << tableData[i][j] << " ";} else {
                    std::cout << "|   ";
                } // (1): | .. | .. | .. | ...
            }
            std::cout << "|"; // (1) + "|"; -> | .. | .. | .. |
        }
    }
}
int main() {
    char a[9][9] = {};

    Data Data;
    int x, y, z;
    SetWindowSize(80, 35);
//    while (cin >> x >> y) {
//        clearScreen();
//        inBanCo(a, x, y, 40-(x * 4 / 2)-5);
//        inBangDiem(Data, 40+(x * 4 / 2)+6);
//        gotoXY(0, 0);
//    }
    Data.OPLayer.score = 0;
//    cout << "              _____ ___ ____ _____  _    ____ _____ ___  _____ \n"
//            "             |_   _|_ _/ ___|_   _|/ \\  / ___|_   _/ _ \\| ____|\n"
//            "               | |  | | |     | | / _ \\| |     | || | | |  _|  \n"
//            "               | |  | | |___  | |/ ___ \\ |___  | || |_| | |___ \n"
//            "               |_| |___\\____| |_/_/   \\_\\____| |_| \\___/|_____| \n";
//    cout << "\n";
//
//    cout << "-------------===================================================-----------------";
//    gotoXY(0, 10);
//    inBanCo(a, 9, 9, 40-(9 * 4 / 2)-5);
//    inBangDiem(Data, 40+(9 * 4 / 2)+2);
cout << "               _____ ___ ____ _____  _    ____ _____ ___  _____\n"
        "              |_   _|_ _/ ___|_   _|/ \\  / ___|_   _/ _ \\| ____|\n"
        "                | |  | | |     | | / _ \\| |     | || | | |  _|\n"
        "                | |  | | |___  | |/ ___ \\ |___  | || |_| | |___\n"
        "                |_| |___\\____| |_/_/   \\_\\____| |_| \\___/|_____|\n"
        " _______________________________________________________________________________\n"
        "--------------====================================================-----------------\n"
        "  8              8                                          8              8 \n"
        "  8              8                                          8              8 \n"
        "  8              8                                          8              8 \n"
        "  8 ____________ 8                                          8 ____________ 8 \n"
        " |+--------------+|                                         +--------------+ |\n"
        " || O: mm:ss     ||                                         |     DIEM     | |\n"
        " || X: mm:ss     ||                                         +----+---------+ |\n"
        " |+--------------+|                                         | X: | 0       | |\n"
        " \\________________/                                         +----+---------+ |\n"
        "                                                            _________________/  ";
        inBanCo(a, 9, 9, 40-(9 * 4 / 2)-3,  8);
gotoXY(0, 35);
cout << "___-Author:_qpneruy-_____________---2024---____________________-Ver 1.0.0-___________";
    std::cin.get();
    return 0;
}