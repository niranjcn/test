%{
    #include<stdio.h>
%}

%%
[0-9]   { putchar('#'); }
.|\n    { ECHO; }
%%

int main(){
    yylex();
    return 0;
}

int yywrap(){
    return 1;
}