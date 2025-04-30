#include <limits.h>
#include <stdlib.h>

int divide(int dividend, int divisor) {
    // Handle overflow case
    if (dividend == INT_MIN && divisor == -1)
        return INT_MAX;

    // Convert to long long to avoid overflow on abs(INT_MIN)
    long long ldividend = llabs((long long)dividend);
    long long ldivisor = llabs((long long)divisor);

    // Determine the sign of the result
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

    // Clamp result to 32-bit signed int range
    if (result > INT_MAX) return INT_MAX;
    if (result < INT_MIN) return INT_MIN;

    return (int)result;
}
