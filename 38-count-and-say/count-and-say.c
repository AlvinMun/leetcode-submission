char* countAndSay(int n) {
    if (n == 1)
        return strdup("1");

    char *prev = countAndSay(n - 1);
    int len = strlen(prev);
    char *result = malloc(2 * len + 1);
    int count = 1;
    int pos = 0;

    for (int i = 1; i <= len; i++) {
        if (i < len && prev[i] == prev[i - 1]) {
            count++;
        } else {
            pos += sprintf(result + pos, "%d%c", count, prev[i - 1]);
            count = 1;
        }
    }
    free(prev);
    result[pos] = '\0';
    return (result);
}