%{
#include <stdio.h>
#include <stdlib.h>
void yyerror();
int yylex();
%}
%token letter
%%
statement: ID ;
ID: letter;
%%
void yyerror() {
    printf("Invalid identifier\n");
    exit(1);
}
int main() {
    printf("Enter an identifier:\n");
    if (yyparse() == 0) {
        printf("Valid identifier\n");
    }
    return 0;
}
