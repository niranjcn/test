/* calculator.y */
%{
    #include <stdio.h>
    int yylex(void);
    void yyerror(char *);
%}

// Define the token type and operator precedence
%token NUMBER
%left '+' '-'
%left '*' '/'

%%
program:
    program statement '\n'
    |
    ;

statement:
    expr                    { printf("Result: %d\n", $1); }
    ;

expr:
    expr '+' expr           { $$ = $1 + $3; }
    | expr '-' expr         { $$ = $1 - $3; }
    | expr '*' expr         { $$ = $1 * $3; }
    | expr '/' expr         { $$ = $1 / $3; }
    | '(' expr ')'          { $$ = $2; }
    | NUMBER                { $$ = $1; }
    ;
%%

void yyerror(char *s) {
    fprintf(stderr, "Error: %s\n", s);
}

int main() {
    printf("Enter an expression (e.g., 5 * (3 + 4)) followed by Enter:\n");
    yyparse();
    return 0;
}