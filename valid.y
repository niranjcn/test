%{
#include <stdio.h>
#include <stdlib.h>
void yyerror();
int yylex();
%}
%token ID NUMBER
%left '+' '-'
%left '*' '/'
%right '='
%%
assignment: ID '=' e;
e: e '+' e | e '-' e | e '*' e | e '/' e | '(' e ')' | ID | NUMBER;
%%
void yyerror() {
    printf("Invalid expression\n");
    exit(1);
}
int main() {
    printf("Enter an expression (e.g., a = b + c):\n");
    if (yyparse() == 0) {
        printf("Valid expression\n");
    }
    return 0;
}