%{
#include <stdio.h>
#include <stdlib.h>

/* Function to calculate base^exp without using pow() */
int power(int base, int exp) {
    int result = 1;
    for(int i = 0; i < exp; i++)
        result *= base;
    return result;
}
%}

%%

[0-9]+  { 
            int num = atoi(yytext);       // original number
            int original = num;
            int sum = 0, n = 0, digit;

            // Count digits
            int temp = num;
            while(temp != 0) { n++; temp /= 10; }

            // Calculate sum of digits^n
            temp = num;
            while(temp != 0) {
                digit = temp % 10;
                sum += power(digit, n);
                temp /= 10;
            }

            // Print result
            if(sum == original)
                printf("%d is an Armstrong number.\n", original);
            else
                printf("%d is not an Armstrong number.\n", original);
        }

\n      ;    /* ignore newlines */
.       ;    /* ignore everything else */

%%

int main() {
    printf("Enter a number to check if it is Armstrong:\n");
    yylex();
    return 0;
}

int yywrap() { return 1; }
