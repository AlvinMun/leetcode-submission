/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void backtrack(char ***res, int *returnSize, int *capacity, char *current, int open, int close, int max) {
    if (strlen(current) == max * 2) {
        if (*returnSize >= *capacity) {
            *capacity *= 2;
            *res = realloc(*res, (*capacity) * sizeof(char *));
        }
        (*res)[*returnSize] = strdup(current);
        (*returnSize)++;
        return;
    }

    if (open < max) {
        current[strlen(current)] = '(';
        backtrack(res, returnSize, capacity, current, open + 1, close, max);
        current[strlen(current) - 1] = '\0';
    }
    if (close < open) {
        current[strlen(current)] = ')';
        backtrack(res, returnSize, capacity, current, open, close + 1, max);
        current[strlen(current) - 1] = '\0';
    }
}

char** generateParenthesis(int n, int* returnSize) {
    int capacity = 100;
    char **res = malloc(capacity * sizeof(char *));
    *returnSize = 0;

    char *current = calloc(2 * n + 1, sizeof(char));
    backtrack(&res, returnSize, &capacity, current, 0, 0, n);
    free(current);
    return res;
}