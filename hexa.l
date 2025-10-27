%{
#include <stdio.h>
int valid = 0;  // flag to track if input matched
%}

%%

0[xX][0-9A-Fa-f]+   { valid = 1; }
\n {return 0;}
. { valid = 0; }

%%

int main(){
    printf("Enter the hexadecimal to check: ");
    yylex();
    if(valid)
        printf("\nThe entered string is a hexadecimal\n");
    else
        printf("\nThe entered string is not a hexadecimal\n");
}

int yywrap(){
    return 1;
}