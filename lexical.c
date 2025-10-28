#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isKeyword(char word[]) {
    char keywords[32][10] = {
        "auto", "break", "case", "char", "const", "continue", "default", "do",
        "double", "else", "enum", "extern", "float", "for", "goto", "if",
        "int", "long", "register", "return", "short", "signed", "sizeof",
        "static", "struct", "switch", "typedef", "union", "unsigned",
        "void", "volatile", "while"
    };
    for (int i = 0; i < 32; i++) {
        if (strcmp(word, keywords[i]) == 0)
            return 1;
    }
    return 0;
}

int isOperator(char ch) {
    char operators[] = "+-*/%=<>!";
    for (int i = 0; i < strlen(operators); i++) {
        if (ch == operators[i])
            return 1;
    }
    return 0;
}

int main() {
    FILE *fp;
    char ch, buffer[50];
    int i = 0;

    fp = fopen("program.txt", "r");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return 0;
    }

    printf("---- Lexical Analysis Output ----\n");

    while ((ch = fgetc(fp)) != EOF) {
        // If operator
        if (isOperator(ch)) {
            printf("%c is an operator\n", ch);
        }
        // If identifier or keyword
        else if (isalnum(ch)) {
            buffer[i++] = ch;
        }
        // Word end (space, newline, etc.)
        else if ((ch == ' ' || ch == '\n' || ch == '\t') && i != 0) {
            buffer[i] = '\0';
            i = 0;
            if (isKeyword(buffer))
                printf("%s is a keyword\n", buffer);
            else
                printf("%s is an identifier\n", buffer);
        }
    }

    fclose(fp);
    return 0;
}