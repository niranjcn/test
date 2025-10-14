#include <stdio.h>
#include <string.h>

char result[20][20], t1[20][20], in[20][20], t2[20][20];
int j;

void add(char *s) {
    for (int i = 0; i < j; i++) {
        if (!strcmp(result[i], s)) {
            return;
        }
    }
    strcpy(result[j++], s);
}

void epsilon_closure(int n, char *s) {
    for (int i = 0; i < n; i++) {
        if (!strcmp(s, t1[i]) && !strcmp(in[i], "e")) {
            add(t2[i]);
            epsilon_closure(n, t2[i]);
        }
    }
}

int main() {
    int n, m;
    char states[20][20];

    printf("Enter number of states: ");
    scanf("%d", &n);

    printf("Enter states:\n");
    for (int i = 0; i < n; i++) {
        scanf("%s", states[i]);
    }

    printf("Enter number of transitions: ");
    scanf("%d", &m);

    printf("Enter transitions (state1 input state2):\n");
    for (int i = 0; i < m; i++) {
        scanf("%s %s %s", t1[i], in[i], t2[i]);
    }

    for (int i = 0; i < n; i++) {
        j = 0;
        add(states[i]);
        epsilon_closure(m, states[i]);
        printf("\nEpsilon closure of %s = { ", states[i]);
        for (int k = 0; k < j; k++) {
            printf("%s ", result[k]);
        }
        printf("}\n");
    }

    return 0;
}