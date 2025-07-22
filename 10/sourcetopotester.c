#include <stdio.h>
#include <stdlib.h>

int graph[100][100], isCyclic = 0, inDegree[100], res[100], ridx=0;

void topo(int n) {
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            if (graph[i][j])
                inDegree[j]++;

    int count = 0;
    int queue[100], front=0;

    while (count < n) {
        int flag = 1;
        int idx = 0;
        
        for (int i=0; i<n; i++) {
            if (inDegree[i] == 0) {
                queue[idx++] = i;
                flag = 0;
            }
        }
        if (flag) {
            isCyclic = 1;
            break;
        } else {
            for (int u=0; u<idx; u++) {
                for (int v=0; v<n; v++) {
                    if (graph[queue[u]][v] == 1)
                        inDegree[v] -= 1;
                }
                res[ridx++] = queue[u];
                inDegree[queue[u]] = -1;
                count++;
            }
        }
    }
}

void main() {
    int n;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++)
            scanf("%d", &graph[i][j]);
        inDegree[i] = 0;
    }

    topo(n);

    if (isCyclic) {
        printf("Graph is cyclic\n");
    } else {
        printf("Topological order:\n");
        printf("ridx: %d\n", ridx);
        for (int i = ridx-1; i > -1; i--) {
            printf("--> %c ", res[i] + 65);
        }
        printf("\n");
    }
}
