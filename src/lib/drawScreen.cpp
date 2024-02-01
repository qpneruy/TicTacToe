//
// Created by huuti on 001, 01/02/2024.
//
#include <iostream>
#include <unordered_map>


void inBanCo(char tableData[9][9], int width, int height, int x) {
    std::string space {};
    for (int i = 0 ;i < x; i++ ) space += " ";
    std::cout << space + "      ";

    for (int i = 1; i <= width; i++) {
        std::cout << i << "   "; // 1   2   3   4 ....
    }
    std::cout << "\n";
    for (int i = 0; i <= height; i++) {
        std::cout << space << "    ";
        for (int o = 0; o <= width; o++) {
            if (o == 0) {  std::cout << "+"; } // "+" + (2)
            else {
                std::cout << "---+"; // (2): ----+----+----+...
            }
        }
        std::cout << "\n";
        if (i != height) {
            std::cout << space + "  " << i+1 << " "; // 1 |; 2 |; ..|
            for (int j = 0; j < width; j++) {
                if (tableData[i][j] == 'X' || tableData[i][j] == 'O'){  std::cout << "| " << tableData[i][j] << " ";} else {
                    std::cout << "|   ";
                } // (1): | .. | .. | .. | ...
            }
            std::cout << "|"; // (1) + "|"; -> | .. | .. | .. |
        }

        std::cout << "\n";
    }
}
std::string Main[4] = {"Choi", "Cai Dat", "Tiep Tuc", "Tac Gia"};
std::string Setting[4] = {"Music: OFF", "askjdakhjd: OFF"};

void inMenu(const std::string& key) {
 if (key == "1") {
     std::cout << Main[0] << "\n";
     std::cout << Main[1] << "\n";;
     std::cout << Main[2] << "\n";
     std::cout << Main[3] << "\n";
 } else if (key == "2") {
     std::cout << Setting[0] << "\n";
     std::cout << Setting[1] << "\n";
 }
}