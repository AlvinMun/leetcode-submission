#include <stdbool.h>
#include <string.h>

// Function to check if placing 'c' in board[row][col] is valid
bool isValid(char** board, int row, int col, char c) {
    for (int i = 0; i < 9; i++) {
        // Check row
        if (board[row][i] == c) return false;
        // Check column
        if (board[i][col] == c) return false;
        // Check 3x3 sub-box
        if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c) return false;
    }
    return true;
}

bool solve(char** board) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] == '.') {
                for (char c = '1'; c <= '9'; c++) {
                    if (isValid(board, i, j, c)) {
                        board[i][j] = c;
                        if (solve(board)) {
                            return true;
                        } else {
                            board[i][j] = '.'; // backtrack
                        }
                    }
                }
                return false; // trigger backtracking
            }
        }
    }
    return true; // all cells filled
}

void solveSudoku(char** board, int boardSize, int* boardColSize) {
    solve(board);
}