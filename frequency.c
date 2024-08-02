#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFreq;

void to_lower_case(char* str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

int main() {
    char paragraph[10000];
    WordFreq word_freq[MAX_WORDS];
    int word_count = 0;

    printf("Enter a paragraph: ");
    fgets(paragraph, sizeof(paragraph), stdin);

    char *token = strtok(paragraph, " ,.-\n");

    while (token != NULL) {
        to_lower_case(token);

        int found = 0;
        for (int i = 0; i < word_count; i++) {
            if (strcmp(word_freq[i].word, token) == 0) {
                word_freq[i].count++;
                found = 1;
                break;
            }
        }

        if (!found && word_count < MAX_WORDS) {
            strcpy(word_freq[word_count].word, token);
            word_freq[word_count].count = 1;
            word_count++;
        }

        token = strtok(NULL, " ,.-\n");
    }

    printf("\nWord frequencies:\n");
    for (int i = 0; i < word_count; i++) {
        printf("%s: %d\n", word_freq[i].word, word_freq[i].count);
    }

    return 0;
}
