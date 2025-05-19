int jump(int* nums, int numsSize) {
    if (numsSize == 1)
        return (0);
    int jumps = 0;
    int current_end = 0;
    int farthest = 0;

    for (int i = 0; i < numsSize - 1; i++) {
        farthest = (i + nums[i] > farthest) ? i + nums[i] : farthest;

        if (i == current_end) {
            jumps++;
            current_end = farthest;

            if (current_end >= numsSize - 1) {
                break;
            }
        }
    }
    return (jumps);
}