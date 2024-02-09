#include<stdio.h>
#include<stdlib.h>

struct Node{
    int vertex;
    struct Node *adj;
    struct Node *next;
};

struct Node *createNode(int vertex){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = vertex;
    newNode->adj = NULL;
    newNode->next = NULL;
    return newNode;
}

struct Node *createGraph(struct Node *graph,int vertex){
    struct Node *ptr = graph;
    if(ptr == NULL){
        ptr = createNode(vertex);
        graph = ptr;
        printf("The vertex %d is added as the first vertex\n",vertex);
        return graph;
    }
    else{
        while(ptr->next != NULL){
           ptr = ptr->next;
        }
        ptr->next = createNode(vertex);
        ptr = ptr->next;
        printf("The vertex %d is added at the end",vertex);
        return graph;
    }
}
struct Node *addEdge(struct Node *graph,int v1,int v2){
    
}

int main(){
    struct Node *graph = NULL;
    int choice;
    int vertex;
    while(1){
        printf("1.ADD vertex\n");
        printf("0.EXIT\n");

        printf("Enter your choice:");
        scanf("%d",&choice);

        switch(choice){
            case 1:
            printf("Add your vertex:");
            scanf("%d",&vertex);
            createGraph(graph,vertex);
            break;

            case 0:
            exit(0);
           
            default:
            printf("INVALID CHOICE\n");
        }
    }
    return 0;
}

