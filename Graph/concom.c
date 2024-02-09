#include<stdio.h>
#include<stdlib.h>
#define MAX 100

void addEdge(int graph[MAX][MAX], int start, int end) {
    graph[start][end] = 1;
    graph[end][start] = 1;
    printf("The edge between %d and %d is added successfully\n", start, end);
}

void dfs(int graph[MAX][MAX], int numVertices, int vertex, int visited[MAX]) {
    visited[vertex] = 1;

    for (int i = 0; i < numVertices; i++) {
        if (graph[vertex][i] == 1 && !visited[i]) {
            dfs(graph, numVertices, i, visited);
        }
    }
}

int connectedComponents(int graph[MAX][MAX], int numVertices) {
    int connected_component = 0;
    int visited[MAX];

    for (int i = 0; i < numVertices; i++) {
        visited[i] = 0;
    }

    for (int i = 0; i < numVertices; i++) {
        if (!visited[i]) {
            dfs(graph, numVertices, i, visited);
            connected_component++;
        }
    }

    return connected_component;
}


int main() {
    int graph[MAX][MAX];
    int numVertices, numEdges;
    int v1, v2;

    printf("Enter the number of Vertices: ");
    scanf("%d", &numVertices);
    printf("Enter the number of Edges: ");
    scanf("%d", &numEdges);

    printf("Enter the edges:\n");
    for (int i = 0; i < numEdges; i++) {
        scanf("%d %d", &v1, &v2);
        addEdge(graph, v1, v2);
    }

    int numConnectedComponents = connectedComponents(graph, numVertices);
    printf("Number of Connected Components: %d\n", numConnectedComponents);

    return 0;
}
