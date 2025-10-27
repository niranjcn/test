%{
#include <stdio.h>
#include <string.h>
%}

%%

"#"[^\r\n]*        { printf("%s is a preprocessor directive\n", yytext); }
"//"[^\r\n]*       { printf("%s is a single-line comment\n", yytext); }
"/*"([^*]|\*+[^*/])*\*+"/"   { printf("%s is a multi-line comment\n", yytext); }

(int|void|char|double|float|break|continue|return|main|while|for|do|struct|union) { printf("%s is a keyword\n", yytext); }

[_A-Za-z][_A-Za-z0-9]*   { printf("%s is an identifier\n", yytext); }
\"([^\\\"]|\\.)*\"       { printf("%s is a string\n", yytext); }
[0-9]+                   { printf("%s is a number\n", yytext); }
\<|\>|\<=|\>=            { printf("%s is a relational\n", yytext); }
"=="                     { printf("%s is a equal to\n", yytext); }
"="                      { printf("%s is an assignment operator\n", yytext); }
[ \t\r\n]+               ;     /* ignore whitespace */
.                        ;     /* ignore anything else */

%%

int main() {
    FILE *fp = fopen("input.txt","r");
    if(!fp) {
        printf("File does not exist\n");
        return 0;
    }
    yyin = fp;
    yylex();
    return 0;
}

int yywrap() { return 1; }
