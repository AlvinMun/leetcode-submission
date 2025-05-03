int longestValidParentheses(char* s) {
    int maxLen = 0;
    int len = strlen(s);
    int stack[len + 1];
    int top = -1;

    stack[++top] = -1;
    for (int i = 0; i < len; i++) {
        if (s[i] == '(') {
            stack[++top] = i;
        } else {
            top--;
            if (top == -1) {
                stack[++top] = i;
            } else {
                int validLen = i - stack[top];
                if (validLen > maxLen)
                    maxLen = validLen;
            }
        }
    }
    return (maxLen);
}