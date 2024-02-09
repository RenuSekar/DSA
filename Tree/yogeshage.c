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
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
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
        root->left=insertNode(root->left,name,age);
    }
    else if(root->age <= 18){
        root->right= insertNode(root->right,name,age);
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

int main() {
    struct TreeNode *root = NULL;
    char name[50];
    int age;
    int choice;

    do {
        printf("\nMenu:\n");
        printf("1. Insert Node\n");
        printf("2. Display Enrolled List\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Name: ");
                scanf("%s", name);
                printf("Enter Age: ");
                scanf("%d", &age);
                root = insertNode(root, name, age);
                break;
                
            case 2:
                printf("\nEnrolled List:\n");
                Traversal(root);
                break;

            case 3:
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 3);

    return 0;
}