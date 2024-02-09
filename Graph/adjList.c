#include<stdio.h>
#include<stdlib.h>

struct Node{
    int vertex;
    struct Node *adj_vertex;
    struct Node *next_vertex;    
};

//function prototypes
struct Node *create_node(int vertex);
struct Node *create_graph(struct Node *graph,int vertex);
struct Node *delete_list(struct Node *graph,int t_vertex);
struct Node *delete_adj(struct Node *adjacent,int vertex,int t_vertex);
struct Node *insert_list(struct Node *list);


struct Node *create_node(int vertex){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    if(newNode == NULL)
    printf("\nMemory allocation failed");
    else
    newNode->vertex = vertex;
    printf("%d created",newNode->vertex);
    newNode->adj_vertex = NULL;
    newNode->next_vertex = NULL;
    return newNode;
}

struct Node *create_graph(struct Node *graph,int vertex){
    struct Node *ptr = graph;
    if(ptr == NULL){
        printf("\nNUll graph so First Node");
        ptr = create_node(vertex);
        graph = ptr;
    }
    else{
        while(ptr->next_vertex != NULL){
            ptr = ptr->next_vertex;
        }
        printf("\nTraversing to the last node");
        ptr->next_vertex = create_node(vertex);
        ptr = ptr->next_vertex;
    }
    printf("\nEnter the adjacent vertices of %d(enter -1 to exit) : ",ptr->vertex);
    while(1){
        int data;
        scanf("%d",&data);
        if(data == -1)
        break;
        else
        ptr->adj_vertex = create_node(data);
        ptr = ptr->adj_vertex;
    }
    return graph;
}

int findNode(struct Node *graph,int t_vertex){
    struct Node *ptr = graph;
    while(ptr != NULL){
        if(ptr->vertex == t_vertex){
            return 1;
        }
        ptr = ptr->next_vertex;
    }
    return 0;
}

struct Node *insert_Adjacent(struct Node *list,int t_vertex,int vertex,int *flag){
    struct Node *ptr = list;
    if(ptr == NULL)
    *flag == 0;
    printf("\nAdjacent not found");
    while(ptr != NULL && ptr->vertex != t_vertex){
        ptr = ptr->next_vertex;
    }
    while(ptr->vertex == t_vertex){
        if(ptr->adj_vertex != NULL){
            ptr = ptr->adj_vertex;
        }
        else{
            ptr->adj_vertex = create_node(vertex);
        }
    }
}

struct Node *insert_list(struct Node *list){
    struct Node *ptr = list;
    if(ptr != NULL && ptr->next_vertex != NULL){
        ptr = ptr->next_vertex;
    }
    int data;
    
    Duplicate:
    printf("\nEnter the vertex : ");
    scanf("%d",&data);
    if(findNode(list,data)){
        printf("\nDuplicate vertex encountered");
        goto Duplicate;
    }
    struct Node *newNode = create_node(data);
    
}


