char* multiply(char* num1, char* num2) {
    int len1 = strlen(num1);
    int len2 = strlen(num2);

    if (strcmp(num1, "0") == 0 || strcmp(num2, "0") == 0)
        return ("0");

    int *res = calloc(len1 + len2, sizeof(int));
    for (int i = len1 - 1; i >= 0; i--) {
        for (int j = len2 - 1; j >= 0; j--) {
            int multiply = (num1[i] - '0') * (num2[j] - '0');
            int sum = multiply + res[i + j + 1];

            res[i + j + 1] = sum % 10;
            res[i + j] += sum / 10;
        }
    }
    int start = 0;
    while (start < len1 + len2 && res[start] == 0) {
        start++;
    }
    char *product = malloc((len1 + len2 - start + 1) * sizeof(char));
    int k = 0;
    for (int i = start; i < len1 + len2; i++) {
        product[k++] = res[i] + '0';
    }
    product[k] = '\0';
    free(res);
    return (product);
}