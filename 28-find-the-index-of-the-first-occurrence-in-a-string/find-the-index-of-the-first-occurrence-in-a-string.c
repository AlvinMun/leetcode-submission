int strStr(char* haystack, char* needle) {
    int i = 0;
    int j;
    if (needle[0] == '\0')
        return (*haystack);
    while (haystack[i] != '\0') {
        j = 0;
        while (haystack[i + j] != '\0' && haystack[i + j] == needle[j]) {
            if (needle[j + 1] == '\0')
                return (i);
                j++;
        }
        i++;
    }
    return (-1);
}