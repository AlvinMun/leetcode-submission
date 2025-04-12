/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int** threeSum(int *nums, int numsSize, int *returnSize, int **returnColumnSizes) {
    qsort(nums, numsSize, sizeof(int), compare);

    int **res = malloc(100 * sizeof(int *));
    *returnColumnSizes = malloc(100 * sizeof(int));
    *returnSize = 0;
    int capacity = 100;

    for (int i = 0; i < numsSize - 2; i++) {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        int left = i + 1;
        int right = numsSize - 1;

        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];

            if (sum < 0) {
                left++;
            } else if (sum > 0) {
                right--;
            } else {
                if (*returnSize == capacity) {
                    capacity *= 2;
                    res = realloc(res, capacity * sizeof(int *));
                    *returnColumnSizes = realloc(*returnColumnSizes, capacity * sizeof(int));
                }

                res[*returnSize] = malloc(3 * sizeof(int));
                res[*returnSize][0] = nums[i];
                res[*returnSize][1] = nums[left];
                res[*returnSize][2] = nums[right];
                (*returnColumnSizes)[*returnSize] = 3;
                (*returnSize)++;

                while (left < right && nums[left] == nums[left + 1])
                    left++;
                while (left < right && nums[right] == nums[right - 1])
                    right--;

                left++;
                right--;
            }
        }
    }

    return res;
}

