#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct TreeNode{
    char name[50];
    int phno;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* createNode(char name[50],int phno){
    struct TreeNode *newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    strcpy(newNode->name,name);
    newNode->phno = phno;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct TreeNode* insertNode(struct TreeNode *root,char name[50],int phno){
    if(root == NULL){
        return createNode(name,phno);
    }
    if(strcmp(name,root->name)<0){
        return insertNode(root->left,name,phno);    
    }
    else if(strcmp(name,root->name)>0){
        return insertNode(root->right,name,phno);
    }
    return root;
}

struct TreeNode* search(struct TreeNode* root,char name[50]){
    if(root == NULL){
        return NULL;
    }

    if(strcmp(root->name,name)==0){
           return root;
    }
    else if(strcmp(root->name,name)<0){
           return search(root->left,name);
    }
    else if(strcmp(root->name,name)>0){
           return search(root->right,name);
    }
    
    
    
}

void display(struct TreeNode *root){
   
    if(root != NULL){
        display(root->left);
        printf("\n%s - %d",root->name,root->phno);
        display(root->right);
    }
}

int main(){
    struct TreeNode *root = NULL;
    char name[50];
    int phno;
    int choice;

    while(1){
        printf("\n\n....Main Menu....\n1.Insert a contact \n2.Search \n3.Display contacts \n4.Exit");
        printf("\nEnter your choice : ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
            printf("\nEnter Name : ");
            scanf("%s",name);
            printf("\nEnter Phone Number : ");
            scanf("%d",&phno);
            root = insertNode(root,name,phno);
            break;

            case 2:
            printf("\nContact Name to search : ");
            scanf("%s",name);
            struct TreeNode *node = search(root,name);
            if(node == NULL){
                printf("\nNO results found");
            }
            else{
                printf("\n%s - %d",node->name,node->phno);
            }
            break;

            case 3:
            display(root);
            break;

            case 4:
            exit(0);

            default:
            printf("\n INVALID CHOICE");     
        }
    }
}