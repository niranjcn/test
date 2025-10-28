#include<stdio.h>
#include<string.h>

int main(){
    
    printf("Enter the set of intermnediate expressions: (terminated by exit) \n");
    char expr[100][100],str[20],opr[20];
    int i = 0;
    do{
        scanf("%s",expr[i]);
    }while(strcmp(expr[i++], "exit") != 0);

    printf("The optimized expressions after common subexpression elimination are: \n");
    i = 0;
    do{
        strcpy(str, expr[i]);
        switch(str[3]){
            case '+':
                strcpy(opr, "ADD");
                break;
            case '-':
                strcpy(opr, "SUB");
                break;  
            case '*':
                strcpy(opr, "MUL");
                break;
            case '/':
                strcpy(opr, "DIV");
                break;
        }

        printf("\n\tMOV %c, R%d", str[2], i);
        printf("\n\t%s %c, R%d", opr, str[4], i);
        printf("\n\tMOV R%d, %c", i,str[0]);
    }while(strcmp(expr[++i],"exit") != 0);

}
