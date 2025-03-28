double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int m = nums1Size;
    int n = nums2Size;
    int p1 = 0;
    int p2 = 0;
    int min() {
        if (p1 < m && p2 < n) {
            return (nums1[p1] < nums2[p2] ? nums1[p1++] : nums2[p2++]);
        } else if (p1 < m) {
            return nums1[p1++];
        } else if (p2 < n) {
            return nums2[p2++];
        }
        return (-1);
    }

    double median;
    if ((m + n) % 2 == 0) {
        for (int i = 0; i < ((m + n) / 2) - 1; i++) {
            int temp = min();
        }
        median = (min() + min()) / 2.0;
    } else {
        for (int i = 0; i < (m + n) / 2; i++) {
            int temp = min();
        }
        median = min();
    }
    return (median);
}