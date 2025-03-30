char *longestPalindrome(char *s) {
    int n = strlen(s);
    if (n == 0)
        return "";
    bool dp[n][n];
    memset(dp, false, sizeof dp);
    int result[2] = {0, 0};

    //for single character substring
    for (int i = 0; i < n; i++) {
        dp[i][i] = true;
    }

    //for 2-character substring
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == s[i + 1]) {
            dp[i][i + 1] = true;
            result[0] = i;
            result[1] = i + 1;
        } else {
            dp[i][i + 1] = false;
        }
    }

    //for 3-character substring or more
    for (int diff = 2; diff < n; diff++) {
        for (int i = 0; i < n - diff; i++) {
            int j = i + diff; //since diff = j - i
            if (s[i] == s[j] && dp[i + 1][j - 1]) {
                dp[i][j] = true;
                result[0] = i;
                result[1] = j;
            } else {
                dp[i][j] = false;
            }
        }
    }
    s[result[1] + 1] = '\0';
    return s + result[0];
}