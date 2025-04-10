int romanToInt(char* s) {
    int roman[128] = {0};
    roman['I'] = 1;
    roman['V'] = 5;
    roman['X'] = 10;
    roman['L'] = 50;
    roman['C'] = 100;
    roman['D'] = 500;
    roman['M'] = 1000;

    int res = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        int curr = roman[s[i]];
        int next = roman[s[i + 1]];

        if (curr < next)
            res -= curr;
        else
            res += curr;
    }
    return (res);
}