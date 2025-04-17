#define MAX_SIZE 10000
bool isValid(char* s) {
    char stack[MAX_SIZE];
    int top = -1;

    for (int i = 0; s[i] != '\0'; i++) {
        char c = s[i];
        if (c == '(' || c == '{' || c == '[') {
            if (top + 1 >= MAX_SIZE)
                return (false);
            stack[++top] = c;
        } else {
            if (top == -1)
                return (false);

            char topChar = stack[top --];
            if ((c == ')' && topChar != '(') || 
                (c == '}' && topChar != '{') || 
                (c == ']' && topChar != '[')) {
                    return (false);
                }
        }
    }
    return (top == -1);
}