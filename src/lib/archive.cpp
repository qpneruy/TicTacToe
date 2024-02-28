//
// Created by huuti on 026, 26/02/2024.
//

#include "include/archive.h"
#include "include/drawScreen.h"
#include "include/winLogic.h"
#include <nlohmann/json.hpp>
#include <fstream>

using namespace std;

void leaderboard::add_player(const std::string& Name, int score) {
    bool found = false;
    if (!leaderboardData.empty()) {
        for (auto it = leaderboardData.begin(); it != leaderboardData.end(); ++it) {
            if (it->first == Name) {
                found = true;
                if (it->second < score) {
                    leaderboardData.erase(it);
                    std::pair<std::string, int> mypair;
                    mypair.first = Name;
                    mypair.second = score;
                    leaderboardData.insert(mypair);
                    break;
                }
            }
        }
        if (!found)
            leaderboardData.emplace(Name, score);
    } else {
        leaderboardData.emplace(Name, score);
    }
}



void save(const gameData& Data) {
    nlohmann::json data;
    for (int i = 0; i < Data.drData.height; ++i) {
        nlohmann::json row;
        for (int j = 0; j < Data.drData.width; ++j) {
            row.push_back(Data.table[i][j]);
        }
        data["board"]["grid"].push_back(row);
    }
    data["board"]["size"] = {Data.drData.height, Data.drData.width}; //nho sua lai cho nay cho dong bo voi nhap du lieu
    data["board"]["Xscore"] = Data.X.score;
    data["board"]["Oscore"] = Data.O.score;
    data["board"]["intWin"] = Data.drData.intWin;
    int count = 0;
    if (!Data.X_ld.leaderboardData.empty()) {
        for (const auto &Player: Data.X_ld.leaderboardData) {
            ++count;
            data["leaderBoard"]["X"].push_back({{"top",    std::to_string(count)},
                                                {"name", Player.first},
                                                {"score",  Player.second}});
            if (count + 1 == 11) break;
        }
    } else {data["leaderBoard"]["X"].push_back("None");}
    count = 0;
    if (!Data.O_ld.leaderboardData.empty()) {
        for (const auto &Player: Data.O_ld.leaderboardData) {
            ++count;

            data["leaderBoard"]["O"].push_back({{"top",    std::to_string(count)},
                                                {"name", Player.first},
                                                {"score",  Player.second}});
            if (count + 1 == 11) break;
        }
    } else {data["leaderBoard"]["O"].push_back("None");}
    data["setting"]["music"] = true;
    std::ofstream file(R"(D:\Project\CSharp\TicTacToe\src\data.json)");
    file << data.dump(4);
    file.close();
}


gameData load() {
    gameData Data;
    nlohmann::json data;
    std::ifstream file(R"(D:\Project\CSharp\TicTacToe\src\data.json)");
    file >> data;
    file.close();
    Data.X.score = data["board"]["Xscore"];
    Data.O.score = data["board"]["Oscore"];
    Data.drData.height = data["board"]["size"][0];
    Data.drData.width = data["board"]["size"][1];
    Data.drData.intWin = data["board"]["intWin"];
    for (int i = 0; i  < Data.drData.height; i++) {
        for (int j = 0; j < Data.drData.width; j++){
            Data.table[i][j] = data["board"]["grid"][i][j];
        }
    }
    if (data["leaderBoard"]["O"][0] != "None") {
        for (auto player : data["leaderBoard"]["O"])
        Data.O_ld.add_player(player["name"], player["score"]);
    }
    if (data["leaderBoard"]["X"][0] != "None") {
        for (auto player : data["leaderBoard"]["X"])
            Data.X_ld.add_player(player["name"], player["score"]);
    }
    Data.Music = data["setting"]["music"];
    return Data;
}
