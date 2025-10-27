%{
    #include<stdio.h>
    #include<stdlib.h>
    #include"y.tab.h"
    extern int yylval;
    void yyerror(char *s);
%}

%%
[0-9]+ {yylval=atoi(yytext); return NUMBER;}
[ \t] ;
[\n] {return 0;}
[+\-*/%] {return yytext[0];}
[() ] {return yytext[0];}
. { yyerror("Invalid character"); exit(1);}

%%

int yywrap(){
    return 1;
}