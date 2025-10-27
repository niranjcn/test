%{
    #include<stdio.h>
%}

%%

0 {printf ("The number is zero\n");}
-[0-9]+ {printf("The number is negative\n");}
[0-9]+ {printf("The number is positive\n");}
\n {return 0;}
. {printf("Invalid input\n");}
%%

int main(){
    printf("Enter the number to check: ");
    yylex();
    return 0;
}
int yywrap(){
    return 1;
}