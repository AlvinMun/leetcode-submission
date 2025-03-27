int lengthOfLongestSubstring(char *s) {
    int n = strlen(s);
    int charset[128];
    for (int i = 0; i < 128; i++)
        charset[i] = -1;

    int left = 0;
    int maxLength = 0;
    for (int right = 0; right < n; right++) {
        if (charset[s[right]] >= left) {
            left = charset[s[right]] + 1;
    }
    charset[s[right]] = right;
    maxLength = (right - left + 1) > maxLength ? (right - left + 1) : maxLength;
    }
    return (maxLength);
}