int maxArea(int *height, int heightSize) {
    int max = 0;
    int left = 0;
    int right = heightSize - 1;
    while (left < right) {
        int h = height[left] < height[right] ? height[left] : height[right];
        int w = right - left;
        int area = h * w;
        
        if (area > max)
            max = area;

        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }
    return (max);
}