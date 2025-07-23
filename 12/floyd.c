#include <stdio.h>
#include <stdlib.h>


int graph[100][100], visited[100], isCyclic = 0;
int bfscount = 0;

int graph[100][100];

void floyd(int n) {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int m1 = graph[i][j], m2 = graph[i][k] + graph[k][j];
                graph[i][j] = (m1 < m2)? m1: m2; 
            }
        }
    }

    printf("Shortest paths: \n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
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
    }

    floyd(n);
    return 0;
}
