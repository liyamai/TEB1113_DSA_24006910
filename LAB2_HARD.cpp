#include <vector>
#include <string>
#include <iostream>

// HARD: Validity of a given Tic-Tac-Toe board configuration

using namespace std;

bool isWin(const vector<string>& board, char player) {
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true;
        }
    }
    for (int j = 0; j < 3; ++j) {
        if (board[0][j] == player && board[1][j] == player && board[2][j] == player) {
            return true;
        }
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true;
    }
    return false;
}

bool isValidTicTacToe(vector<string>& board) {
    int countX = 0, countO = 0;
    for (const string& row : board) {
        for (char cell : row) {
            if (cell == 'X') {
                countX++;
            } else if (cell == 'O') {
                countO++;
            }
        }
    }
    
    bool xWin = isWin(board, 'X');
    bool oWin = isWin(board, 'O');
    
    if (xWin && oWin) {
        return false;
    }
    if (xWin) {
        return countX == countO + 1;
    }
    if (oWin) {
        return countX == countO;
    }
    return (countX == countO) || (countX == countO + 1);
}

int main() {
    vector<string> board1 = {"XOX", "O O", "XOX"};
    cout << (isValidTicTacToe(board1) ? "Valid" : "Invalid") << endl; 

    vector<string> board2 = {"XXX", "   ", "OOO"};
    cout << (isValidTicTacToe(board2) ? "Valid" : "Invalid") << endl; 

    vector<string> board3 = {"XOX", " X ", "   "};
    cout << (isValidTicTacToe(board3) ? "Valid" : "Invalid") << endl; 
    return 0;
}
