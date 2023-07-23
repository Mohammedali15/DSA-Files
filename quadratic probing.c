#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 100

typedef struct {
    char word[50];
} Entry;

Entry dictionary[TABLE_SIZE];

int hash(char* word) {
    int sum = 0;
    for (int i = 0; i < strlen(word); i++) {
        sum += word[i];
    }
    return sum % TABLE_SIZE;
}

void ins(char* word) {
    int index = hash(word);
    int i = 1;

    while (dictionary[index].word[0] != '\0') {
        index = (index + i * i) % TABLE_SIZE;
        i++;
    }

    strcpy(dictionary[index].word, word);
}

int srch(char* word) {
    int index = hash(word);
    int i = 1;

    while (strcmp(dictionary[index].word, word) != 0) {
        if (dictionary[index].word[0] == '\0') {
            return 0;
        }
        index = (index + i * i) % TABLE_SIZE;
        i++;
    }

    return 1;
}

int main() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        dictionary[i].word[0] = '\0';
    }

    int numWords;
    printf("Enter the number of words in the dictionary: ");
    scanf("%d", &numWords);

    printf("Enter the words:\n");
    for (int i = 0; i < numWords; i++) {
        char word[50];
        scanf("%s", word);
        ins(word);
    }

    char searchWord[50];
    printf("Enter a word to search: ");
    scanf("%s", searchWord);

    int searchResult = srch(searchWord);
    if (searchResult) {
        printf("Word found in the dictionary.\n");
    } else {
        printf("Word not found in the dictionary.\n");
    }

    return 0;
}

