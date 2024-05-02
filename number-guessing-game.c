#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h> 

/* Number Guessing Game - computer chooses a random number between 1-100 and you have 10 guesses to get it. */

int random_range(int min, int max) {
    srand(time(NULL));
    return rand() % (max - min + 1) + min; // to generate numbers within the specified range
}

int main() {
    int number;
    int min = 1;
    int max = 100;
    int i;
    const int maxGuess = 10;
    int guess;
    char choice;

    printf("Welcome to the Number Guess Game!\nI choose a number between %d and %d and you have only 10 chances to guess it!\n", min, max);

    do {
        printf("Okay, I made up my mind.\n");
        number = random_range(min, max);

        for (i = 1; i <= maxGuess; i++) {
            printf("What is your guess? > ");
            scanf("%d", &guess);

            if (guess < min || guess > max) { // Check if guess is outside the range
                printf("Your guess is outside the valid range of %d to %d. Please try again.\n", min, max);
                continue;
            }

            if (guess < number) {
                printf("My number is larger than %d!\n", guess);
            } else if (guess > number) {
                printf("My number is smaller than %d!\n", guess);
            } else {
                printf("\nYou did it! My number is %d!\n", guess);
                printf("You found it with just %d guesses.\n", i);

                printf("Do you want to play again? (Y/N) > ");
                getchar();
                scanf(" %c", &choice); // skips whitespace and read the character

                // Check if choice is neither 'Y' nor 'N'
                while (choice != 'Y' && choice != 'N') {
                    printf("Invalid choice. Please enter 'Y' or 'N': ");
                    scanf(" %c", &choice);
                }

                break;
            }

            printf("%d guesses left.\n", (maxGuess - i));
        }

        if (i >= maxGuess) {
            printf("SORRY! You couldn't find it with %d guesses!\n", maxGuess);
            printf("My number was %d. Maybe next time!\n", number);

            printf("Do you want to play again? (Y/N) > ");
            getchar();
            scanf(" %c", &choice); // skips whitespace and read the character

            // Check if choice is neither 'Y' nor 'N'
            while (choice != 'Y' && choice != 'N') {
                printf("Invalid choice. Please enter 'Y' or 'N': ");
                scanf(" %c", &choice);
            }
        }
    } while (toupper(choice) != 'N'); 

    printf("\nThanks for playing! See you later.\n");

    return 0;
}
