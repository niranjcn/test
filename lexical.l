%{
#include <stdio.h>
#include <string.h>
int line_no = 1;
%}
%%
"//".*                              { printf("Single-line Comment\t: %s\n", yytext); }
"/*"([^*]|\*+[^*/])*"\*/"           { printf("Multi-line Comment\t: %s\n", yytext); }
[ \t]*#[ \t]*include[ \t]*<[^>\n]+> { printf("Preprocessor directive\t: %s\n", yytext); }
("auto"|"break"|"case"|"char"|"const"|"continue"|"default"|"do"|"double"|"else"|"enum"|"extern"|"float"|"for"|"goto"|"if"|"int"|"long"|"register"|"return"|"short"|"signed"|"sizeof"|"static"|"struct"|"switch"|"typedef"|"union"|"unsigned"|"void"|"volatile"|"while") { printf("Keyword\t\t: %s\n", yytext); }
[0-9]+                              { printf("Number\t\t: %s\n", yytext); }
[a-zA-Z_][a-zA-Z0-9_]*              { printf("Identifier\t: %s\n", yytext); }
\"([^\"\\]|\\.)*\"                   { printf("String Literal\t: %s\n", yytext); }
"=="|"!="|"<="|">="|"="|"+"|"-"|"*"|"/"|"%"   { printf("Operator\t: %s\n", yytext); }
[(){};,]                            {}
"<"|">"                              { printf("Relational Operator\t: %s\n", yytext); }
[\r\n]+                              { line_no++; }
[ \t]+                               {}
.                                     {}
%%
int main() {
    FILE *fp = fopen("input_file.c", "r");
    if (!fp) {
        perror("Error opening file");
        exit(0);
    }
    yyin = fp;
    yylex();
    printf("\nTotal Lines: %d\n", line_no);
    fclose(fp);
    return 0;
}
int yywrap() { return 1; }
