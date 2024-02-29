//
// Created by huuti on 026, 26/02/2024.
//

#include "include/archive.h"
#include "include/drawScreen.h"
#include <nlohmann/json.hpp>
#include <fstream>
#include <filesystem>

void leaderboard::add_player(const std::string &Name, int score) {
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

void init_file() {
    std::ifstream file;
    std::string path = std::filesystem::current_path().string();
    file.open(path + "\\data.json");
    if (file) return;
    using json = nlohmann::json;
    std::ofstream f(path + "\\data.json");
    json ex2 = R"(
  {
    "board": {
        "Oscore": 0,
        "Xscore": 0,
        "grid": [
            [
                "",
                "",
                ""
            ],
            [
                "",
                "",
                ""
            ],
            [
                "",
                "",
                ""
            ]
        ],
        "intWin": 3,
        "size": [
            3,
            3
        ]
    },
    "leaderBoard": [
        "None"
    ],
    "setting": {
        "music": true
    }
}
)"_json;
    f << ex2.dump(4);
    f.close();
}

void save(const gameData &Data) {
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
    if (!Data.player.leaderboardData.empty()) {
        for (const auto &Player: Data.player.leaderboardData) {
            ++count;
            data["leaderBoard"].push_back({{"top",   std::to_string(count)},
                                                {"name",  Player.first},
                                                {"score", Player.second}});
            if (count + 1 == 11) break;
        }
    } else { data["leaderBoard"].push_back("None"); }
    data["setting"]["music"] = true;
    std::string path = std::filesystem::current_path().string();
    std::ofstream file(path + R"(\data.json)");
    file << data.dump(4);
    file.close();
}


gameData load() {
    gameData Data;
    nlohmann::json data;
    std::string path = std::filesystem::current_path().string();
    std::ifstream file(path + R"(\data.json)");
    file >> data;
    file.close();
    Data.drData.x = 40;
    Data.drData.y = 11;
    Data.X.score = data["board"]["Xscore"];
    Data.O.score = data["board"]["Oscore"];
    Data.drData.height = data["board"]["size"][0];
    Data.drData.width = data["board"]["size"][1];
    Data.drData.intWin = data["board"]["intWin"];
    for (int i = 0; i < Data.drData.height; i++) {
        for (int j = 0; j < Data.drData.width; j++) {
            Data.table[i][j] = data["board"]["grid"][i][j];
        }
    }
    if (data["leaderBoard"][0] != "None") {
        for (auto player: data["leaderBoard"])
            Data.player.add_player(player["name"], player["score"]);
    }
    Data.Music = data["setting"]["music"];
    return Data;
}
