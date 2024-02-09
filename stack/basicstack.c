/*#include<stdio.h>
#include<stdlib.h>

struct TreeNode{
    int data;
    struct TreeNode *next;
};

struct TreeNode *createNode(int data){
    struct TreeNode *newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct TreeNode *push(struct TreeNode *top,int data){
    struct TreeNode *newNode = createNode(data);
    if(top == NULL){
        top = newNode;
    }
    else{
        newNode->next = top;
        top = newNode;
    }
    return top;
}

struct TreeNode *pop(struct TreeNode *top){
    if(top == NULL){
        printf("\nUnder Flow");
    }
    else{
        struct TreeNode *temp = top;
        top = top->next;
        free(temp);
    }
    return top;
}

struct TreeNode *display(struct TreeNode *top){
    if(top == NULL){
        printf("\nNo elements in the stack");
    }
    else{
        struct TreeNode *current = top;
        while(current != NULL){
            printf("%d->",current->data);
            current = current->next;
        }
    }
    return top;
}

int peek(struct TreeNode *top){
    if(top == NULL){
        printf("\nStack is empty");
        return -1;
    }
    return top->data;
}

void isEmpty(struct TreeNode *top){
    if(top == NULL){
        printf("\nStack Empty");
    }
}

int main(){
    int data;
    struct TreeNode *stack = NULL;
    int choice;

    while(1){
        printf("\n1.push \n2.pop \n3.peek \n4.display \n5.exit");
        printf("\nEnter your choice :");
        scanf("%d",&choice);

        switch(choice){
            case 1:
            printf("\nEnter data to push: ");
            scanf("%d",&data);
            stack = push(stack,data);
            break;

            case 2: 
            stack = pop(stack);
            break;

            case 3:
            peek(stack);
            printf("\n The element at peek is %d",stack->data);
            break;

            case 4:
            display(stack);
            break;

            case 5:
            exit(0);

            default:
            printf("\nInvalid option");
        }
        


    }
}*/
/*
//array implementation
//push
#define MAX 30
int stack[MAX];
int top = -1;

//prototypes
void push(int stack[],int val);
int pop(int stack[]);
int peek(int stack[]);
void display(int stack[]);

void push(int stack[MAX],int val){
    if(top == MAX-1){
        printf("\nStack OVERFLOW");
    }
    else{
        top++;
        stack[top] = val;
    }
}

int pop(int stack[MAX]){
    if(top == -1){
        printf("\nStack UNDERFLOW");
    }
    else{
        int val = stack[top];
        top--;  
        return val;
    }      
}

int peek(int stack[MAX]){
    if(top == -1){
        printf("\n Stack is Empty");
    }
    else{
        return stack[top];
    }
}

void display(int stack[MAX]){
    if(top == -1){
        printf("\n Stack is empty");
    }
    else{
        for(int i = top;i>=0;i--){
            printf("\n %d->",stack[i]);
        }
    }
}*/

#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *createNode(int data){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
}

struct Node *push(struct Node *top,int data){
    struct Node *newNode = createNode(data);
    if(top == NULL){
        top = newNode;
    }
    else{
        newNode->next = top;
        top = newNode;
    }
    return top;

}

struct Node *pop(struct Node *top){
    if(top == NULL){
        printf("UnderFlow\n");
        return 0;
    }
    else{
        struct Node *temp = top;
        top = top->next;
        free(temp);
    }
    return top;
}

void display(struct Node *top){
    if(top == NULL){
        printf("No elements in the stack");
    }
    else{
        struct Node *current = top;
        while(current != NULL){
            printf("%d->",current->data);
            current = current->next;
        }
    }
}

int peek(struct Node *top){
    if(top == NULL){
        printf("Underflow");
        return 0;
    }
    else{
        return top->data;
    }
}

int main(){
    struct Node *stack = NULL;
    int choice,data;

    while(1){
        printf("\n1.push \n2.pop \n3.peek \n4.display \n5.exit");
        printf("\nEnter your choice :");
        scanf("%d",&choice);

        switch(choice){
            case 1: 
            printf("Enter your data :");
            scanf("%d",&data);
            stack = push(stack,data);
            printf("\n%d added sucessfully",data);
            break;

            case 2:
            stack = pop(stack);
            break;

            case 3:
            data = peek(stack);
            printf("The top element is %d ",data);
            break;

            case 4:
            display(stack);
            break;

            case 5:
            exit(0);

            default:
            printf("Invalid choice\n");      
        }
    }
}