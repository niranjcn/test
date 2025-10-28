#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

char expr[MAX];
char temp = 'Z';
int i;
void generate();

int main() 
{
    printf("\t\tINTERMEDIATE CODE GENERATION\n\n");
    printf("Enter the Expression: ");
    scanf("%s", expr);
    printf("The intermediate code:\n");
    generate();
    return 0;
}

void generate() 
{
    char opOrder[] = {'/', '*', '+', '-', '='};
    int len = strlen(expr);
    int start;
    if (expr[0] == '=')
        start = 1;
    else
        start = 0;
    for (int p = 0; p < 5; p++) {
        for (i = start; i < len; i++) 
        {
            char c = expr[i];
            if (c == opOrder[p]) 
            {
                if (c == '=' && i == 0)
                    continue;
                int l = i - 1;
                while (l >= 0 && (expr[l] == '$' || expr[l] == ' '))
                    l--;
                char left = expr[l];
                int r = i + 1;
                while (r < len && (expr[r] == '$' || expr[r] == ' ')) 
                    r++;
                char right = expr[r];
                printf("%c := %c %c %c\n", temp, left, c, right);
                expr[l] = '$';
                expr[i] = temp;
                expr[r] = '$';
                temp--;
            }
        }
    }
    printf("w := %c\n", temp + 1);
}