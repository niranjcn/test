/* abc2ABC.l */
%{
#include <stdio.h>
%}
%%
abc     { printf("ABC"); }
\n      {return 0;}
%%
int main(){ 
    printf("Enter the input: ");
    yylex();
    printf("\n"); 
    return 0;
    }
int yywrap(){return 1;}
