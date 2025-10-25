#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct TAC {
    char op[3], arg1[10], arg2[10], res[10];
} code[20];

char var[20][10];
int val[20], count = 0;

int findConst(char x[]) {
    for (int i = 0; i < count; i++)
        if (strcmp(var[i], x) == 0)
            return val[i];
    return -9999; // not found
}

int main() {
    int n;
    printf("Enter number of 3-address code statements: ");
    scanf("%d", &n);

    printf("Enter TAC (e.g., = 3 a or + a b t1):\n");
    for (int i = 0; i < n; i++)
        scanf("%s %s %s %s", code[i].op, code[i].arg1, code[i].arg2, code[i].res);

    printf("\nAfter Constant Propagation:\n");
    for (int i = 0; i < n; i++) {
        if (strcmp(code[i].op, "=") == 0) {
            if (code[i].arg1[0] >= '0' && code[i].arg1[0] <= '9') {
                strcpy(var[count], code[i].arg2);
                val[count++] = atoi(code[i].arg1);
            }
            printf("%s = %s\n", code[i].arg2, code[i].arg1);
        } else {
            int v1 = findConst(code[i].arg1);
            int v2 = findConst(code[i].arg2);
            if (v1 != -9999)
                sprintf(code[i].arg1, "%d", v1);
            if (v2 != -9999)
                sprintf(code[i].arg2, "%d", v2);
            printf("%s = %s %s %s\n", code[i].res, code[i].arg1, code[i].op, code[i].arg2);
        }
    }
return 0;
}