#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

char *input;   // pointer to input string
char lookahead; // current character

// function declarations
void E();
void Eprime();
void T();
void Tprime();
void F();

void error() {
    printf("❌ Syntax Error\n");
    exit(1);
}

void next() {
    lookahead = *input++;  // move to next character
}

void match(char expected) {
    if (lookahead == expected)
        next();
    else
        error();
}

// Grammar implementation

void E() {
    T();
    Eprime();
}

void Eprime() {
    if (lookahead == '+') {
        match('+');
        T();
        Eprime();
    }
    // else epsilon (do nothing)
}

void T() {
    F();
    Tprime();
}

void Tprime() {
    if (lookahead == '*') {
        match('*');
        F();
        Tprime();
    }
    // else epsilon
}

void F() {
    if (isalpha(lookahead)) {   // identifier
        match(lookahead);
    } 
    else if (lookahead == '(') {
        match('(');
        E();
        match(')');
    } 
    else {
        error();
    }
}

int main() {
    char expr[100];
    printf("Enter expression: ");
    scanf("%s", expr);

    input = expr;
    next();     // initialize lookahead

    E();        // start from start symbol

    if (lookahead == '\0')
        printf("✅ Valid Expression\n");
    else
        printf("❌ Invalid Expression\n");

    return 0;
}
