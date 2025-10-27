%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to validate the day/month/year ranges
int is_valid_date(int d, int m, int y) {
    if (y < 1) return 0;
    if (m < 1 || m > 12) return 0;
    
    int maxd;
    if (m == 2) {
        // leap year check
        int leap = (y % 400 == 0) || (y % 4 == 0 && y % 100 != 0);
        maxd = leap ? 29 : 28;
    } else if (m == 4 || m == 6 || m == 9 || m == 11) {
        maxd = 30;
    } else {
        maxd = 31;
    }

    return (d >= 1 && d <= maxd);
}
%}

%%
([0-9]{2})\/([0-9]{2})\/([0-9]{4}) {
    int d, m, y;
    sscanf(yytext, "%d/%d/%d", &d, &m, &y);
    if (is_valid_date(d, m, y))
        printf("%s is a valid date\n", yytext);
    else
        printf("%s is invalid (day/month mismatch)\n", yytext);
}
[ \t\n]+   ;    // ignore whitespace
.          { printf("%s is invalid format\n", yytext); }
%%

int main() {
    printf("Enter a date (dd/mm/yyyy): ");
    yylex();
    return 0;
}

int yywrap() { return 1; }