/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void backtrack(int *nums, int numsSize, int *path, int depth, int *used, int **result, int *returnSize, int **returnColumnSizes) {
    if (depth == numsSize) {
        result[*returnSize] = malloc(numsSize * sizeof(int));
        for (int i = 0; i < numsSize; i++) {
            result[*returnSize][i] = path[i];
        }
        (*returnColumnSizes)[*returnSize] = numsSize;
        (*returnSize)++;
        return;
    }
    for (int i = 0; i < numsSize; i++) {
        if (!used[i]) {
            used[i] = 1;
            path[depth] = nums[i];
            backtrack(nums, numsSize, path, depth + 1, used, result, returnSize, returnColumnSizes);
            used[i] = 0;
        }
    }
}

int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int maxPerms = 1;
    for (int i = 2; i <= numsSize; i++)
        maxPerms *= i;
    int **result = malloc(maxPerms * sizeof(int *));
    *returnColumnSizes = malloc(maxPerms * sizeof(int));
    *returnSize = 0;

    int *path = malloc(numsSize * sizeof(int));
    int *used = calloc(numsSize, sizeof(int));

    backtrack(nums, numsSize, path, 0, used, result, returnSize, returnColumnSizes);

    free(path);
    free(used);
    return (result);
}