//
//  Sem1_1.cpp
//  Blank Project
//
//  Created by Mariam Samkharadze on 12.04.24.
//

#include <stdio.h>
#include "console.h"
#include "simpio.h"
#include "grid.h"
#include <fstream>
#include "tokenscanner.h"


enum cellState {
    N = 0,
    X = 1,
    O = -1
};

const int BOARD_LENTH = 3;

struct gameState {
    Grid<cellState> board;
    cellState currPlayer;
    void nextPlayer() {
        if(currPlayer == X) currPlayer = O;
        if(currPlayer == O) currPlayer = X;
    }
};

cellState getCell(gameState& game, int i, int j, string type) {
    if(type.compare("row") == 0) return game.board[i][j];
    if(type.compare("column") == 0) return game.board[j][i];
    return N;
}

bool lineIsFilled(gameState& game, cellState (fun) (gameState&, int, int, string), cellState &player, string type) {
    for(int i = 0; i < BOARD_LENTH; i++) {
        bool filled = true;
        for(int j = 0; j < BOARD_LENTH; j++) {
            if(fun(game, i, j, type) != player)
                filled = false;
        }
        if(filled) return true;
    }
    return false;
}

bool diagonalFilled(gameState& game, cellState &player) {
    bool filledOne = true, filledTwo = true;
    for(int i = 0; i < BOARD_LENTH; i++) {
        if(game.board[i][i] != player)
            filledOne = false;
        if(game.board[i][BOARD_LENTH - i - 1] != player)
            filledTwo = false;
    }
    if(filledOne || filledTwo) return true;
    return false;
}

bool isThisPlayerWinner(gameState& game, cellState player, cellState &winner) {
    if(lineIsFilled(game, getCell, player, "row")
       || lineIsFilled(game, getCell, player, "column") || diagonalFilled(game, player)) {
        winner = player;
        return true;
    }
    return false;
}

bool isDraw(gameState& game) {
    for(int i = 0; i < BOARD_LENTH; i++) {
        for(int j = 0; j < BOARD_LENTH; j++) {
            if(game.board[i][i] == N) return false;
        }
    }
    return true;
}

bool isGameOver(gameState& game, cellState &winner) {
    if(isThisPlayerWinner(game, X, winner)) return true;
    if(isThisPlayerWinner(game, O, winner)) return true;
    if(isDraw(game)) return true;
    return false;
}

cellState playGame(gameState& game) {
    cellState winner;
    if(isGameOver(game, winner)) {
        return winner;
    }

//    cellState myIdentity = game.currPlayer;
    game.nextPlayer();
    winner = game.currPlayer;
    game.nextPlayer();
    for(int i = 0; i < BOARD_LENTH; i++) {
        for(int j = 0; j < BOARD_LENTH; j++) {
            if(game.board[i][j] == N) {
                game.board[i][j] = game.currPlayer;
                game.nextPlayer();
                cellState gameRes = playGame(game);
                if(game.currPlayer == X) {
                    if(gameRes > winner) {
                        winner = gameRes;
                    }
                } else {
                    if(gameRes < winner) {
                        winner = gameRes;
                    }
                }
                game.board[i][j] = N;
                game.nextPlayer();
            }
        }
    }
    return winner;
}


int main() {
    gameState game;
    Grid<cellState> grid(BOARD_LENTH, BOARD_LENTH);
    game.board = grid;
    for (int i = 0; i < BOARD_LENTH; ++i) {
        for (int j = 0; j < BOARD_LENTH; ++j) {
            game.board[i][j] = N;
        }
    }
    game.currPlayer = O;
//    game.board[1][1] = X;
//    game.board[2][2] = X;
//    game.board[0][0] = X;
    cout << game.board << endl;
    
    cellState winner = playGame(game);
    
    if (winner == X) {
        cout << "Player X wins!" << endl;
    } else if (winner == O) {
        cout << "Player O wins!" << endl;
    } else {
        cout << "It's a draw!" << endl;
    }
    return 0;
}
