/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
const char *mapping[] = {
    "",
    "",
    "abc",
    "def",
    "ghi",
    "jkl",
    "mno",
    "pqrs",
    "tuv",
    "wxyz"
};

void backtrack(char **result, int *returnSize, char *combination, const char *digits, int index) {
    if (digits[index] == '\0') {
        result[*returnSize] = strdup(combination);
        (*returnSize)++;
        return;
    }
    int digit = digits[index] - '0';
    const char *letters = mapping[digit];
    for (int i = 0; letters[i] != '\0'; i++) {
        combination[index] = letters[i];
        backtrack(result, returnSize, combination, digits, index + 1);
    }
}

char** letterCombinations(char* digits, int* returnSize) {
    *returnSize = 0;
    if (digits[0] == '\0')
        return NULL;
    
    int maxLen = 1;
    for (int i = 0; digits[i]; i++) {
        int digit = digits[i] - '0';
        int len = strlen(mapping[digit]);
        maxLen *= len;
    }
    char **result = malloc(maxLen * sizeof(char *));
    char *combination = malloc(strlen(digits) + 1);
    combination[strlen(digits)] = '\0';

    backtrack(result, returnSize, combination, digits, 0);
    free(combination);
    return (result);
}