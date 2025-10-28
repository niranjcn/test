%{
    #include<stdio.h>
    #include "y.tab.h"
    int yyerror(char *);
    extern int yylval;
%}

%%
[0-9]+    {yylval = atoi(yytext); return NUMBER;}
[+\-*/%()] {return yytext[0];}
.          {yyerror("Invalid Character"); exit(1);}
%%

int yywrap(){
    return 1;
}
