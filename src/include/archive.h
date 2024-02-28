//
// Created by huuti on 026, 26/02/2024.
//

#ifndef TICTACTOEV2_ARCHIVE_H
#define TICTACTOEV2_ARCHIVE_H


#include "drawScreen.h"
#include "winLogic.h"
#include "mapping.h"
#include <set>

struct CompareScore {
    bool operator()(const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) const {
        return a.second > b.second;
    }
};
class leaderboard {
public:
    std::set<std::pair<std::string, int>, CompareScore> leaderboardData;
    void add_player(const std::string& Name, int score);
};
struct gameData {
    std::string table[9][9] = {};
    drawData drData;
    Player X{}, O{};
    posData poData;
    leaderboard X_ld, O_ld;
    bool Music = false;
};

void save(const gameData& Data);
gameData load();


#endif //TICTACTOEV2_ARCHIVE_H