%{
#include "y.tab.h"
%}

%%

[a-zA-Z_][a-zA-Z0-9_]*    { yylval = 0; return ID; }
[0-9]+                    { yylval = atoi(yytext); return NUMBER; }

[ \t\n]+                  ;  // skip whitespace

"="                       { return '='; }
"+"                       { return '+'; }
"-"                       { return '-'; }
"*"                       { return '*'; }
"/"                       { return '/'; }
"("                       { return '('; }
")"                       { return ')'; }

.                         { printf("Unknown character: %s\n", yytext); exit(1); }

%%

int yywrap() {
    return 1;
}

