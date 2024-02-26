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


using json = nlohmann::json;
int save(string table[9][9], drawData drData, Player plX, Player plO, const leaderboard& X_ld, const leaderboard& O_ld) {
    nlohmann::json data;
    for (int i = 0; i < drData.height; ++i) {
        nlohmann::json row;
        for (int j = 0; j < drData.width; ++j) {
            row.push_back(table[i][j]);
        }
        cout << row;
        data["board"]["grid"].push_back(row);
    }
    data["board"]["size"] = {drData.height, drData.width}; //nho sua lai cho nay cho dong bo voi nhap du lieu
    data["board"]["Xscore"] = plX.score;
    data["board"]["Oscore"] = plO.score;
    data["board"]["intWin"] = drData.intWin;
    int count = 0;
    if (!X_ld.leaderboardData.empty()) {
        for (const auto &Player: X_ld.leaderboardData) {
            ++count;
            data["leaderBoard"]["X"].push_back({{"top",    std::to_string(count)},
                                                {"player", Player.first},
                                                {"score",  Player.second}});
            if (count + 1 == 11) break;
        }
    } else {data["leaderBoard"]["X"].push_back("None");}
    count = 0;
    if (!O_ld.leaderboardData.empty()) {
        for (const auto &Player: O_ld.leaderboardData) {
            ++count;

            data["leaderBoard"]["O"].push_back({{"top",    std::to_string(count)},
                                                {"player", Player.first},
                                                {"score",  Player.second}});
            if (count + 1 == 11) break;
        }
    } else {data["leaderBoard"]["O"].push_back("None");}
    data["setting"]["music"] = true;
    std::ofstream file(R"(D:\Project\CSharp\TicTacToe\src\data.json)");
    file << data.dump(4);
    file.close();
}


int load(std::string table[9][9], drawData &drData, Player &plX, Player &plO, const leaderboard& X_ld, const leaderboard& O_ld) {
    std::ifstream file(R"(D:\Project\CSharp\TicTacToe\src\data.json)");
    if (!file.is_open()) {
        std::cerr << "Không thể mở tệp JSON." << std::endl;
        return 1;
    }
    json data;
    file >> data;
    file.close();
    int height = data["board"]["size"][0];
    int width = data["board"]["size"][1];
    for (int i = 0; i  < height; i++) {
        for (int j = 0; j < width; j++){
            table[i][j] = data["board"]["grid"][i][j];
        }
    }
    for (int i = 0; i  < height; i++) {
        cout << "\n";
        for (int j = 0; j < width; j++){
            cout << table[i][j] << " ";
        }
    }

    return 0;
}
