%{
    #include<stdio.h>
    #include<stdlib.h>
%}

%%
[0-9]+  {
            long n = atol(yytext);
            unsigned long long res = 1;
            for(long i = 2;i<=n;i++)
            res *= i;
            printf("%ld! = %llu\n",n,res);
        }
[ \t\n]+    ;
.       { printf("Ignoring: %s\n",yytext); }
%%

int main(){
    yylex();
    return 0;
}
int yywrap(){
    return 1;
}
