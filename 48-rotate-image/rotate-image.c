void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void transpose(int **matrix, int len) {
    for (int i = 0; i < len; i++) {
        for (int j = i; j < len; j++) {
            swap(&matrix[i][j], &matrix[j][i]);
        }
    }
}

void changeCols(int **matrix, int len) {
    for (int i = 0; i < len; i++) {
        if (len % 2 == 0) {
            for (int j = 0; j < len / 2; j++) {
                swap(&matrix[i][j], &matrix[i][len - j - 1]);
            }
        } else {
            for (int j = 0; j < (len / 2) + 1; j++) {
                swap(&matrix[i][j], &matrix[i][len - j - 1]);
            }
        }
    }
}

void rotate(int **matrix, int matrixSize, int *matrixColSize) {
    transpose(matrix, matrixSize);
    changeCols(matrix, matrixSize);
}