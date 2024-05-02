#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Anagram Words - checks if 2 words are anagrams */

void sortString(char *word1);
int isAnagram(char* word1, char* word2);

void sortString(char *word1) {
    char tempWord;
    int i, j;

    // sort characters of word1 in alphabetical order
    for (i = 0; i < strlen(word1) - 1; i++) {
        for (j = i + 1; j < strlen(word1); j++) {
            if (word1[i] > word1[j]) {
                tempWord = word1[i];
                word1[i] = word1[j];
                word1[j] = tempWord;
            }
        }
    }
}

int isAnagram(char* word1, char* word2) {
    int isAnagram = 0;

    // check for their lengths.
    if (strlen(word1) == strlen(word2)) {
        // copy the originals into new variables
        char sortedWord1[50];
        char sortedWord2[50];
        strcpy(sortedWord1, word1);
        strcpy(sortedWord2, word2);
        // sort the copies
        sortString(sortedWord1);
        sortString(sortedWord2);
        // compare the sorted copies
        if (strcmp(sortedWord1, sortedWord2) == 0) {
            // if they are equal then they are anagrams
            isAnagram = 1;
        }
    }
    // if lengths are not equal, isAnagram stays at 0
    return isAnagram;
}

int main () {
    char word1[50];
    char word2[50];
    char choice;

    do {
        printf("Please enter first word: ");
        scanf("%s", word1);
        printf("Please enter the second word: ");
        scanf("%s", word2);

        if (isAnagram(word1, word2)) {
            printf("Yes! %s and %s are anagrams.\n", word1, word2);
        } else {
            printf("Sorry! %s and %s are not anagrams.\n", word1, word2);
        }

        printf("Do you want to run another test? (Y/N): ");
        scanf(" %c", &choice); // Adjusted to skip whitespace and read the character

        // Check if choice is neither 'Y' nor 'N'
        while (choice != 'Y' && choice != 'N') {
            printf("Invalid choice. Please enter 'Y' or 'N': ");
            scanf(" %c", &choice);
        }
    } while (choice != 'N');

    printf("\nThanks for using the Anagram Checker! See you later.\n");

    return 0;
}
