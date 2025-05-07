bool isValidSudoku(char** board, int boardSize, int* boardColSize) {
    bool row[9][9] = {false};
    bool col[9][9] = {false};
    bool square[9][9] = {false};

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] != '.') {
                int num = board[i][j] - '1';
                int squareIndex = (i / 3) * 3 + (j / 3);

                if (row[i][num] || col[j][num] || square[squareIndex][num]) {
                    return (false);
                }
                row[i][num] = true;
                col[j][num] = true;
                square[squareIndex][num] = true;
            }
        }
    }
    return (true);
}