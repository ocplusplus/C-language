#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* String Manipulation - find, replace, remove, palindrome test, and reverse functions */

//find char function
int findChar(char * str, char c1)
{
    int idx = -1;
    for(int i = 0; i < strlen(str); i++)
    {
        if(str[i]==c1)//when character is found return index
        {
            idx = i;
            break;
        }

    }
    return idx;//when character not found return -1
}
//replace char function
int replaceChar(char * str, char c1, char c2)
{
    int count = 0;
    for(int i = 0; i <strlen(str); i++)
    {
        if(str[i]==c1) //check if c1 matches
        {
            str[i]=c2; //replaces string
            count++;
        }
    }
    return count;
}
//remove char function
int removeChar(char *str1, char *str2, char c1)
{
    int count = 0;
    strcpy(str2,str1); //copy string 1 into string 2
    for(int i = 0; i <strlen(str2); i++)
    {
        if(str2[i]==c1) //check if c1 matches
        {
            str2[i]= '*'; //replaces character with asterick
            count++;
        }
    }
    return count;
}
//palindrome string function
int isPalindrome(char * str)
{
    int n = strlen(str);
    int isPalindrome = 0;
    for(int i=0; i<n/2; i++)
    {
        if(str[i]!=(str[n-(i+1)]))
        {
            return 0;
        }
    return 1;
    }
}
//reverse string function
int reverseString(char * str)
{
    int n = strlen(str);
    char temp;
    for(int i=0; i<n/2; i++)
    {
        temp=str[i];
        str[i]=str[n-(i+1)];
        str[n-(i+1)]=temp;
    }
    return n;
}
int main()
{

    char s[100], s1[100];
    char c1, c2;
    int result;
//find char
    printf("Please enter String: ");
    scanf("%s", s);
    printf("\nPlease enter character to find:");
    scanf(" %c", &c1);
    result = findChar(s,c1);
    printf("Index of character : %d.\n",result);
//replace char
    printf("Please enter string: ");
    scanf("%s", s);
    printf("\nPlease enter character to replace:");
    scanf(" %c", &c1);
    printf("\nPlease enter replacement character:");
    scanf(" %c", &c2);
    result = replaceChar(s,c1,c2);
    printf("Number of character replacements : %d.\nString with character replaced: %s",result,s);
//remove char
    printf("\nPlease enter string: ");
    scanf("%s", s);
    printf("\nPlease enter character to remove:");
    scanf(" %c", &c1);
    result = removeChar(s,s1,c1);
    printf("Number of characters removed : %d.\nString with character removed: %s",result,s1);
//palindrome string
    printf("\nPlease enter string to test if palindrome: ");
    scanf("%s", s);
    result = isPalindrome(s);
    printf("Result is 1 if string is palindrome, otherwise result is 0: %d", result);
//reverse string
    printf("\nPlease enter string to reverse: ");
    scanf("%s", s);
    result = reverseString (s);
    printf("Number of characters in reverse string : %d.\nString in reverse: %s",result,s);
}
