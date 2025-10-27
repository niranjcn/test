#include <stdio.h>
#include <string.h>

struct Rule 
{
    char left[10], right[10]; 
};

int main() 
{
    char input[20], stack[50] = "", temp[50];
    struct Rule rules[10];
    int i = 0, n, steps = 0;
    printf("Enter number of rules: ");
    scanf("%d", &n);
    printf("Enter rules (A->abc):\n");
    for (int j = 0; j < n; j++) 
    {
        scanf("%s", temp);
        strcpy(rules[j].left, strtok(temp, "->"));
        strcpy(rules[j].right, strtok(NULL, "->"));
    }
    printf("Enter input: ");
    scanf("%s", input);
    printf("\nStack\t Input\t Action\n");
    printf("--------------------------------------------\n");
    while (1) 
    {
        steps++;
        int reduced = 1;
        while (reduced) 
        {
            reduced = 0;
            for (int j = 0; j < n; j++) 
            {
                int sl = strlen(stack), rl = strlen(rules[j].right);
                if (sl >= rl && !strcmp(stack + sl - rl, rules[j].right)) 
                {
                    stack[sl - rl] = '\0';
                    strcat(stack, rules[j].left);
                    printf("%s\t %s\t Reduce %s->%s\n", stack, input + i, rules[j].left, rules[j].right);
                    reduced = 1;
                    break;
                }
            }
        }
        if (!strcmp(stack, rules[0].left) && i == strlen(input)) 
        {
            printf("\nAccepted in %d steps\n", steps);
            break;
        }
        if (i < strlen(input)) 
        {
            char c = input[i];
            strncat(stack, &input[i++], 1);
            printf("%s\t %s\t Shift '%c'\n", stack, input + i, c);
        }
        else 
        {
            printf("\nNot Accepted\n");
            break;
        }
    }
    return 0;
}
