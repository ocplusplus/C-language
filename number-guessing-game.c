#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Number Guessing Game - computer chooses a random number between 1-100 and you have 10 guesses to get it. */

int random_range(int min, int max) //random number generator function
{
    srand(time(NULL));
    return rand()% 100 + 1;
}

int main()
{
    int number;
    int min = 1; //lowest possible number
    int max = 100; //highest possible number
    int i;
    const int maxGuess = 10; //maximum number of guesses
    int guess; //guess
    char choice; //Y/N choice
    printf("Welcome to the Number Guess Game!\nI choose a number between %d and %d and you have only 10 chances to guess it!\n", min, max);
    do
    {
        printf("Okay, I made up my mind.\n");
        number = random_range(min, max);
        for(i = 1;i <=maxGuess;i++)
        {
            printf("What is your guess? >");
            scanf("%d",&guess);
            if(guess < number)//if guess is smaller than number
            {
                printf("My number is larger than %d!\n",guess);
            }
            else if(guess > number)//if guess is larger than number
            {
                printf("My number is smaller than %d!\n",guess);
            }
            else//guess is correct
            {
                printf("\nYou did it! My number is %d!",guess);
                printf("\nYou found it with just %d guesses.",i);
                printf("\nDo you want to play again?(Y/N) >");
                getchar();
                scanf("%c",&choice);
                break;
            }
            printf("%d guesses left.\n",(maxGuess-i));//number of guesses remaining
        }
       if(i>=maxGuess)//if the user runs out of guesses
       {
           printf("SORRY! You couldn't find it with %d guesses!\n",maxGuess);
           printf("My number was %d. Maybe next time!\n",number);
           printf("Do you want to play again?(Y/N)");
           getchar();
           scanf("%c",&choice);
       }

    }while(choice!='N');//when user selects N(no) to stop playing
    printf("\nThanks for playing! See you later.");

}
