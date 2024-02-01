//
// Created by huuti on 001, 01/02/2024.
//
#include <iostream>
#include <unordered_map>

std::string space = "                     ";
void inBanCo(char tableData[9][9], int width, int height) {
    std::cout << space + "      ";
    for (int i = 1; i <= width; i++) {
        std::cout << i << "   ";
    }
    std::cout << "\n";
    for (int i = 0; i <= height + 1; i++) {
        std::cout << space << "    ";
        for (int o = 0; o <= width; o++) {
            if (o == 0) {  std::cout << "+"; }
            else {
                std::cout << "---+";
            }
        }
        std::cout << "\n";
        if (i != height + 1) {
            std::cout << space + "  " << i+1 << " ";
            for (int j = 0; j < width; j++) {
                if (tableData[i][j] == 'X' || tableData[i][j] == 'O'){  std::cout << "| " << tableData[i][j] << " ";} else {
                    std::cout << "|   ";
                }
            }
            std::cout << "|";
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