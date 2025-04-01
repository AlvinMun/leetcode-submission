int reverse(int x) {
    int n = 0;
    while (x != 0) {
        int pop = x % 10;
        x /= 10;

        if (n > INT_MAX / 10 || (n == INT_MAX / 10 && pop > 7))
            return (0);
        if (n < INT_MIN / 10 || (n == INT_MIN / 10 && pop < -8))
            return (0);
        
        n = n * 10 + pop;
    }
    return (n);
}