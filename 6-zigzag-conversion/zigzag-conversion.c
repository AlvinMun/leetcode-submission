char* convert(char* s, int numRows) {
    if (numRows == 1)
    return s;

    int len = strlen(s);
    char *result = malloc((len + 1) * sizeof(char));
    if (!result)
        return NULL;
    int index = 0;
    int increment = (numRows - 1) * 2;
    
    for (int i = 0; i < numRows; i++) {
        for (int j = i; j < len; j += increment) {
            result[index++] = s[j];
            int middle = j + increment - 2 * i;
            if (i != 0 && i != numRows - 1 && middle < len) {
                result[index++] = s[middle];
            }
        }
    }
    result[index] = '\0';
    return (result);
}