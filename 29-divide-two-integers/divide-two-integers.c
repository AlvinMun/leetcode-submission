int divide(int dividend, int divisor) {
    if (dividend == INT_MIN && divisor == -1)
        return INT_MAX;

    long long ldividend = llabs((long long)dividend);
    long long ldivisor = llabs((long long)divisor);

    int negative = (dividend < 0) ^ (divisor < 0);

    long long result = 0;

    while (ldividend >= ldivisor) {
        long long temp = ldivisor, multiple = 1;
        while (ldividend >= (temp << 1)) {
            temp <<= 1;
            multiple <<= 1;
        }
        ldividend -= temp;
        result += multiple;
    }

    result = negative ? -result : result;


    if (result > INT_MAX) return INT_MAX;
    if (result < INT_MIN) return INT_MIN;

    return (int)result;
}
