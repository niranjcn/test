#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void main(){
    char icode[10][30], str[10], opr[20];
    int i=0, num=0;
    printf("Enter the intermediate code to generate backend of compiler\n");
    i=0;
    while(1){
        scanf("%s",icode[i]);
        if(strcmp(icode[i],"exit")==0) break;
        i++;
    }
    num = i;
    printf("Intermediate code is\n");
    i=0;
    do{
        strcpy(str,icode[i]);
        switch(str[3])
        {
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
        printf("\nMOV %c, R%d",str[2],i);
        printf("\n%s %c, R%d",opr,str[4],i);
        printf("\nMOV R%d, %c",i,str[0]);
    }while(++i < num && strcmp(icode[i],"end")!=0);
}