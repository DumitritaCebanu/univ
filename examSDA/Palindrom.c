#include <stdio.h>
#include <string.h>

char inputText[] = "abbba";
int n = 0, m = sizeof(inputText) - 2, isPalindrome = 0;

void checkPalindrome (int a, int b) {
     if (a > b)
         return;
     else 
         if (inputText[a] == inputText[b]) {
             isPalindrome = 1;
             checkPalindrome(a + 1, b - 1);
         }
         else {
             isPalindrome = 0;
             return;
         }
}

int main (void) {
    checkPalindrome(n, m);

    if (isPalindrome == 0)
        printf("The word is not a palindrome.");
    else
        printf("The word is a palindrome.");
}

/* number palindrom
int isPal(int aj)
{
    static int sum = 0;
    if(aj != 0)
    {
        sum = sum *10 + aj%10;
        isPal(aj/10);   // recursive call same as while(n!=0) using loop
    }
    else if(sum == n)
        return 1;
    else
        return 0;
}
*/