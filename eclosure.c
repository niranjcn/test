#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void closure(char states[], int num, int visited[], char allStates[][10], int n); // corrected prototype

struct transition{
    char from[6];
    char symbol;
    char to[6];
}trans[20];

int main()
{
    int num,n;
    char state[6][10];
    printf("enter the no of transitions:\n");
    scanf("%d",&num);
    printf("enter the transitions:\n");
    for(int i=0;i<num;i++)
    {
        scanf("%s %c %s",trans[i].from,&trans[i].symbol,trans[i].to);
    }
    printf("enter no of states:\n");
    scanf("%d",&n);
    printf("enter the states:\n");
    for(int i=0;i<n;i++)
    {
        scanf("%s",state[i]);
    }
    for(int i=0;i<n;i++)
    {
        int visited[10] = {0}; // size >= number of states
        printf("\nepsilon closure of %s:{", state[i]);
        closure(state[i], num, visited, state, n);
        printf("}\n");
    }
}

void closure(char states[6], int num, int visited[], char allStates[][10], int n)
{
    int flag = -1;
    for(int i=0;i<n;i++)
        if(strcmp(allStates[i], states)==0) 
            flag=i;

    if(flag==-1 || visited[flag]) 
        return;
    visited[flag] = 1;
    printf("%s", states);

    for(int i=0;i<num;i++)
    {
        if(strcmp(trans[i].from, states)==0 && trans[i].symbol=='e')
        {
            closure(trans[i].to, num, visited, allStates, n);
        }
    }
}
