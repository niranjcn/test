%{
#include <stdio.h>
#include <stdlib.h>
%}

%%
[0-9]{6}   {printf("Valid Pincode: %s \n", yytext);}
[ \t\n]   ; // ignore whitespace
.         { printf("Invalid Pincode: %s\n", yytext); }
%%
int main(){
    printf("Enter pincodes to validate (Ctrl+D to end):\n");
    yylex();
    return 0;
}
int yywrap() {
    return 1;
}
