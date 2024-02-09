#include<stdio.h>
#include<stdlib.h>

struct TreeNode{
    char data;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *createNode(char data){
    struct TreeNode *newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct TreeNode *ExpressionTree(char postfix[]){
    struct TreeNode *stack[100];
    int top = -1;
    int i = 0;
    while(postfix[i] != '\0'){
        char ch = postfix[i];
        if(ch == '+'||ch == '-'||ch == '*'||ch == '%'||ch == '/' ){
          struct TreeNode *newNode = createNode(ch);
          newNode->right = stack[top--];
          newNode->left = stack[top--];
          stack[top++] = newNode;
        }
        else{
          stack[top++] = createNode(ch);
        }
        printf("\nStack position of %c : %d",postfix[i],i);
        i++;
    }
    return stack[top];
}

void Inordertraversal(struct TreeNode *root){
    if(root != NULL){
        Inordertraversal(root->left);
        printf("%c",root->data);
        Inordertraversal(root->right);
    }
}

struct TreeNode *find_sibling(struct TreeNode *root,struct TreeNode *node){
    if(root == NULL || root == node){
        return  NULL;
    }
    if(root->left == node && root->right != NULL){
        return root->right;
    }
    else if(root->right == node && root->left != NULL){
        return root->left;
    }
    else{
        struct TreeNode *sibling = find_sibling(root->left,node);
        if(sibling != NULL){
            return sibling;
        }
        else{
            return find_sibling(root->right,node);
        }
        
    }
}

void *find_ancestors(struct TreeNode *root,struct TreeNode *node){
    if(root == NULL ||root == node){
        return NULL;
    }
    if(root->left == node || root->right == node){
        printf("The ancestor is %c",root->data);
    }
    else{
        find_ancestors(root->left,node);
        find_ancestors(root->right,node);
    }
}

int main(){
    char postfix[15];
    char ch;
    
    printf("Enter a postfix equation :");
    scanf("%s",postfix);
    struct TreeNode *root = ExpressionTree(postfix);
    printf("\nThe inorder Traversal is:");
    Inordertraversal(root);
    struct TreeNode *node;
    while(1){
        printf("\n1.Left Sibling");
        printf("\n2.Right Sibiling");
        printf("\n3.Ancestors");
        printf("\n4.Exit");

        int choice;
        printf("\nEnter your choice:");
        scanf("%d",&choice);

        switch(choice){
            case 1:
            printf("\n Enter a char :");
            scanf("%c",&ch);
            node = createNode(ch);
            find_sibling(root,node);
            printf("\nThe left sibling of %c is %c",ch,root->left);
            break;

            case 2:
            printf("\n Enter a char :");
            scanf("%c",&ch);
            node = createNode(ch);
            struct TreeNode *sibling = find_sibling(root,node);
            printf("\nThe right sibling of %c is %c",ch,root->right);
            break;

            case 3:
            printf("\nEnter a char :");
            scanf("%c",&ch);
            find_ancestors(root,node);
            break;

            case 4:
            exit(0);

            default:
            printf("\nInvalid choice");
        }
    }
    return 0;
}
