#include<stdio.h>
#include<stdlib.h>

#define MAX 100

void addEdge(int graph[MAX][MAX],int start,int end){
    graph[start][end] = 1;
    printf("The edge added between %d and %d\n",start,end);
}

void printGraph(int graph[MAX][MAX],int numVertices){
    for(int i=0;i<numVertices;i++){
        for(int j=0;j<numVertices;j++){
            printf("%d",graph[i][j]);
        }
        printf("\n");
    }
}

/*void indegree(int graph[MAX][MAX],int numVertices){
    for(int j=0;j<numVertices;j++){
        int indegree = 0;
        for(int i=0;i<numVertices;i++){
            if(graph[i][j] == 1){
                indegree++;
            }
        }
        printf("The indegree of %d is %d\n",j,indegree);
    }    
}

void outdegree(int graph[MAX][MAX],int numVertices){
    for(int i=0;i<numVertices;i++){
        int outdegree = 0;
        for(int j=0;j<numVertices;j++){
            if(graph[i][j] == 1){
                outdegree++;
            }
        }
        printf("The outdegree of %d is %d\n",i,outdegree);
    }
}*/

void degree(int graph[MAX][MAX],int numVertices){
    int vertices = 0;

        for(int i=0;i<numVertices;i++){
            int indegree = 0;
            int outdegree = 0;
            for(int j=0;j<numVertices;j++){
                if(graph[j][i] == 1){
                    indegree++;
                }
            }
            for(int j=0;j<numVertices;j++){
                if(graph[i][j] == 1){
                    outdegree++;
                }
            }
            int total = indegree + outdegree;
            printf("The degree of %d is %d\n",i,total);
        }
}

void dfs(int graph[MAX][MAX], int vertex, int numVertices)
{
    int stack[MAX];
    int top = -1;
    int visited[MAX];

    for (int i = 0; i < numVertices; i++)
    {
        visited[i] = 0;
    }

    stack[++top] = vertex;
    visited[vertex] = 1;

    while (top != -1)
    {
        int u = stack[top--];
        printf("%d ", u);

        for (int i = 0; i < numVertices; i++)
        {
            if (graph[u][i] == 1 && !visited[i])
            {
                stack[++top] = i;
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

/*void bfs(int graph[MAX][MAX],int vertex,int numVertices){
    int queue[MAX];
    int visited[MAX];
    int front,rear;
    front =0;
    rear = -1;

    for(int i = 0;i<numVertices;i++){
        visited[i] = 0;
    }

    queue[++rear] = vertex;
    visited[vertex] = 1;

    while(front != -1 && front <= rear){
       int u = queue[front++];
       printf("%d ",u);

       for(int i=0;i<numVertices;i++){
        if(graph[u][i] == 1 && !visited[i]){
            queue[rear++] = i;
            visited[i] = 1;
        }
       }
    }
}*/





int main(){
    int numVertices,numEdges,vertex;
    
    
    printf("Enter no of vertices:");
    scanf("%d",&numVertices);
    int visited[numVertices];

    int graph[MAX][MAX] = {0};

    printf("\nEnter no of edges:");
    scanf("%d",&numEdges);
    int v1,v2;
    printf("\nEnter the edges :");
    for(int i=0;i<numEdges;i++){
        scanf("%d %d",&v1,&v2);
        addEdge(graph,v1,v2);
    }
    printGraph(graph,numVertices);
   /* printf("INDEGREE :\n");
    indegree(graph,numVertices);
    printf("OUTDEGREE :\n");
    outdegree(graph,numVertices);*/
    degree(graph,numVertices);
    printf("Enter the start vertex:");
    scanf("%d",&vertex);
    dfs(graph,vertex,numVertices);
    //bfs(graph,vertex,numVertices);
    connected_components(graph,numVertices);
    return 0;
}