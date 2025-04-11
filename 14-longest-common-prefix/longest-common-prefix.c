char* longestCommonPrefix(char** strs, int strsSize) {
   if (strsSize == 0)
    return "";
    char *prefix = strs[0];
    for (int i = 1; i < strsSize; i++) {
        int j = 0;
        while (prefix[j] && strs[i][j] && prefix[j] == strs[i][j]) {
            j++;
        }
        prefix[j] = '\0';
        if (j == 0)
            return "";
    }
    return strdup(prefix);
}