static int is_safe(int board[], int row, int col) {
    int i;
    i = 0;
    while (i < row) {
        if (board[i] == col)
            return (0);
        if (abs(board[i] - col) == abs(i - row))
            return (0);

        i++;
    }
    return (1);
}


static void solve(int board[], int row, int n, int *count) {
    int col;

    if (row == n){
        (*count)++;
        return;
    }
    col = 0;
    while (col < n) {
        if (is_safe(board, row, col))
        {
            board[row] = col;
            solve(board, row + 1, n, count);
        }
        col++;
    }
}

int totalNQueens(int n) {
    int board[9];
    int count;

    count = 0;
    solve(board, 0, n, &count);
    return (count);
}