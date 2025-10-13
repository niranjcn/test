#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 30

struct Expression {
    char op;       // Operator: +, -, *, /, =
    char op1[10];  // Operand 1
    char op2[10];  // Operand 2
    char res[10];  // Result variable
};

int main() {
    struct Expression exp[MAX];
    int n, i, j, change;

    printf("Enter number of expressions: ");
    scanf("%d", &n);

    printf("\nEnter expressions in format (<op> <op1> <op2> <res>):\n");
    printf("Example:\n= 3 - a\n+ a b t1\n* t1 2 t2\n\n");

    for (i = 0; i < n; i++) {
        scanf(" %c %s %s %s", &exp[i].op, exp[i].op1, exp[i].op2, exp[i].res);
    }

    // Constant propagation
    do {
        change = 0;
        for (i = 0; i < n; i++) {
            // If assignment (=), propagate constant to result
            if (exp[i].op == '=') {
                // Check if right-hand side is a constant
                if (isdigit(exp[i].op1[0])) {
                    // Replace any use of this variable with constant
                    for (j = 0; j < n; j++) {
                        if (strcmp(exp[i].res, exp[j].op1) == 0) {
                            strcpy(exp[j].op1, exp[i].op1);
                            change = 1;
                        }
                        if (strcmp(exp[i].res, exp[j].op2) == 0) {
                            strcpy(exp[j].op2, exp[i].op1);
                            change = 1;
                        }
                    }
                }
            }
        }
    } while (change);

    printf("\nOptimized Code After Constant Propagation:\n");
    for (i = 0; i < n; i++) {
        printf("%c %s %s %s\n", exp[i].op, exp[i].op1, exp[i].op2, exp[i].res);
    }

    return 0;
}
