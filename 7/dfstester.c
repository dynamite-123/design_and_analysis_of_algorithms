#include <stdio.h>
#include <stdlib.h>



int graph[100][100], visited[100], isCyclic = 0, dfscount = 0;

void dfs(int n, int node) {
    printf("--> %c ", node + 65);
    dfscount++;

    visited[node] = 1; //visiting 
    for (int i = 0; i < n; i++) {
        if (graph[node][i]) {
            if (visited[i] == 1) {
                isCyclic = 1;
            } else if (visited[i] == 0) {
                dfs(n, i);
            }
        }
    }
    visited[node] = 2; //visited
}

int main() {
    
    int n;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    int **graph = malloc(sizeof(int*) * n);

    for (int i=0; i<n; i++) 
        graph[i] = malloc(sizeof(int) * n);

    printf("Enter the adjacency matrix:\n");

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++)
            scanf("%d", &graph[i][j]);
        visited[i] = 0;
    }

    dfs(n, 0);
    printf("\n");

    int connected = (n == dfscount)? 1: 0;

    for (int i=1; i<n; i++) {
        if (visited[i] == 0) {
            dfs(n, i);
        }
        printf("\n");
    }

    if (isCyclic == 1) {
        printf("Graph is cyclic\n");
    } else {
        printf("Graph is acyclic\n");
    }

    if (connected == 1) {
        printf("Graph is connected\n");
    } else {
        printf("Graph is not connected\n");
    }
    return 0;
}
