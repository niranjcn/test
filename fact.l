%{
    #include<stdio.h>
%}

%%
[0-9]+ {int x=atoi(yytext),y=1; while(x!=1){ y*=x; x--;} printf("The factorial is: %d",y);}
\n {return 0;}
%%
int main(){ 
    printf("Enter the input: ");
    yylex();
    printf("\n"); 
    return 0;
    }
int yywrap(){return 1;}