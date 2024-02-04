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
#include "include/drawScreen.h"
#include "include/winLogic.h"
#include "include/mapping.h"
#include "include/touchLogic.h"
#include <conio.h>
#include <Windows.h>
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_ENTER 13
#define KEY_ESC 27
using namespace std;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
string MainMenu[9] = {"Tiep Tuc", "Choi Moi", "Cai Dat", "Tac Gia"};
int main() {
    int x = 20;
    SetWindowSize(80, 35);
    for (int i = 0; i<4; i++ ) {

        gotoXY(40 -( MainMenu[i].length()/ 2), x);
        x += 2;
        cout << MainMenu[i];
    }
    int ch;
    int count = 0;
    gotoXY(40 -( MainMenu[0].length()/ 2), 20);
    x = 20;
    while (true) {
       if (kbhit()) {
          ch = getch();
          if (ch == KEY_DOWN) {

              count++;
              if (count > 3) {
                  count = 0;
                  x = 20;
                  gotoXY(40 -( MainMenu[3].length()/ 2), 28);
                  SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                  cout << MainMenu[3];
              }
              x += 2;
              gotoXY(40 -( MainMenu[(count - 1)].length()/ 2), x-2);
              SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
              cout << MainMenu[count - 1];
              gotoXY(40 -( MainMenu[count].length()/ 2), x);
              SetConsoleTextAttribute(hConsole,   FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
              cout << MainMenu[count];
          }
          if (ch == KEY_UP) {
              count--;
              if (count < 0) {
                  count = 3;
                  x = 28;
                  gotoXY(40 -( MainMenu[0].length()/ 2), 20);
                  SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                  cout << MainMenu[0];
              }
              x -= 2;
              gotoXY(40 -( MainMenu[count+ 1].length()/ 2), x+2);
              SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
              cout << MainMenu[count + 1];
              gotoXY(40 -( MainMenu[count].length()/ 2), x);
              SetConsoleTextAttribute(hConsole,   FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
              cout << MainMenu[count];
          }
       }
    }
}