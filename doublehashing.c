/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_NODES 5

typedef struct {
    char task[50];
    int node;
} Task;

int hash1(char* task) {
    int sum = 0;
    for (int i = 0; i < strlen(task); i++) {
        sum += task[i];
    }
    return sum % NUM_NODES;
}

int hash2(char* task) {
    int sum = 0;
    for (int i = 0; i < strlen(task); i++) {
        sum += task[i] * (i + 1);
    }
    return sum % NUM_NODES;
}

int assignNode(char* task) {
    int hashVal1 = hash1(task);
    int hashVal2 = hash2(task);
    int node = hashVal1;

    while (1) {
        if (node == hashVal1 || node == hashVal2) {
            return node;
        }
        node = (node + 1) % NUM_NODES;
    }
}

int main() {
    Task tasks[] = {
        {"Task 1", -1},
        {"Task 2", -1},
        {"Task 3", -1},
        {"Task 4", -1},
        {"Task 5", -1}
    };

    for (int i = 0; i < sizeof(tasks) / sizeof(Task); i++) {
        tasks[i].node = assignNode(tasks[i].task);
    }

    for (int i = 0; i < sizeof(tasks) / sizeof(Task); i++) {
        printf("Assigned Node for %s: Node %d\n", tasks[i].task, tasks[i].node);
    }

    return 0;
}
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10
#define MAX_KICKS 5

typedef struct {
    char key[50];
    int value;
} Entry;

Entry table1[TABLE_SIZE];
Entry table2[TABLE_SIZE];

int hash1(char* key) {
    int sum = 0;
    for (int i = 0; i < strlen(key); i++) {
        sum += key[i];
    }
    return sum % TABLE_SIZE;
}

int hash2(char* key) {
    int sum = 0;
    for (int i = 0; i < strlen(key); i++) {
        sum += key[i] * (i + 1);
    }
    return sum % TABLE_SIZE;
}

void insertEntry(char* key, int value) {
    int hashVal1 = hash1(key);
    int hashVal2 = hash2(key);

    Entry newEntry;
    strcpy(newEntry.key, key);
    newEntry.value = value;

    Entry tempEntry;
    int numKicks = 0;

    while (numKicks < MAX_KICKS) {
        if (table1[hashVal1].value == -1) {
            table1[hashVal1] = newEntry;
            return;
        } else {
            tempEntry = table1[hashVal1];
            table1[hashVal1] = newEntry;
            newEntry = tempEntry;

            hashVal2 = hash2(newEntry.key);
            if (table2[hashVal2].value == -1) {
                table2[hashVal2] = newEntry;
                return;
            } else {
                tempEntry = table2[hashVal2];
                table2[hashVal2] = newEntry;
                newEntry = tempEntry;

                hashVal1 = hash1(newEntry.key);
            }
        }
        numKicks++;
    }

    printf("Insertion failed: Maximum number of kicks reached.\n");
}

int searchValue(char* key) {
    int hashVal1 = hash1(key);
    int hashVal2 = hash2(key);

    if (table1[hashVal1].value != -1 && strcmp(table1[hashVal1].key, key) == 0) {
        return table1[hashVal1].value;
    } else if (table2[hashVal2].value != -1 && strcmp(table2[hashVal2].key, key) == 0) {
        return table2[hashVal2].value;
    } else {
        return -1;
    }
}

int main() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        table1[i].value = -1;
        table2[i].value = -1;
    }

    insertEntry("key1", 10);
    insertEntry("key2", 20);
    insertEntry("key3", 30);

    char searchKey[50];
    printf("Enter a key to search: ");
    scanf("%s", searchKey);

    int searchResult = searchValue(searchKey);
    if (searchResult != -1) {
        printf("Value: %d\n", searchResult);
    } else {
        printf("Key not found.\n");
    }

    return 0;
}

