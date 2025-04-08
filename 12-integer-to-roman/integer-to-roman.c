char *intToRoman(int num) {
    const char *symbols[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    const int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

    char *result = malloc(20 * sizeof(char));
    result[0] = '\0';

    for (int i = 0; i < 13 && num > 0; i++) {
        while (num >= values[i]) {
            strcat(result, symbols[i]);
            num -= values[i];
        }
    }
    return (result);
}