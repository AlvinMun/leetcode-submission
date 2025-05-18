bool isMatch(char* s, char* p) {
    int s_len = strlen(s);
    int p_len = strlen(p);
    int i, j = 0;
    int starIdx = -1;
    int match = 0;
    
    while (i < s_len) {
        if (j < p_len && (p[j] == '?' || p[j] == s[i])) {
            i++;
            j++;
        } else if (j < p_len && p[j] == '*') {
            starIdx = j;
            match = i;
            j++;
        } else if (starIdx != -1) {
            j = starIdx + 1;
            match++;
            i = match;
        } else {
            return (false);
        }
    }
    while (j < p_len && p[j] == '*') {
        j++;
    }
    return (j == p_len);
}