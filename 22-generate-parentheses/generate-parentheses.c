/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void backtrack(char ***res, int *returnSize, char *current, int open, int close, int max) {
    int len = strlen(current);
    if (len == 2 * max) {
        (*returnSize)++;
        *res = realloc(*res, (*returnSize) * sizeof(char*));
        (*res)[*returnSize - 1] = malloc((2 * max + 1) * sizeof(char));
        strcpy((*res)[*returnSize - 1], current);
        return;
    }
    
    if (open < max) {
        current[len] = '(';
        current[len + 1] = '\0';
        backtrack(res, returnSize, current, open + 1, close, max);
        current[len] = '\0';
    }
    if (close < open) {
        current[len] = ')';
        current[len + 1] = '\0';
        backtrack(res, returnSize, current, open, close + 1, max);
        current[len] = '\0';
    }
}

char** generateParenthesis(int n, int* returnSize) {
    *returnSize = 0;
    char **res = NULL;
    char *current = calloc((2 * n + 1), sizeof(char));
    backtrack(&res, returnSize, current, 0, 0, n);
    free(current);
    return res;
}