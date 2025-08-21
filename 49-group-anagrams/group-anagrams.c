/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int cmpChar(const void *a, const void *b) {
    return (*(char *)a - *(char *)b);
}

char *sortString(const char *str) {
    char *s = strdup(str);
    qsort(s, strlen(s), sizeof(char), cmpChar);
    return (s);
}

typedef struct {
    char * key;
    char **group;
    int size;
    int capacity;
} HashEntry;

char ***groupAnagrams(char** strs, int strsSize, int* returnSize, int** returnColumnSizes) {
    if (strsSize == 0) {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return (NULL);
    }

    HashEntry *map = (HashEntry *)calloc(strsSize, sizeof(HashEntry));
    int mapSize = 0;

    for (int i = 0; i < strsSize; i++) {
        char *key = sortString(strs[i]);

        int found = -1;
        for (int j = 0; j < mapSize; j++) {
            if (strcmp(map[j].key, key) == 0) {
                found = j;
                break;
            } 
        }

        if (found == -1) {
            map[mapSize].key = key;
            map[mapSize].capacity = 8;
            map[mapSize].size = 0;
            map[mapSize].group = (char **)malloc(map[mapSize].capacity * sizeof(char *));
            found = mapSize;
            mapSize++;
        } else {
            free(key);
        }

        if (map[found].size == map[found].capacity) {
            map[found].capacity *= 2;
            map[found].group = (char **)realloc(map[found].group, map[found].capacity * sizeof(char *));
        }
        map[found].group[map[found].size++] = strs[i];
    }

    char ***res = (char ***)malloc(mapSize * sizeof(char **));
    *returnColumnSizes = (int *)malloc(mapSize * sizeof(int));
    *returnSize = mapSize;

    for (int i = 0; i < mapSize; i++) {
        res[i] = map[i].group;
        (*returnColumnSizes)[i] = map[i].size;
        free(map[i].key);
    }
    free(map);
    return (res);
}