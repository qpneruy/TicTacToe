//
// Created by huuti on 002, 02/02/2024.
//

#ifndef TICTACTOEV2_WINLOGIC_H
#define TICTACTOEV2_WINLOGIC_H

struct Player {
    int PosX;
    int PosY;
    int score;
    int intWin;
};

bool HorVerCheck(Player Data, char table[9][9], int width, int height, char Player);

#endif //TICTACTOEV2_WINLOGIC_H
