/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct {
    char *key;
    int count;
} WordCount;

int findInMap(WordCount *map, int size, const char *word) {
    for (int i = 0; i < size; i++) {
        if (strcmp(map[i].key, word) == 0) {
            return (i);
        }
    }
    return (-1);
}

int* findSubstring(char* s, char** words, int wordsSize, int* returnSize) {
    *returnSize = 0;
    if (!s || !words || wordsSize == 0)
        return NULL;
    int wordLen = strlen(words[0]);
    int totalLen = wordLen * wordsSize;
    int stringLen = strlen(s);

    if (stringLen < totalLen)
        return NULL;

    WordCount *wordMap = malloc(sizeof(WordCount) * wordsSize);
    int mapSize = 0;
    for (int i = 0; i < wordsSize; i++) {
        int index = findInMap(wordMap, mapSize, words[i]);
        if (index != -1) {
            wordMap[index].count++;
        } else {
            wordMap[mapSize].key = words[i];
            wordMap[mapSize].count = 1;
            mapSize++;
        }
    }
    int *result = malloc(sizeof(int) * (stringLen - totalLen + 1));
    for (int i = 0; i <= stringLen - totalLen; i++) {
        WordCount *seen = malloc(sizeof(WordCount) * wordsSize);
        for (int j = 0; j < mapSize; j++) {
            seen[j].key = wordMap[j].key;
            seen[j].count = 0;
        }
        int k;
        for (k = 0; k < wordsSize; k++) {
            char word[wordLen + 1];
            strncpy(word, s + i + k * wordLen, wordLen);
            word[wordLen] = '\0';

            int index = findInMap(wordMap, mapSize, word);
            if (index == -1)
                break;
            seen[index].count++;
            if (seen[index].count > wordMap[index].count) {
            break;
            }
        }
        if (k == wordsSize) {
            result[*returnSize] = i;
            (*returnSize)++;
        }
        free(seen);
    }
    free(wordMap);
    return (result);
}