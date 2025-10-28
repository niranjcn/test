%{
#include <stdio.h>
#include<stdlib.h>
int upper = 0; lower = 0, digit = 0, special = 0;
%}

%%
[A-Z] {upper++;}
[a-z] {lower++;}
[0-9] {digit++;}
[!@#$%^&*(),.?":{}|<>] {special++;}
.    ;
%%

int main(){
    printf("Enter a password to validate:\n");
    yylex();
    if(upper >= 1 && lower >= 1 && digit >= 1 && special >= 1){
        printf("Valid Password\n");
    }
    else{
        printf("Invalid Password\n");
    }
    return 0;
}

int yywrap() {
    return 1;
}
