%{
#include <stdio.h>
int valid = 0;  // flag to track if input matched
%}

%%

[0-9]{3}-[0-9]{3}-[0-9]{4}  { valid = 1; }
\n                           { return 0; }
.                            ;
%%

int main() {
    printf("Enter the input to check if it's a mobile number or not: ");
    yylex();
    if (valid)
        printf("The given input is a mobile number\n");
    else
        printf("The given input is not a mobile number\n");
    return 0;
}

int yywrap() { return 1; }
