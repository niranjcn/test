//use gcc lex.yy.c -lm
%{
#include <stdio.h>
#include <math.h>
%}

%%
[0-9]+  {
            int num = atoi(yytext);
            int temp = num, sum = 0, digit, n = 0;

            // Count number of digits
            while(temp != 0) {
                n++;
                temp /= 10;
            }

            temp = num;

            // Calculate sum of digits raised to power n
            while(temp != 0) {
                digit = temp % 10;
                sum += pow(digit, n);
                temp /= 10;
            }

            if(sum == num)
                printf("%d is an Armstrong number\n", num);
            else
                printf("%d is not an Armstrong number\n", num);
        }

.|\n    ;
%%

int main() {
    printf("Enter a number: ");
    yylex();
    return 0;
}

int yywrap() {
    return 1;
}
