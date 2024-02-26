//
// Created by huuti on 026, 26/02/2024.
//

#ifndef TICTACTOEV2_ARCHIVE_H
#define TICTACTOEV2_ARCHIVE_H


#include "drawScreen.h"
#include "winLogic.h"
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

int save(std::string table[9][9], drawData drData, Player plX, Player plO, const leaderboard& X_ld, const leaderboard& O_ld);
int load(std::string table[9][9], drawData &drData, Player &plX, Player &plO, const leaderboard& X_ld, const leaderboard& O_ld);


#endif //TICTACTOEV2_ARCHIVE_H