
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_WORDS 100000
#define WORD_LENGTH 50

char dictionary[MAX_WORDS][WORD_LENGTH];
int dictSize = 0;

void toLowerCase(char *word) {
    for (int i = 0; word[i]; i++)
        word[i] = tolower(word[i]);
}

int isSpelledCorrectly(char *word) {
    toLowerCase(word);
    for (int i = 0; i < dictSize; i++) {
        if (strcmp(word, dictionary[i]) == 0)
            return 1;
    }
    return 0;
}

void loadDictionary(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Dictionary file not found!\n");
        exit(1);
    }
    while (fgets(dictionary[dictSize], WORD_LENGTH, file)) {
        dictionary[dictSize][strcspn(dictionary[dictSize], "\n")] = 0;
        dictSize++;
        if (dictSize >= MAX_WORDS) break;
    }
    fclose(file);
}

int main() {
    char typedText[1000];
    char word[100];
    time_t startTime, endTime;
    double timeTaken;
    int totalWords = 0, errorWords = 0;

    loadDictionary("words.txt");

    printf("=========================================\n");
    printf("         TYPING TEST + SPELL CHECK       \n");
    printf("=========================================\n");
    printf("Type anything you want (press ENTER to finish):\n");

    startTime = time(NULL);
    fgets(typedText, sizeof(typedText), stdin);
    endTime = time(NULL);
    timeTaken = difftime(endTime, startTime);

    char *token = strtok(typedText, " ,.-\n");
    while (token != NULL) {
        strcpy(word, token);
        totalWords++;

        if (!isSpelledCorrectly(word))
            errorWords++;

        token = strtok(NULL, " ,.-\n");
    }

    double accuracy = ((double)(totalWords - errorWords) / totalWords) * 100.0;
    double wpm = (double)totalWords / (timeTaken / 60.0);

    printf("\n=========================================\n");
    printf("                RESULTS                  \n");
    printf("=========================================\n");
    printf("Time taken: %.2f seconds\n", timeTaken);
    printf("Total words typed: %d\n", totalWords);
    printf("Misspelled words: %d\n", errorWords);
    printf("Accuracy: %.2f%%\n", accuracy);
    printf("Words Per Minute (WPM): %.2f\n", wpm);
    printf("=========================================\n");

    return 0;
}
