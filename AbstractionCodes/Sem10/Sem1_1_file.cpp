
#include <stdio.h>
#include "console.h"
#include "simpio.h"
#include "grid.h"
#include <fstream>
#include "tokenscanner.h"

using namespace std;
enum position {
cross = 1,
neither = 0,
nought = -1
};
struct boardT {
Grid<position> grid; position currentPlayer;
};

bool doesPlayerWin(boardT& board, position player) { for (int i = 0; i < 3; i++) {
bool isRowFull = true;
bool isColumnFull = true;
for (int j = 0; j < 3; j++) {
if (board.grid[i][j] != player) isRowFull = false;
if (board.grid[j][i] != player) isColumnFull = false;
}
if (isRowFull || isColumnFull)
return true;
}
if (board.grid[0][0] == player
&& board.grid[1][1] == player
&& board.grid[2][2] == player)
return true;
if (board.grid[0][2] == player
&& board.grid[1][1] == player
&& board.grid[2][0] == player)
return true;
return false;
}
bool isGameOver(boardT& board, position& gameResult) { if (doesPlayerWin(board, cross)) {
gameResult = cross;
return true;
}
if (doesPlayerWin(board, nought)) { gameResult = nought;
return true;
}
for (int i = 0; i < 3; i++) {
for (int j = 0; j < 3; j++) { if (board.grid[i][j] == neither)
return false; }
}
gameResult = neither; return true;
}

position gameFinalResult(boardT& board) {
position gameResult;
if (isGameOver(board, gameResult))
return gameResult;
position otherPlayer;
if (board.currentPlayer == cross)
otherPlayer = nought;
else
otherPlayer = cross;
gameResult = otherPlayer;
for (int i = 0; i < 3; i++) {
for (int j = 0; j < 3; j++) {
if (board.grid[i][j] == neither) {
boardT nextBoard = board;
nextBoard.grid[i][j] = board.currentPlayer; nextBoard.currentPlayer = otherPlayer; position currentResult = gameFinalResult(nextBoard); if (board.currentPlayer == cross) {
if (currentResult > gameResult) gameResult = currentResult;
} else {
if (currentResult < gameResult) gameResult = currentResult;
}
}
}
}
return gameResult; }



int main() {
    // Initialize the game board
    boardT gameBoard;
    gameBoard.grid = Grid<position>(3, 3);
    // Assuming it's X's turn to move
    gameBoard.currentPlayer = neither;

    // Determine the best move for the current player
    position bestMove = gameFinalResult(gameBoard);

    // Output the result
    cout << "Best move for the current player: ";
    switch (bestMove) {
        case cross:
            cout << "Win" << endl;
            break;
        case nought:
            cout << "Lose" << endl;
            break;
        case neither:
            cout << "Draw" << endl;
            break;
    }

    return 0;
}
