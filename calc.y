%{
    #include<stdio.h>
    int flag=0;
    void yyerror(char *s);
    int yylex();
%}

%token NUMBER
%left '+' '-' 
%left '*' '/' '%'
%left '(' ')'

%%
ArithemeticExpression: E { printf("Result %d\n",$$); return 0;};
E: E '+' E {$$=$1+$3;} | E '-' E {$$=$1-$3;} | E '*' E {$$=$1*$3;} | E '/' E {$$=$1/$3;} | E '%' E {$$=$1%$3;} | '(' E ')' {$$=$2;} | NUMBER {$$=$1;};
%%

void main(){
    printf("Enter the arithmetic expression to evaluate\n");
    yyparse();
    if(flag==0)
        printf("The entered arithmetic expression is valid\n");
}

void yyerror(char *s){
    flag=1;
    printf("The entered expression is invalid\n");
}
