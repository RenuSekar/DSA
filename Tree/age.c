#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct TreeNode{
    char name[50];
    int age;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *createNode(char name[50],int age){
    struct TreeNode *newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    strcpy(newNode->name,name);
    newNode->age = age;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct TreeNode *insertNode(struct TreeNode *root,char name[50],int age){
    if(root == NULL){
        return createNode(name,age);
    }
    if(root->age > 18){
        root->left =  insertNode(root->left,name,age);
    }
    else if(root->age < 18){
        root->right = insertNode(root->right,name,age);
    }
    return root;
}

void Traversal(struct TreeNode *root){
    if(root != NULL){
        Traversal(root->left);
        printf("\n %s : %d",root->name,root->age);
        Traversal(root->right);
    }
}

int main(){
    struct TreeNode *root = NULL;
    char name[50];
    int age;
    int key;

    while(1){
        
        printf("\nEnter Name : ");
        scanf("%s",name);
        printf("\nEnter age : ");
        scanf("%d",&age);
        root = insertNode(root,name,age);
        printf("\nEnrolled List :");
        Traversal(root);
        printf("\nTo continue enter any key (exit enter 0)\n");
        scanf("%d",&key);
        if(key == 0){
            exit(0);
        }
    }
}

