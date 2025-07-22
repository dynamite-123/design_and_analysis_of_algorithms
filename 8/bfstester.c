#include <stdio.h>
#include <stdlib.h>


int graph[100][100], visited[100], isCyclic = 0;
int bfscount = 0;


void bfs(int n, int node) {
    int q[100], front = 0, rear = 0;

    q[rear++] = node;
    
    while (rear > front) {
        int cur = q[front++];
        bfscount++;
        visited[cur] = 1;
        printf("--> %c ", cur + 65);

        for (int i=0; i<n; i++) {
            if (graph[cur][i] == 1 && visited[i] == 0)
                q[rear++] = i;
            if (graph[cur][i] == 1 && visited[i] == 1)
                isCyclic = 1;
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

    bfs(n, 0);
    printf("\n");

    int connected = (n == bfscount)? 1: 0;

    for (int i=1; i<n; i++) {
        if (visited[i] == 0) {
            bfs(n, i);
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
