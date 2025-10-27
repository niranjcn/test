%{
#include <stdio.h>
#include <stdlib.h>
int num;
int is_perfect(int n) {
    int j=0, arr[30], result=0;
    for(int i=1;i<(n/2)+1;i++){
        if(n%i==0){
            arr[j]=i;
            j++;
        }
    }
    arr[j] = -1;
    for(int i=0;arr[i]!=-1;i++){
        result+=arr[i];
    }
    return (result == n);
    }

%}

%%
[0-9]+ { num =atoi(yytext);}
\n {return 0;}
. ;
%%

int main(){
    printf("Enter the number to check if its perfect or not: ");
    yylex();
    if(is_perfect(num))
        printf("The number is a perfect number\n");
    else
        printf("The number is not a perfect number \n");
}

int yywrap(){
    return 1;
}