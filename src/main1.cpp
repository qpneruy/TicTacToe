#include <iostream>
#include <unistd.h>
#include <conio.h>
#include <math.h>
#include <windows.h>
#include <fstream>

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_ENTER 13
#define KEY_ESC 27
using namespace std;
const int baseX = 0;
const int baseY = 8;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
const  char ch[2] = {30,31};
/*{--------------------------------------------}*/
void gotoXY(int x, int y) {
    COORD CursorPosition;
    CursorPosition.X = x;
    CursorPosition.Y = y;
    SetConsoleCursorPosition(hConsole, CursorPosition);
}
/*{--------------------------------------------}
 int wherex() {
   CONSOLE_SCREEN_BUFFER_INFO csbi;
   COORD result;
   if (!GetConsoleScreenBufferInfo(
         GetStdHandle(STD_OUTPUT_HANDLE), &
         csbi
      ))
      // return -1;
      return result.X;
}
/*{---------------------------------------------}
int wherey() {
   CONSOLE_SCREEN_BUFFER_INFO csbi;
   COORD result;
   if (!GetConsoleScreenBufferInfo(
         GetStdHandle(STD_OUTPUT_HANDLE), &
         csbi
      ))
      // return -1;
      return result.Y;
  }
/*{--------------------------------------------}*/
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
struct ToadoXY {
    int PosX;
    int PosY;
};
void GetPosMouse(ToadoXY & pos) {
    int x, y;
    bool Pressed = false;
    HANDLE hStdin;
    DWORD cNumRead, fdwMode, i, eventRead;
    INPUT_RECORD irInBuf[128], Inrec;
    hStdin = GetStdHandle(STD_INPUT_HANDLE);
    fdwMode = ENABLE_EXTENDED_FLAGS;
    SetConsoleMode(hStdin, fdwMode);
    fdwMode = ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT;
    SetConsoleMode(hStdin, fdwMode);
    while (!Pressed) {
        PeekConsoleInput(hStdin, & Inrec, 1, & eventRead);
        ReadConsoleInput(hStdin, & Inrec, 1, & eventRead);
        x = Inrec.Event.MouseEvent.dwMousePosition.X;
        y = Inrec.Event.MouseEvent.dwMousePosition.Y;
        switch (Inrec.EventType) {
            case MOUSE_EVENT: {
                if (Inrec.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED) {
                    pos.PosX = x;
                    pos.PosY = y;
                    //   cout << " DA chay event chuot" << x << "<<<<<";
                    Pressed = true;
                }
                break;
            }
        }
    }
}
/*{--------------------------------------------}*/
struct XYMap {
    int MapY[99], MapX[99];
};
const int posXinc = 4;
const int posYinc = 2;
void Mapping(int x, int y, XYMap & Map) {
    int posX = 0, posY = 1;
    for (int i = 0; i < x; ++i) {
        posX = posXinc * i + 4;
        Map.MapX[i] = posX;
    }
    for (int i = 0; i < y; ++i) {
        posY = posYinc * i + 3;
        Map.MapY[i] = posY;
    }
}
/*{--------------------------------------------}*/
int SlectionSortF(int a[], int n, int x) {
    a[n] = a[n - 1] + 1;
    for (int i = 0; i <= n; i++) {
        if (x <= a[i]) {
            if (a[i] - x == 1) {
                return a[i];
            }
            if (x - a[i - 1] == 1) {
                return a[i - 1];
            }

            if (a[i] - x == 0) {
                return x;

            }
        }
    }
    return -1;
}
/*{--------------------------------------------}*/
int binarySearch(int arr[], int l, int r, int x, int ktl) {
    int tsDC;
    if (ktl == 0) {
        int xNew = SlectionSortF(arr, r, x);

        tsDC = xNew;
    } else if (ktl == 1) {
        tsDC = x;
    }
    for (int i = 0; i <= r - 1; i++) {}
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (arr[m] == tsDC) {
            return m;
        }
        if (arr[m] < tsDC)
            l = m + 1;
        else
            r = m - 1;
    }
    return -1;
}
/*{--------------------------------------------}*/
void DacPos(int x, int y, int xNew, int yNew, ToadoXY & XYpos, XYMap & Map) {
    XYpos.PosX = binarySearch(Map.MapX, 0, x, xNew, 0);
    XYpos.PosY = binarySearch(Map.MapY, 0, y, yNew, 1);
}

/*{--------------------------------------------}*/
void inBanCo(char a[100][100], int x, int y) {
    gotoXY(0, 0);
    int cnt = 0;
    int HesoB = 4 * (x - 2);
    int HesoA = round(HesoB / 2);
    cout << "--[Ban Co]";
    for (int i = 1; i <= HesoB + 1; i++) {
        cout << "-";
    }
    cout << endl;
    for (int i = 1; i <= x; i++) {
        if (i == 1) {
            cout << " ";
        }
        cout << "   " << i;
    }
    cout << endl;
    cout << "  -";
    for (int n = 1; n <= x; n++) {
        cout << "----";
    }
    cout << endl;

    for (int i = 1; i <= y; i++) {
        cout << i << " ";
        for (int j = 1; j <= x + 1; j++) {
            if (a[i - 1][j - 1] != 0) {
                cout << "| " << a[i - 1][j - 1] << " ";
                cnt++;
            } else {
                cout << "|   ";
            }
        }
        cout << endl;
        if (i != y) {
            cout << "  +";
            for (int n = 1; n <= x; n++) {
                cout << "---+";
            }
            cout << endl;
        } else {
            cout << "  -";
            for (int n = 1; n <= x; n++) {
                cout << "----";
            }
        }
    }
    cout << endl;
}
/*{--------------------------------------------------------------------}*/
bool CheoPhaiCheck(char a[100][100], int x, int y, int DKwin, char tsDC) {
    int l = 0, cnt = 0, tsCC, tsCR;
    if (y >= x) {
        tsCC = y;
        tsCR = x;
    } else if (x > y) {
        tsCC = x;
        tsCR = y;
    }
    for (int u = -tsCC; u <= tsCC; u++) {
        l = 0;
        for (int i = 0; i < tsCC + 1; i++) {
            for (int j = 0; j < tsCR + 1; j++) {
                int kq = i + 1;
                if (i - kq + 1 == j) {
                    l++;
                    if (a[i + u][l - 1] == tsDC) {
                        cnt++;
                        if (cnt == DKwin) {
                            return true;
                        }
                    } else {
                        cnt = 0;
                    }
                }

            }
        }
    }
    return false;
}
/*{--------------------------------------------}*/
bool HoaCheck(char a[100][100], int x, int y) {
    int Cnt = 0;
    for (int i = 0; i <= y; i++) {
        for (int j = 0; j <= x; j++) {
            if (a[i][j] == 'X' || a[i][j] == 'O') {
                Cnt++;
            }
        }
    }
    if (Cnt == x * y) {
        return true;
    }
    return false;
}
/*{--------------------------------------------------------------}*/
bool DocCheck(char a[100][100], int x, int y, int DKwin, char tsDC) {
    int count = 0;
    for (int i = 0; i <= x; i++) {
        for (int j = 0; j <= y; j++) {
            if (a[j][i] == tsDC) {
                count++;
                if (count == DKwin) {
                    return true;
                }
            } else {
                count = 0;
            }
        }

    }
    return false;
}
/*{----------------------------------------------------------------}*/
bool NgangCheck(char a[100][100], int x, int y, int DKwin, char tsDC) {
    int count = 0;
    for (int i = 0; i <= y; i++) {
        for (int j = 0; j <= x; j++) {
            if (a[i][j] == tsDC) {
                count++;
                if (count == DKwin) {
                    return true;
                }
            } else {
                count = 0;
            }
        }
    }
    return false;
}
/*{-----------------------------------------------------------}*/
int isWin(char a[100][100], int x, int y, int Dkwin, char ktl) {
    char d[100][100] = {};
    for (int i = 0; i < y; i++) {
        for (int j = x - 1; j >= 0; j--) {
            d[i][x - j - 1] = a[i][j];
        }
    }
    if (CheoPhaiCheck(d, x, y, Dkwin, ktl)) {
        return 1;
    }
    if (CheoPhaiCheck(a, x, y, Dkwin, ktl)) {
        //cout << "Ham iswin return ve cheo";
        return 1;
    }
    if (DocCheck(a, x, y, Dkwin, ktl)) {
        //cout << "Ham iswin return ve doc";
        return 1;
    } else if (NgangCheck(a, x, y, Dkwin, ktl)) {
        //cout << "Ham iswin return ve ngang";
        return 1;
    } else if (HoaCheck(a, x, y)) {
        //	cout << "Ham iswin return ve hoa";
        return 2;
    }
    //cout << "Ham iswin return ve 0";
    return 0;
}
/*{-----------------------}*/
char Key() {
    bool event = false;
    while (event == false) {
        if (kbhit()) {
            char GetKey = getch();
            return GetKey;
        }
    }
    return 0;
}
/*{------------------------}*/
bool SystaxCheck(char ktl, int x, int y, int yarr, int xarr, char a[100][100]) {
    if (yarr == -1 || xarr == -1) {
        cout << "Vi Tri Khong Hop Le!";
        return true;
    }
    if (ktl == 'O') {
        if (a[yarr][xarr] == 'O') {
            cout << "O Co Nay Ban Da Danh Roi!";
            return true;
        } else if (a[yarr][xarr] == 'X') {
            cout << "O Co Nay X Da Danh Roi!";
            return true;
        }
    } else if (ktl == 'X') {
        if (a[yarr][xarr] == 'X') {
            cout << "O Co Nay Ban Da Danh Roi!";
            return true;
        } else if (a[yarr][xarr] == 'O') {
            cout << "O Co Nay O Da Danh Roi!";
            return true;
        }
    }
    cout << "                                                ";
    return false;
}
/*{------------------------------------------------------------------------}*/
const string mainMenuArr[5] = {
        "[1]-Choi",
        "[2]-Cai Dat",
        "[3]-Tac Gia",
        "[4]-Thoat "
};
string settingMenuArr[3] = {
        "[1]-KeyBoard Coord: [OFF]",
        "[2]-Sound: [OFF]",
};
bool KbCoord = false;
void showMenu(const string arr[], int size, int y) {
    for (int i = 0; i < size; i++) {
        if (i == y) {
            SetConsoleTextAttribute(hConsole,   FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
            cout << arr[i] << endl;
        } else {
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            cout << arr[i] << endl;
        }
    }
}

void updateMenu(const string arr[], int old_y, int new_y, int ktl) {
    int y, y_2;
    if (ktl == 1){
        y = old_y;
        y_2 = new_y;
    } else if (ktl == 0){
        y = old_y+8;
        y_2 = new_y+8;
    }
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    // gotoXY(arr[old_y].length() + 1, old_y + 8);
    gotoXY(0, y);
    cout << arr[old_y];
    SetConsoleTextAttribute(hConsole,   FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
    // gotoXY(arr[new_y].length() + 1, new_y + 8);
    gotoXY(0, y_2);
    cout << arr[new_y];
}

void toggleSetting(int y) {
    if (settingMenuArr[y].find("[OFF]") != string::npos) {
        settingMenuArr[y].replace(settingMenuArr[y].find("[OFF]"), 8, "[ON] ");
    } else {
        settingMenuArr[y].replace(settingMenuArr[y].find("[ON]"), 4, "[OFF]");
    }
}

int getMenuSelection(const string arr[], int size, int ktl) {
    char ch;
    int y = 0, tsDC = 0;
    if (ktl == 1) {
        gotoXY(0,0);
        showMenu(arr, size, y);
        tsDC = KEY_ESC;
    } else if (ktl == 0) {
        showMenu(arr, size, y);
        tsDC = KEY_ENTER;
    }

    while (ch != tsDC) {
        if (kbhit()) {
            ch = getch();
            int old_y = y;
            if (ch == KEY_UP) {
                y -= 1;
                if (y < 0) {
                    y = size - 1;
                }
            } else if (ch == KEY_DOWN) {
                y += 1;
                if (y > size - 1) {
                    y = 0;
                }
            } else if (ktl == 1 && ch == KEY_ENTER) {
                toggleSetting(y);
                if (y == 1 && KbCoord == false) {
                    KbCoord = true;
                } else {
                    KbCoord = false;
                }
                gotoXY(0, 0);
                showMenu(arr, size, y);
            } else if (ch == tsDC) {
                if (tsDC == KEY_ESC) {
                    return -1;
                }
                break;
            }
            updateMenu(arr, old_y, y, ktl);
        }
    }
    return y;
}
/*{----------------------------------------------}*/
int SlectionSys() {
    gotoXY(baseX, baseY);
    int mainSelection = getMenuSelection(mainMenuArr, 4, 0);
    if (mainSelection == 1) {
        clearScreen();
        getMenuSelection(settingMenuArr, 3, 1);
        clearScreen();
    } else if (mainSelection == 2) {
        return 2;
    } else {
        return 1;
    }
    return -1;
}
/*{------------------------------------------------------}*/
int LoadGame(ToadoXY & xyPOS, XYMap & Map) {
    int chon, Win, Xwin = 0, Owin = 0;
    int luotX = 0, luotO = 0;
    bool opl = false, xpl = false, flagX = true, flagO = true;
    int x = 31, y = 31;
    char a[100][100] = {}, Dkwin;
    char null[100][100] = {};
    char pl;
    clearScreen();
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    cout << "-----PLAYING------";
    cout << endl;
    cout << "Nhap Do lon Ban Co Toi Da [9x9]: ";
    while (x > 9 || y > 9 || x < 2 || y < 2) {
        cin >> x >> y;
        if (x > 9 || y > 9 || x < 2 || y < 2) {
            cout << "Ban Co Qua Lon!" << endl;
            cout << "Nhap lai: ";
        }
    }
    cout << endl << "Nhap So Dau Can De Chien Thang: ";
    while (Dkwin > x || Dkwin > y || Dkwin < 1) {
        Dkwin = Key() - '0';
        if (Dkwin > x || Dkwin > y || Dkwin < 1) {
            gotoXY(0, 3);
            cout << endl << "Qua Nhieu Dau, Nhap lai!" << endl;
            cout << "Nhap Lai! ";
        }
    }
    cout << endl << "Ai di Truoc: 1-[X]      2-[O]" << endl;
    bool flags = true;
    while (flags == true) {
        if (Key() == '1') {
            xpl = true;
            pl = 'X';
            flags = false;
        } else if (Key() == '2') {
            opl= true;
            pl = 'O';
            flags = false;
        } else {
            cout << "Khong Ton Tai!";
            cout << "Nhap Lai";
            sleep(1.243);
            flags = true;
        }
        Mapping(x, y, Map);
    }

    clearScreen();
    int isPlayerWin = 0;
    while (true) {
        if (xpl) {
            flagX = true;
            while (flagX) {
                inBanCo(a, x, y);
                cout << ">>LUOT X<<";
                GetPosMouse(xyPOS);
                DacPos(x, y, xyPOS.PosX, xyPOS.PosY, xyPOS, Map);
                xpl = false;
                opl = true;
                if (SystaxCheck('X', x, y, xyPOS.PosY, xyPOS.PosX, a)) {
                    flagX = true;
                } else {
                    a[xyPOS.PosY][xyPOS.PosX] = 'X';
                    luotX++;
                    if (luotX >= Dkwin) {
                        if (isWin(a, x, y, Dkwin, 'X') == 1) {
                            isPlayerWin = 1;
                            Xwin = true;
                            opl = false;
                            flagX = false;
                        } else if (isWin(a, x, y, Dkwin, 'X') == 2) {
                            isPlayerWin = 2;
                            opl = false;
                            flagX = false;
                        }
                    }
                    flagX = false;
                }
            }
        }
        if (opl) {
            flagO = true;
            while (flagO) {
                inBanCo(a, x, y);
                cout << ">>LUOT O<<";
                GetPosMouse(xyPOS);
                DacPos(x, y, xyPOS.PosX, xyPOS.PosY, xyPOS, Map);
                opl = false;
                xpl = true;
                if (SystaxCheck('O', x, y, xyPOS.PosY, xyPOS.PosX, a)) {
                    flagO = true;
                } else {
                    a[xyPOS.PosY][xyPOS.PosX] = 'O';
                    luotO++;
                    if (luotO >= Dkwin) {
                        if (isWin(a, x, y, Dkwin, 'O') == 1) {
                            isPlayerWin = 1;
                            Owin = true;
                            xpl = false;
                            flagO = false;
                        } else if (isWin(a, x, y, Dkwin, 'O') == 2) {
                            isPlayerWin = 2;
                            xpl = false;
                            flagO = false;
                        }
                    }
                    flagO = false;
                }
            }
        }
        if (isPlayerWin == 1) {
            if (Owin) {
                clearScreen();
                inBanCo(a, x, y);
                cout << "Chuc Mung! O Thang" << endl;
                cout << "Ban Co Muon Choi Lai Khong?" << endl;
                cout << "y-[Co]            n-[NO]";
                // cout << "Nhan Phim [ESC] De quay lai menu.";
                if (Key() == 'y') {
                    luotX = 0;
                    luotO = 0;
                    if (pl == 'O') {
                        opl = true;
                    } else if (pl == 'X') {
                        xpl = false;
                    }
                    isPlayerWin = 0;
                    Owin--;
                    for (int i = 0; i <= x; i++) {
                        for (int j = 0; j <= y; j++) {
                            a[i][j] = null[i][j];
                        }
                    }
                } else if (Key() == 'n') {
                    return 1;
                }
            } else if (Xwin == 1) {
                clearScreen();
                inBanCo(a, x, y);
                cout << "Chuc Mung! X Thang" << endl;
                cout << "Ban Co Muon Choi Lai Khong?" << endl;
                cout << "y-[Co]            n-[NO]";
                //   cout << "Nhan Phim [ESC] De quay lai menu.";
                if (Key() == 'y') {
                    luotX = 0;
                    luotO = 0;
                    if (pl == 'O') {
                        opl = true;
                    } else if (pl == 'X') {
                        xpl = true;
                    }
                    isPlayerWin = 0;
                    Xwin = false;
                    for (int i = 0; i <= x; i++) {
                        for (int j = 0; j <= y; j++) {
                            a[i][j] = null[i][j];
                        }
                    }
                } else if (Key() == 'n') {
                    return 1;
                }
            }
        } else if (isPlayerWin == 2) {
            clearScreen();
            inBanCo(a, x, y);
            cout << "Ca 2 Hoa" << endl;
            cout << "Ban Co Muon Choi Lai Khong?" << endl;
            cout << "y-[Co]            n-[NO]"<< endl;
            //   cout << "Nhan Phim [ESC] De quay lai menu.";
            if (Key() == 'y') {
                luotX = 0;
                luotO = 0;
                if (pl == 'O') {
                    opl = true;
                } else if (pl == 'X') {
                    xpl = true;
                }
                isPlayerWin = 0;
                for (int i = 0; i <= x; i++) {
                    for (int j = 0; j <= y; j++) {
                        a[i][j] = null[i][j];
                    }
                }
            } else if (Key() == 'n') {
                return 1;
            }
        }
    }
}
/*{------------------------------------------------------------------------}*/

/*{---------------------------------------------------------------------------------}*/
int main(void) {
    XYMap Map;
    ToadoXY xyPOS;

    bool event = false;
    bool win = true;
    while (win) {
        gotoXY(0,0);
        clearScreen();
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        cout << "------------------[Bien The Co CARO]--------------------" << endl;
        cout << "*Made By:   //   //   ////////  //  ////  //  //   //  *" << endl;
        cout << "*12/04/23  //   //      //         ////  //  //   //   *" << endl;
        cout << "*         ///////      //     //  // // //  ///////    *" << endl;
        cout << "*        //   //      //     //  //  ////  //   //     *" << endl;
        cout << "*       //   //  //  //     //  //   ///  //   //      *" << endl;
        cout << "--------------------------------------------------------" << endl;
        gotoXY(baseX, baseY+5);
        cout << ch[0] << "/" << ch[1] << " De Chon  " << "|  ENTER - De xac nhan" ;

        int chon = SlectionSys();

        if (chon == 1) {
            LoadGame(xyPOS, Map);
        }
    }
}