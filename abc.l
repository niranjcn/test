/* abc2ABC.l */
%{
#include <stdio.h>
%}
%%
abc     { printf("ABC"); }
%%
int main(){ yylex(); return 0;}
int yywrap(){return 1;}
