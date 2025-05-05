/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int findFirst(int *nums, int numsSize, int target) {
    int left = 0;
    int right = numsSize - 1;
    int index = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] >= target) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
        if (nums[mid] == target)
            index = mid;
    }
    return (index);
}

int findLast(int *nums, int numsSize, int target) {
    int left = 0;
    int right = numsSize - 1;
    int index = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] <= target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
        if (nums[mid] == target)
            index = mid;
    }
    return (index);
}

int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    int *result = malloc(sizeof(int) * 2);
    result[0] = findFirst(nums, numsSize, target);
    result[1] = findLast(nums, numsSize, target);
    *returnSize = 2;
    return (result);
}