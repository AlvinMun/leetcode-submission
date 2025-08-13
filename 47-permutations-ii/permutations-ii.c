/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

void backtrack(int *nums, int numsSize, bool *used, int *curr, int depth, int ***res, int *resultsSize, int **colSizes) {
    if (depth == numsSize) {
        int *perm = (int *)malloc(numsSize * sizeof(int));
        for (int i = 0; i < numsSize; i++)
            perm[i] = curr[i];

        (*res)[*resultsSize] = perm;
        (*colSizes)[*resultsSize] = numsSize;
        (*resultsSize)++;
        return;
    }
    for (int i = 0; i < numsSize; i++) {
        if (used[i])
            continue;
        if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1])
            continue;
        
        used[i] = true;
        curr[depth] = nums[i];
        backtrack(nums, numsSize, used, curr, depth + 1, res, resultsSize, colSizes);
        used[i] = false;
    }
}

int** permuteUnique(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    qsort(nums, numsSize, sizeof(int), compare);

    int maxPerms = 1;
    for (int i = 2; i <= numsSize; i++) {
        maxPerms *= i;
    }
    
    int **res = (int **)malloc(maxPerms * sizeof(int *));
    *returnColumnSizes = (int *)malloc(maxPerms * sizeof(int));
    bool *used = (bool *)calloc(numsSize, sizeof(bool));
    int *curr = (int *)malloc(numsSize * sizeof(int));
    *returnSize = 0;

    backtrack(nums, numsSize, used, curr, 0, &res, returnSize, returnColumnSizes);

    free(used);
    free(curr);
    return (res);
}