bool isMatchRecursive(char *s, char *p, int i, int j, int m, int n, int **memo) {
    if (i > m || j > n) return false;  // Bounds check
    if (memo[i][j] != -1) {
        return memo[i][j] == 1;
    }
    bool result = false;
    if (p[j] == '\0') {
        result = (s[i] == '\0');
    } else if (j + 1 < n && p[j + 1] == '*') {  // Check j+1 before accessing
        result = isMatchRecursive(s, p, i, j + 2, m, n, memo) ||
                (i < m && (s[i] == p[j] || p[j] == '.') && isMatchRecursive(s, p, i + 1, j, m, n, memo));
    } else if (i < m && (s[i] == p[j] || p[j] == '.')) {
        result = isMatchRecursive(s, p, i + 1, j + 1, m, n, memo);
    }
    memo[i][j] = (int)result;
    return result;
}

bool isMatch(char *s, char *p) {
    int m = strlen(s);
    int n = strlen(p);

    // Allocate memo[m+1][n+1]
    int **memo = (int **)malloc((m + 1) * sizeof(int *));
    for (int i = 0; i <= m; i++) {
        memo[i] = (int *)malloc((n + 1) * sizeof(int));
        for (int j = 0; j <= n; j++) {
            memo[i][j] = -1;
        }
    }

    bool result = isMatchRecursive(s, p, 0, 0, m, n, memo);

    // Free memory
    for (int i = 0; i <= m; i++) {
        free(memo[i]);
    }
    free(memo);

    return result;
}