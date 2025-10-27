%{
    #include<stdio.h>
    #include<string.h>
    #include<stdlib.h>
    char text[100];
    void reverse(char *s, char* rev){
        int len=strlen(s);
        int j=0;
        for(int i=len-1;i>=0;i--){
            rev[j] = s[i];
            j++;
        }
        rev[len] = '\0';
    }
%}

%%
.+  {strcpy(text, yytext);}
\n {return 0;}
%%

int main() {
    char rev[100];
    printf("Enter the string to check if it's a palindrome:\n");
    yylex();
    reverse(text, rev);
    if (strcmp(text, rev) == 0)
        printf("The given string'%s' is a palindrome.\n", text);
    else
        printf("The given string '%s' is NOT a palindrome.\n", text);

    return 0;
}

int yywrap(){
    return 1;
}