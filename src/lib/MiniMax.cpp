////
//// Created by huuti on 011, 11/03/2024.
////
//
//#include "include/MiniMax.h"
//#include "include/archive.h"
//#include <iostream>
//#include <utility>
//#include "include/winLogic.h"
//bool isMovesLeft(const gameData& gData) {
//    for (int i = 0; i < gData.drData.height; ++i)
//        for (int j = 0; j < gData.drData.width; ++j)
//            if (gData.table[i][j] == " ")
//                return true;
//    return false;
//}
//
//int evaluate(const gameData& gData) {
//    isWin(gData.table, gData.drData, "0");
//}
//
//int minimax(int depth, int alpha, int beta, bool maximizingPlayer, gameData& gData) {
//    if (!isMovesLeft(gData)|| depth == 0) {
//        return evaluate();
//    }
//
//    if (maximizingPlayer) {
//        int maxEval = INT_MIN;
//        for (int i = 0; i < gData.drData.height; ++i) {
//            for (int j = 0; j < gData.drData.width; ++j) {
//                if (gData.table[i][j] == " ") {
//                    gData.table[i][j] = "O";
//                    int eval = minimax(depth - 1, alpha, beta, false, gData);
//                    gData.table[i][j] = " ";
//                    maxEval = std::max(maxEval, eval);
//                    alpha = std::max(alpha, eval);
//                    if (beta <= alpha)
//                        break;
//                }
//            }
//        }
//        return maxEval;
//    } else {
//        int minEval = INT_MAX;
//        for (int i = 0; i < gData.drData.height; ++i) {
//            for (int j = 0; j < gData.drData.width; ++j) {
//                if (gData.table[i][j] == " ") {
//                    gData.table[i][j] = "X";
//                    int eval = minimax(depth - 1, alpha, beta, true, gData);
//                    gData.table[i][j] = " ";
//                    minEval = std::min(minEval, eval);
//                    beta = std::min(beta, eval);
//                    if (beta <= alpha)
//                        break;
//                }
//            }
//        }
//        return minEval;
//    }
//}
//
//std::pair<int, int> findBestMove(gameData& gData) {
//    int bestVal = INT_MIN;
//    std::pair<int, int> bestMove = std::make_pair(-1, -1);
//
//    for (int i = 0; i < gData.drData.height; ++i) {
//        for (int j = 0; j < gData.drData.width; ++j) {
//            if (gData.table[i][j] == " ") {
//                gData.table[i][j] = "O";
//                int moveVal = minimax(5, INT_MIN, INT_MAX, false, gData);
//                gData.table[i][j] = " ";
//                if (moveVal > bestVal) {
//                    bestMove = std::make_pair(i, j);
//                    bestVal = moveVal;
//                }
//            }
//        }
//    }
//
//    return bestMove;
//}