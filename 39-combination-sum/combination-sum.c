/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

void backtrack(int *candidates, int candidatesSize, int target, int **result, int *returnSize, int **returnColumnSizes, int *combination, int combSize, int start) {
    if (target == 0) {
        int *newComb = malloc(combSize *sizeof(int));
        for (int i = 0; i < combSize; i++) {
            newComb[i] = combination[i];
        }
        result[*returnSize] = newComb;
        (*returnColumnSizes)[*returnSize] = combSize;
        (*returnSize)++;
        return;
    }
    for (int i = start; i < candidatesSize; i++) {
        if (candidates[i] <= target) {
            combination[combSize] = candidates[i];
            backtrack(candidates, candidatesSize, target - candidates[i], result, returnSize, returnColumnSizes, combination, combSize + 1, i);
        }
    }
}

int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes) {
    int **result = malloc(150 * sizeof(int *));
    *returnColumnSizes = malloc(150 * sizeof(int));
    int *combination = malloc(target * sizeof(int));
    *returnSize = 0;
    backtrack(candidates, candidatesSize, target, result, returnSize, returnColumnSizes, combination, 0, 0);
    free(combination);
    return (result);
}