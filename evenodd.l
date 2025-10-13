/* evenodd.l */
%{
#include <stdio.h>
#include <stdlib.h>
%}
%%
[+-]?[0-9]+  {
                long n = atol(yytext);
                printf("%ld is %s\n", n, (n%2==0)?"Even":"Odd");
             }
[ \t\n]+ ;
. { printf("Invalid token: %s\n", yytext); }
%%
int main(){ yylex(); return 0;}
int yywrap(){return 1;}
