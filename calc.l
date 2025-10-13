/* calculator.l */
%{
    #include "y.tab.h" // Include header from YACC
    #include <stdlib.h>
    void yyerror(char *);
%}

%%
[0-9]+      {
                yylval = atoi(yytext); // Convert string to int and store in yylval
                return NUMBER; 
            }
[-+*/()\n]   { return *yytext; } // Return operators as themselves
[ \t]       ; /* Skip whitespace */
.           { yyerror("Invalid character"); }
%%

int yywrap() {
    return 1;
}