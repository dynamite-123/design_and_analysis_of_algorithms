#include <stdio.h>
#include <stdlib.h>

int graph[100][100], visited[100], isCyclic = 0, dfscount = 0;
int res[100], idx = 0;

void dfs(int n, int node) {
    res[idx] = node;
    idx++;
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

void topo(int n) {
    
    for (int u=0; u<n; u++) {
        if (visited[u] == 0) {
            dfs(n, u);
        }
    }
}

int main() {
    
    int n;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++)
            scanf("%d", &graph[i][j]);
        visited[i] = 0;
    }

    topo(n);

    if (isCyclic == 1) {
        printf("Graph is cyclic\n");
    } else {
        printf("Topological order:\n");
        for (int i=n-1; i>-1; i--) {
            printf("--> %c ", res[i] + 65);
        }
        printf("\n");
    }

    return 0;
}
