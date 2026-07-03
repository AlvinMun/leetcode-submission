/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

char ***result;
int resultSize;
int *returnColumnSizes;
int *queens;
int nGlobal;

int isSafe(int row, int col) {
    for (int prevRow = 0; prevRow < row; prevRow++) {
        int prevCol = queens[prevRow];
        
        if (prevCol == col) return 0;
        if (abs(prevRow - row) == abs(prevCol - col)) return 0;
    }
    return 1;
}

char **createBoard(int n) {
    char **board = malloc(sizeof(char *) * n);

    for (int i = 0; i < n; i++) {
        board[i] = malloc(sizeof(char) * (n + 1));

        for (int j = 0; j < n; j++) {
            board[i][j] = '.';
        }

        board[i][queens[i]] = 'Q';
        board[i][n] = '\0';
    }
    return board;
}

void backtrack(int row, int n) {
    if (row == n) {
        result[resultSize] = createBoard(n);
        returnColumnSizes[resultSize] = n;
        resultSize++;
        return;
    }
    for (int col = 0; col < n; col++) {
        if (isSafe(row, col)) {
            queens[row] = col;
            backtrack(row + 1, n);
        }
    }
}

char*** solveNQueens(int n, int* returnSize, int** returnColumnSizesPtr) {
    result = malloc(sizeof(char **) * 10000);
    returnColumnSizes = malloc(sizeof(int) * 10000);
    queens = malloc(sizeof(int) * n);

    resultSize = 0;
    nGlobal = n;

    backtrack(0, n);
    *returnSize = resultSize;
    *returnColumnSizesPtr = returnColumnSizes;

    free(queens);
    return result;
}