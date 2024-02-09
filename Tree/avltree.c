#include<stdio.h>
#include<stdlib.h>

struct TreeNode{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};

int height(struct TreeNode *root){
    int leftheight,rightheight;
    if(root == NULL){
        return 0;
    }
    else{
        leftheight = height(root->left);
        rightheight = height(root->right);
        if(leftheight>rightheight){
            return leftheight+1;
        }
        else{
            return rightheight+1;
        }
    }

}

int BalanceFactor(struct TreeNode *root){
    int bf;
    if(root == NULL){
        return 0;
    }
    if(root != NULL){
        bf = height(root->left) - height(root->right);
    }
    return bf;
}

void TreeBalanced(struct TreeNode *root){
    int bf = BalanceFactor(root);
    if(bf == -1||bf == 0||bf ==1){
        printf("\nThe tree is Balanced");
    }
    else{
        printf("\nTree is not balanced");
    }
}

void Rotation(struct TreeNode *root){
    int bf = BalanceFactor(root);
    if(bf == -1||bf == 0||bf ==1){
        printf("\nNo Rotation Needed");
    }
    else if(bf>1){
        if(bf>1){
            printf("\nLeft-Left : Right Rotation Needed");  
        }
        else if(bf<-1){
            printf("\nLeft-Right : First Left,Then Right Rotation Needed");
        }
    }


}