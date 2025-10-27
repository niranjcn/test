%{
#include <stdio.h>
#include <stdlib.h>

long original = 0;
int is_number = 0;

int is_palindrome(long n) {
    long rev = 0, temp = n;
    while (temp > 0) {
        rev = rev * 10 + (temp % 10);
        temp /= 10;
    }
    return n == rev;
}
%}

%%

[0-9]+   {
             original = atol(yytext);
             is_number = 1;
         }

\n       { return 0; }

.+       {
             printf("Invalid input! Please enter a valid number.\n");
             return 0;
         }

%%

int main() {
    printf("Enter a number: ");
    yylex();

    if (!is_number) return 0;

    if (is_palindrome(original))
        printf("The number %ld is a palindrome.\n", original);
    else
        printf("The number %ld is NOT a palindrome.\n", original);

    return 0;
}

int yywrap() { return 1; }
