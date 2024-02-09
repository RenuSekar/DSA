#include<stdio.h>
#include<stdlib.h>

/*//Structure for tree
struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root,int data){
    if(root == NULL){
        return createNode(data);
    }
    else if(data < root->data){
        root->left = insert(root->left,data);
    }
    else if(data > root->data){
        root->right = insert(root->right,data);
    }
    return root;
}

void inorderTraversal(struct Node* root){
    if(root != NULL){
        inorderTraversal(root->left);
        printf("%d",root->data);
        inorderTraversal(root->rigt);
    }
}

struct Node* minValueNode(struct Node* node){
    struct Node* current = node;
    while(current->left != NULL){
        current = current->left;
    }
    return current;
}*/

//structure of tree
struct TreeNode{
    struct TreeNode *left;
    int data;
    struct TreeNode *right;
};

struct TreeNode *createNode(int data){
    struct TreeNode *newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
}

struct TreeNode *insert(struct TreeNode *root,int data){
    if(root == NULL){
        return createNode(data);
    }
    if(data < root->data){
        root->left = insert(root->left,data);
    }
    else if(data > root->data){
        root->right = insert(root->right,data);
    }
    return root;
}

void inorderTraversal(struct TreeNode *root){
    if(root != NULL){
        inorderTraversal(root->left);
        printf("%d->",root->data);
        inorderTraversal(root->right);
    }
}

void preorderTraversal(struct TreeNode *root){
    if(root != NULL){
        printf("%d->",root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

void postorderTraversal(struct TreeNode *root){
    if(root != NULL){
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d->",root->data);
    }
}

//search for a element
int search(struct TreeNode *root,int data){
    if(root == NULL){
        printf("\nTree is empty");
        return 0;
    }
    while(root != NULL){
        if(root->data == data){
            return root;
        }
        else if(root->data > data){
            return search(root->left,data);
        }
        else if(root->data < data){
            return search(root->right,data);
        }
    }
}


int totalNode(struct TreeNode *root){
    if(root == NULL){
        return 0;
    }
    else{
        return totalNode(root->left)+totalNode(root->right)+1;
    }
}

int totalInternalNodes(struct TreeNode *root){
    if(root == NULL){
        return 0;
    }
    if(root->left == NULL && root->right == NULL){
        return 0;
    }
    else{
        return totalInternalNodes(root->left) + totalInternalNodes(root->right) + 1;
    }
}

int totalExternalNodes(struct TreeNode *root){
    if(root == NULL){
        return 0;
    }
    if(root->left == NULL && root->right == NULL){
        return 1;
    }
    else{
        return totalExternalNodes(root->left) + totalExternalNodes(root->right);
    }
}

int Height(struct TreeNode *root){
    int  leftHeight,rightHeight;
    if(root == NULL){
        return 0;
    }
    else{
        leftHeight = Height(root->left);
        rightHeight = Height(root->right);
      if(leftHeight > rightHeight){
        return leftHeight + 1;
       }
      else{
        return rightHeight + 1;
      }
    }
}

struct TreeNode *printInternalNodes(struct TreeNode *root){
    if(root == NULL){
        return NULL;
    }
    if(root->left == NULL && root->right == NULL){
        return NULL;
    }
    else{
        printf("%d->",root->data);
        printInternalNodes(root->left);
        printInternalNodes(root->right); 
    }
}

struct TreeNode *printLeafNodes(struct TreeNode *root){
    if(root == NULL){
        return NULL;
    }
    if(root->left == NULL && root->right == NULL){
        printf("%d->",root->data);
        
    }
        printLeafNodes(root->left);
        printLeafNodes(root->right);   
}

int findMin(struct TreeNode *root){
    if(root == NULL){
        return 0;
    }
    while(root->left != NULL){
        root = root->left;
    }
    return root;
}

int findMax(struct TreeNode *root){
    if(root == NULL){
        return NULL;
    }
    while(root->right != NULL){
        root = root->right;
    }
    return root;
}

