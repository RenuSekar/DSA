/*#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>

// Function to perform the Floyd-Warshall algorithm
void floydWarshall(int graph[100][100], int V) {
    int i, j, k;

    // Replace "INF" with a large value (represented as INT_MAX)
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            if (graph[i][j] == -1) {
                graph[i][j] = INT_MAX;
            }
        }
    }

    // Updating the solution matrix by considering all vertices
    for (k = 0; k < V; k++) {
        for (i = 0; i < V; i++) {
            for (j = 0; j < V; j++) {
                if (graph[i][k] != INT_MAX && graph[k][j] != INT_MAX &&
                    graph[i][k] + graph[k][j] < graph[i][j]) {
                    graph[i][j] = graph[i][k] + graph[k][j];
                }
            }
        }
    }
}

// Function to print the final distance matrix
void printSolution(int dist[100][100], int V) {
    printf("The shortest distances between every pair of vertices are:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INT_MAX) {
                printf("INF\t");
            } else {
                printf("%d\t", dist[i][j]);
            }
        }
        printf("\n");
    }
}

int main() {
    int V;
    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    int graph[100][100];

    // Input the adjacency matrix
    printf("Enter the adjacency matrix (INF for infinity):\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            char input[10];
            scanf("%s", input);
            if (strcmp(input, "INF") == 0) {
                graph[i][j] = INT_MAX;
            } else {
                graph[i][j] = atoi(input);
            }
        }
    }

    // Applying the Floyd-Warshall algorithm
    floydWarshall(graph, V);

    // Printing the final distance matrix
    printSolution(graph, V);

    return 0;
}*/

#include<stdio.h>
#include<stdlib.h>
#define MAX 100

void FloydMarshall(int graph[MAX][MAX],int numVertices){
    int i,j,k;
    for(int i=0;i<numVertices;i++){
        for(int j=0;j<numVertices;j++){
            if(graph[i][j] == -1){
                graph[i][j] = INF_V;
            }
        }
    }

    for(k=0;k<numVertices;k++){
        for(int i=0;i<numVertices;i++){
            for(int j=0;j<numVertices;j++){
                if(graph[i][k] != INF_V && graph[k][j] != INF_V) && graph[i][k] + graph[k][j] < graph[i][j]){
                    graph[i][j] = graph[i][k] + graph[k][j];
                }
            }
        }
    }
}

void printGraph(int graph[MAX][MAX],int numVertices){
    for(int i=0;i<numVertices;i++){
        for(int j=0;j<numVertices;j++){
            printf("%d ",graph[i][j]);
        }
        printf("\n");
    }
}