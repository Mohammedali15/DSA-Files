#include <stdio.h>
#include <string.h>

#define TABLE_SIZE 10

typedef struct {
    char key[50];
    int value;
} Entry;

Entry symbolTable[TABLE_SIZE];

int hash(char* key) {
    int sum = 0;
    for (int i = 0; i < strlen(key); i++) {
        sum += key[i];
    }
    return sum % TABLE_SIZE;
}

void insertEntry(char* key, int value) {
    int index = hash(key);

    while (symbolTable[index].value != -1) {
        index = (index + 1) % TABLE_SIZE;
    }

    strcpy(symbolTable[index].key, key);
    symbolTable[index].value = value;
}

int searchValue(char* key) {
    int index = hash(key);

    while (strcmp(symbolTable[index].key, key) != 0) {
        index = (index + 1) % TABLE_SIZE;
        if (symbolTable[index].value == -1) {
            return -1;
        }
    }

    return symbolTable[index].value;
}

int main() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        symbolTable[i].value = -1;
    }

    int numEntries;
    printf("Enter the number of entries to insert: ");
    scanf("%d", &numEntries);

    for (int i = 0; i < numEntries; i++) {
        char key[50];
        int value;

        printf("Enter key %d: ", i + 1);
        scanf("%s", key);

        printf("Enter value %d: ", i + 1);
        scanf("%d", &value);

        insertEntry(key, value);
    }

    char searchKey[50];
    printf("\nEnter a key to search: ");
    scanf("%s", searchKey);

    int searchResult = searchValue(searchKey);
    if (searchResult != -1) {
        printf("Value: %d\n", searchResult);
    } else {
        printf("Entry not found.\n");
    }

    return 0;
}

