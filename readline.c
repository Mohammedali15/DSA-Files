#include <stdio.h>

#define MAX_LINES 10
#define MAX_LENGTH 100

int readLinesFromInput(char lines[MAX_LINES][MAX_LENGTH]) {
    int i;
    for (i = 0; i < MAX_LINES; i++) {
        printf("Enter line %d (or press enter to finish): ", i + 1);
        fgets(lines[i], MAX_LENGTH, stdin);
        if (lines[i][0] == '\n') {
            break;
        }
    }
    return i;
}

int readLinesFromFile(char lines[MAX_LINES][MAX_LENGTH], char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        return 0;
    }
    int i;
    for (i = 0; i < MAX_LINES; i++) {
        if (fgets(lines[i], MAX_LENGTH, file) == NULL) {
            break;
        }
    }
    fclose(file);
    return i;
}

int getLongestLine(char lines[MAX_LINES][MAX_LENGTH], int count) {
    int longestLength = 0;
    int longestIndex = -1;
    int i;
    for (i = 0; i < count; i++) {
        int length = 0;
        while (lines[i][length] != '\0' && lines[i][length] != '\n') {
            length++;
        }
        if (length > longestLength) {
            longestLength = length;
            longestIndex = i;
        }
    }
    return longestIndex;
}

int main() {
    char lines[MAX_LINES][MAX_LENGTH];
    int count = readLinesFromInput(lines);
    count += readLinesFromFile(lines + count, "input.txt");
    int longestIndex = getLongestLine(lines, count);
    if (longestIndex != -1) {
        printf("Longest line: %s", lines[longestIndex]);
    } else {
        printf("No lines read.\n");
    }
    return 0;
}

