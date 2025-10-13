#include <stdio.h>
#include <string.h>
#include <ctype.h>

char expr[100];
int tempCount = 1;

void newTemp(char *t) {
    sprintf(t, "t%d", tempCount++);
}

// Helper: remove spaces
void removeSpaces(char *src) {
    int i, j = 0;
    for (i = 0; src[i] != '\0'; i++) {
        if (src[i] != ' ')
            src[j++] = src[i];
    }
    src[j] = '\0';
}

// Generate intermediate code (TAC)
void generateTAC(char *exp) {
    char lhs[10], rhs[100];
    int i = 0, j = 0;
    removeSpaces(exp);

    // Split LHS and RHS
    while (exp[i] != '=' && exp[i] != '\0') {
        lhs[j++] = exp[i++];
    }
    lhs[j] = '\0';
    strcpy(rhs, exp + i + 1);

    // We’ll work on rhs repeatedly until reduced to one temp variable
    char operators[] = "*/+-";
    char temp[10];

    printf("\nGenerated Intermediate Code (Three Address Code):\n");

    // Process operators by precedence
    for (int p = 0; p < strlen(operators); p++) {
        for (i = 0; rhs[i] != '\0'; i++) {
            if (rhs[i] == operators[p]) {
                if ((operators[p] == '+' || operators[p] == '-') &&
                    (strchr(rhs, '*') || strchr(rhs, '/')))
                    continue; // Skip + and - until * and / are handled

                char op = rhs[i];
                char leftOp[10], rightOp[10];
                int li = i - 1, ri = i + 1;

                // Find left operand
                while (li >= 0 && isalnum(rhs[li])) li--;
                strncpy(leftOp, rhs + li + 1, i - li - 1);
                leftOp[i - li - 1] = '\0';

                // Find right operand
                int rstart = ri;
                while (isalnum(rhs[ri])) ri++;
                strncpy(rightOp, rhs + rstart, ri - rstart);
                rightOp[ri - rstart] = '\0';

                newTemp(temp);
                printf("%s = %s %c %s\n", temp, leftOp, op, rightOp);

                // Replace the processed part with temp in rhs
                char newExp[100] = "";
                strncat(newExp, rhs, li + 1);
                strcat(newExp, temp);
                strcat(newExp, rhs + ri);
                strcpy(rhs, newExp);

                i = -1; // restart scanning
            }
        }
    }

    // Final assignment
    printf("%s = %s\n", lhs, rhs);
}

int main() {
    printf("Enter a simple arithmetic expression (e.g., a = b + c * d):\n");
    gets(expr);

    generateTAC(expr);

    return 0;
}

