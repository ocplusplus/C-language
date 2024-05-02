#include <stdio.h>
#include <stdlib.h>

/* Prime Number - if integer is larger than 1 it prints out all the prime numbers smaller and equal to it */

void printPrime (unsigned long int number)

{
    int divisorCount = 0;
    int totalPrime = 0; //total number of primes
    if( number > 1)
    {
        unsigned long int n = number;
        printf("Primes before %ld are: ", number);
        for(int i = 1; i <= n; i++)
        {
            divisorCount = 0;
            for(int j = 1; j <= i; j++)
            {
                if(i % j == 0)
                {
                    divisorCount++;
                }
            }
            if(divisorCount == 2)
            {
                printf("%d ", i);
                totalPrime++;
            }

        }
        printf("\n%d prime numbers are smaller than %ld\n", totalPrime, number);
    }
}
int main()
{
    unsigned long int number = 0;
    int x = 1;
    while(x == 1)
    {
        printf("Please enter a positive integer number (0 to end):");
        scanf("%ld", &number);
        if(number == 0)
        {
            x++;
        }
        printPrime(number);
        number = 0;
    }
    printf("Thanks and have a good day!\n");
    return 0;
}
