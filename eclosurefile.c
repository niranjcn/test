#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct transition{
    char from[16];
    char symbol;
    char to[16];
};

struct transition trans[200];

void closure(const char *state, int num, int visited[], char allStates[][16], int n);

int main()
{
    int num, n;
    char state[50][16];
    FILE *fp = fopen("input.txt", "r");
    if(!fp){
        perror("Failed to open input.txt");
        return 1;
    }

    num = 0;
    while(fscanf(fp, "%s %c %s", trans[num].from, &trans[num].symbol, trans[num].to) == 3){
        num++;
    }
    fclose(fp);
    printf("enter no of states:\n");
    if(scanf("%d", &n) != 1){
        fprintf(stderr, "Invalid number of states\n");
        return 1;
    }
    printf("enter the states:\n");
    for(int i=0;i<n;i++){
        scanf("%s", state[i]);
    }

    for(int i=0;i<n;i++){
        int visited[200] = {0};
        printf("\nepsilon closure of %s:{", state[i]);
        closure(state[i], num, visited, state, n);
        printf("}\n");
    }
    return 0;
}

void closure(const char *state, int num, int visited[], char allStates[][16], int n)
{
    int flag = -1;
    for(int i=0;i<n;i++){
        if(strcmp(allStates[i], state) == 0){
            flag = i;
            break;
        }
    }

    if(flag == -1 || visited[flag])
        return;
    visited[flag] = 1;
    printf("%s", state);

    for(int i=0;i<num;i++){
        if(strcmp(trans[i].from, state) == 0 && trans[i].symbol == 'e'){
            closure(trans[i].to, num, visited, allStates, n);
        }
    }
}
