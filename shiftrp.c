#include <stdio.h>
#include <string.h>

char stack[30];
int top = -1;

void push(char c) {
    top++;
    stack[top] = c;
}

void pop() {
    if (top != -1) {
        top--;
    }
}

void display(const char* input, int input_ptr, const char* action) {
    for (int i = 0; i <= top; i++) {
        printf("%c", stack[i]);
    }
    printf("\t\t");
    for (int i = input_ptr; i < strlen(input); i++) {
        printf("%c", input[i]);
    }
    printf("\t\t%s\n", action);
}

void check() {
    if (stack[top] == 'a') {
        pop();
        push('E');
        printf("\t\tREDUCE E->a\n");
    }
    else if (stack[top] == 'E' && stack[top - 1] == '+' && stack[top - 2] == 'E') {
        pop();
        pop();
        pop();
        push('E');
        printf("\t\tREDUCE E->E+E\n");
    }
    else if (stack[top] == 'E' && stack[top - 1] == '*' && stack[top - 2] == 'E') {
        pop();
        pop();
        pop();
        push('E');
        printf("\t\tREDUCE E->E*E\n");
    }
    else if (stack[top] == ')' && stack[top - 1] == 'E' && stack[top - 2] == '(') {
        pop();
        pop();
        pop();
        push('E');
        printf("\t\tREDUCE E->(E)\n");
    }
}

int main() {
    char input[30];
    int input_ptr = 0;

    printf("GRAMMAR:\n");
    printf("E -> E + E\n");
    printf("E -> E * E\n");
    printf("E -> (E)\n");
    printf("E -> a\n\n");

    printf("Enter the input string (e.g., a*a+a): ");
    scanf("%s", input);
    strcat(input, "$");
    push('$');

    printf("\nSTACK\t\tINPUT\t\tACTION\n");
    printf("-----\t\t-----\t\t------\n");
    display(input, input_ptr, "Initial State");

    while (input[input_ptr] != '\0') {
        push(input[input_ptr]);
        input_ptr++;
        display(input, input_ptr, "SHIFT");
        while (1) {
            int previous_top = top;
            check();
            if (previous_top == top) {
                break;
            }
            display(input, input_ptr, "");
        }
    }

    if (stack[top] == 'E' && stack[top - 1] == '$') {
        printf("\nString is successfully parsed.\n");
    } else {
        printf("\nString parsing failed.\n");
    }

    return 0;
}
