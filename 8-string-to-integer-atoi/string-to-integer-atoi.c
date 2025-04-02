int myAtoi(char* s) {
    int i;
    int sign;
    long result;

    i = 0;
    sign = 1;
    result = 0;
    while (s[i] == ' ' || (s[i] >= 9 && s[i] <= 13)) {
        i++;
    }
    while (s[i] == '+' || s[i] == '-') {
        sign = (s[i] == '-') ? -1 : 1;
        i++;

        if (s[i] < '0' || s[i] > '9')
            return (0);
    }
    while (s[i] >= '0' && s[i] <= '9') {
        result = result * 10 + (s[i] - '0');

        if (result * sign > INT_MAX)
            return (INT_MAX);
        if (result * sign < INT_MIN)
            return (INT_MIN);
        i++;
    }
    return (result * sign);
}