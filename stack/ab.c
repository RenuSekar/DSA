#include<stdio.h>
#include<stdlib.h>

struct StackNode{
    char data;
    struct StackNode *next;
};

struct Stack{
    struct StackNode *top;
};

struct StackNode *createStackNode(char data){
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

void push(struct Stack *stack,char data){
    struct StackNode *newNode = createStackNode(data);
    newNode->next = stack->top;
    stack->top = newNode;
}

char pop(struct Stack *stack){
    if(stack->top == NULL){
        return '\0';
    }
    else{
        struct StackNode *temp = stack->top;
        char data = temp->data;
        stack->top = stack->top->next;
        free(temp);
        return data;
    }
}

int isValidString(char str[]){
    struct Stack *stack = createStack();
    int b_count = 0;
    int a_count = 0;

    int i = 0;
    while(str[i]!='\0'){
        if(str[i] == 'b'){
            push(stack,str[i]);
            b_count++;
        }
        else if(str[i]=='a'){
            char popped = pop(stack);
            a_count++;
            if(popped != 'b'){
                return 0;
            }
        }
        else{
            return 0;
        }
        i++;
    }
    if(b_count >= a_count){
        return 0;
    }
    return 1;
}

int main(){
    char str[17];
    printf("\nEnter a string :");
    scanf("%s",str);
    if(isValidString(str)){
        printf("\nIt is a valid string");
    }
    else{
        printf("\nInvalid string");
    }
}