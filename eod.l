%{
    #include<stdio.h>
%}

%%
[0-9]+ {int x=atoi(yytext); if(x%2==0) printf("The number is even\n"); else printf("The number is odd\n");}
\n {return 0;}
%%

int main(){
    printf("Enter the number to check if its even or odd: ");
    yylex();
    return 0;
}
int yywrap(){
    return 1;
}