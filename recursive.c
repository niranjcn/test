#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
int i = 0,error = 0;
char input[100];
void E();
void T();
void EP();
void TP();
void F();

int main(){
    printf("Enter an expression");
    gets(input);
    E();
    if(strlen(input) == i && error == 0){
        printf("Valid Expression");
    }else{
        printf("Invalid Expression");
    }
}

void E(){
    T();
    EP();
}

void T(){
    F();
    TP();
}
void EP(){
    if(input[i] == '+'){
        i++;
        T();
        EP();
    }
}
void TP(){
    if(input[i] == '*'){
        i++;
        F();
        TP();
    }
}
void F(){
    if(isalnum(input[i])){
        i++;
    }else if(input[i] == "("){
        i++;
        E();
        if(input[i] == ")"){
            i++;
        }else{
            error = 1;
        }

    }
    else{
        error = 1;
    }
}
