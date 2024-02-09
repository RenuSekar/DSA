#include<stdio.h>
#include<stdlib.h>

//node structure 
struct Node{
    int data;
    struct Node *next;
};

//Graph structure
struct Graph{
    int V;
    struct Node **adjNode;
};

struct Node *createNode(int data){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Graph *createGraph(int V){
    struct Graph *graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->adjNode = (struct Node**)malloc(V*sizeof(struct Node));

    //create an array 
    for(int i = 0;i<V;i++){
        graph->adjNode[i] = NULL;
    }
}

//add an edge from start to end
void add_edge(struct Graph *graph,int start,int end){
    
}