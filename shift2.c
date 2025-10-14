#include <stdio.h>
#include <string.h>

struct Rule { char left[10], right[10]; };

int main() {
    char input[20], stack[50] = "", temp[50], *sub;
    int i = 0, j, n;
    struct Rule rules[10];

    printf("Enter number of rules: ");
    scanf("%d", &n);
    printf("Enter rules (A->abc):\n");
    for (i = 0; i < n; i++) {
        scanf("%s", temp);
        strcpy(rules[i].left, strtok(temp, "->"));
        strcpy(rules[i].right, strtok(NULL, "->"));
    }

    printf("Enter input: ");
    scanf("%s", input);
    i = 0;

    while (1) {
        if (i < strlen(input)) {
            strncat(stack, &input[i++], 1);
            printf("%s\t%s\tShift\n", stack, input + i);
        }

        for (j = 0; j < n; j++) {
            if ((sub = strstr(stack, rules[j].right))) {
                stack[sub - stack] = '\0';
                strcat(stack, rules[j].left);
                printf("%s\t%s\tReduce %s->%s\n", stack, input + i, rules[j].left, rules[j].right);
                j = -1; // restart reduction
            }
        }

        if (!strcmp(stack, rules[0].left) && i == strlen(input)) {
            printf("\nAccepted\n");
            break;
        }
        if (i == strlen(input)) {
            printf("\nNot Accepted\n");
            break;
        }
    }
    return 0;
}