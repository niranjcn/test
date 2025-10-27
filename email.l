%{
#include <stdio.h>
int valid = 0;
%}

%%
[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]+   { valid = 1; }
\n                                              { return 0; }
.                                               ;
%%

int main() {
    printf("Enter the email to check: ");
    yylex();
    if (valid)
        printf("The given input is an email address\n");
    else
        printf("The given input is not an email address\n");
    return 0;
}

int yywrap() { return 1; }
