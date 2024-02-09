#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

struct TreeNode{
    char data;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct StackNode{
    struct TreeNode *data;
    struct StackNode *next;
};

struct Stack{
    struct StackNode *top;
};

struct TreeNode *createNode(char data){
    struct TreeNode *newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct StackNode *createStackNode(struct TreeNode *data){
    struct StackNode *newNode = (struct StackNode*)malloc(sizeof(struct StackNode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Stack *createStack(){
    struct Stack *stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = NULL;
    return stack;
}

void push(struct Stack *stack,struct TreeNode *data){
    struct StackNode *newNode = createStackNode(data);
    newNode->next = stack->top;
    stack->top = newNode;
}

struct TreeNode *pop(struct Stack *stack){
    if(stack == NULL){
        return NULL;
    }
    else{
        struct StackNode *temp = stack->top;
        struct TreeNode *data = temp->data;
        stack->top = stack->top->next;
        free(temp);
        return data;
    }
}

struct TreeNode *ExpressionTree(struct Stack *stack,char postfix[]){
    int len = strlen(postfix);
    for(int i=0; i<len;i++){
        if(isalnum(postfix[i])){
            struct TreeNode *operand = createNode(postfix[i]);
            push(stack,operand);
        }
        else{
            struct TreeNode *t2 = pop(stack);
            struct TreeNode *t1 = pop(stack);
            struct TreeNode *operator = createNode(postfix[i]);
            operator->left = t1;
            operator->right = t2;
            push(stack,operator);
        }
    }
    return pop(stack);
}

void Inorder(struct TreeNode *root){
    if( root != NULL){
        Inorder(root->left);
        printf(" %c",root->data);
        Inorder(root->right);
    }
}

int main(){
    char postfix[15];
    printf("Enter an postfix Expression:");
    scanf("%s",postfix);
    struct Stack *stack = createStack();
    struct TreeNode *tree = ExpressionTree(stack,postfix);
    Inorder(tree);
    return 0;
}