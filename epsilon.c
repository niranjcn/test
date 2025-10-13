#include <stdio.h>

#define MAX 20

int n; // number of states
int transition[MAX][MAX]; // adjacency matrix for ε-transitions (1 = epsilon move exists)
int visited[MAX];

// Function to perform DFS for epsilon closure
void epsilonClosure(int state) {
    for (int i = 0; i < n; i++) {
        // If there is an epsilon transition from state -> i and i not yet visited
        if (transition[state][i] && !visited[i]) {
            visited[i] = 1;
            epsilonClosure(i);
        }
    }
}

int main() {
    int i, j;

    printf("Enter number of states: ");
    scanf("%d", &n);

    printf("\nEnter epsilon transitions (Enter 1 if epsilon transition exists, else 0):\n");
    printf("For example, if ε-transition exists from state i to state j, enter 1.\n\n");

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("ε-transition from q%d to q%d: ", i, j);
            scanf("%d", &transition[i][j]);
        }
    }

    printf("\n----- Epsilon Closure of Each State -----\n");

    for (i = 0; i < n; i++) {
        // Reset visited array for each state
        for (j = 0; j < n; j++)
            visited[j] = 0;

        visited[i] = 1; // every state includes itself
        epsilonClosure(i);

        printf("ε-closure(q%d) = { ", i);
        for (j = 0; j < n; j++) {
            if (visited[j])
                printf("q%d ", j);
        }
        printf("}\n");
    }

    return 0;
}
