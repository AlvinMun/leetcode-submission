/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

void backtrack(int *candidates, int candidatesSize, int target, int start, int *current, int currentSize, int **results, int *returnSize, int **returnColumnSizes) {
    if (target == 0) {
        results[*returnSize] = malloc(currentSize * sizeof(int *));
        for (int i = 0; i < currentSize; i++) {
            results[*returnSize][i] = current[i];
        }
        (*returnColumnSizes)[*returnSize] = currentSize;
        (*returnSize)++;
        return;
    }
    for (int i = start; i < candidatesSize; i++) {
        if (i > start && candidates[i] == candidates[i - 1])
            continue;
        if (candidates[i] > target)
            break;
        current[currentSize] = candidates[i];
        backtrack(candidates, candidatesSize, target - candidates[i], i + 1, current, currentSize + 1, results, returnSize, returnColumnSizes);
    }
}

int** combinationSum2(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes) {
    qsort(candidates, candidatesSize, sizeof(int), compare);
    int **results = malloc(1000 * sizeof(int *));
    *returnColumnSizes = malloc(1000 * sizeof(int));
    *returnSize = 0;
    int *current = malloc(candidatesSize * sizeof(int));
    backtrack(candidates, candidatesSize, target, 0, current, 0, results, returnSize, returnColumnSizes);
    free(current);
    return (results);
}