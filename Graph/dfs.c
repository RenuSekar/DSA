#include<stdio.h>
#include<stdlib.h>
#define MAX 100
void addEdge(int graph[MAX][MAX],int start,int end){
    graph[start][end] = 1;
    graph[end][start] = 1;
    printf("The edge between %d and %d is added sucessfully\n",start,end);
}

void dfs(int graph[MAX][MAX],int numVertices,int vertex){
    int stack[MAX];
    int top = -1;
    int visited[MAX];
    for(int i=0;i<numVertices;i++){
        visited[i] = 0;
    }
    
    stack[++top] = vertex;
    visited[vertex] = 1;
    
    while(top != -1){
        int u = stack[top--];
        printf("%d",u);
        for(int i=0;i<numVertices;i++){
            if(graph[u][i] == 1 && !visited[i]){
                stack[++top]  = i;
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

void bfs(int graph[MAX][MAX],int numVertices,int vertex){
    int queue[MAX];
    int rear = -1;
    int front = 0;
    int visited[MAX];

    for(int i=0;i<numVertices;i++){
        visited[i] = 0;
    }

    queue[++rear] = vertex;
    visited[vertex] = 1;

    while(front <= rear){
        int u = queue[front++];
        printf("%d",u);
        for(int i=0;i<numVertices;i++){
            if(graph[u][i] == 1 && !visited[i]){
                queue[++rear] = i;
                visited[i] = 1;
            }
        }
    }
}

void connected_components(int graph[MAX][MAX],int numVertices){
    int connected_component = 0;
    int visited[MAX];
    for(int i=0;i<numVertices;i++){
        visited[i] = 0;
    }
    for(int i=0;i<numVertices;i++){
        if(!visited[i]){
            dfs(graph,numVertices,i);
            
            connected_component++;
        }
    }
    printf("Connected components : %d",connected_component);
}

int main(){
    int graph[MAX][MAX];
    int numVertices,numEdges;
    int v1,v2;

    printf("Enter no of Vertices :");
    scanf("%d",&numVertices);
    printf("\nEnter the no of edges :");
    scanf("%d",&numEdges);
    printf("\nEnter the edges :");
    for(int i=0;i<numEdges;i++){
        scanf("%d %d",&v1,&v2);
        addEdge(graph,v1,v2);
    }
    int vertex;
   // printf("Enter the vertex for dfs :");
    //scanf("%d",&vertex);
    //dfs(graph,numVertices,vertex);
    //bfs(graph,numVertices,vertex);
    connected_components(graph,numVertices);
    return 0;
}