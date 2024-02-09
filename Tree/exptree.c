#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct TreeNode {
    char data;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct StackNode {
    struct TreeNode* data;
    struct StackNode* next;
};

struct Stack {
    struct StackNode* top;
};

struct TreeNode* createNode(char data) {
    struct TreeNode* newnode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newnode->data = data;
    newnode->left = newnode->right = NULL;
    return newnode;
}

struct Stack* createStack() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = NULL;
    return stack;
}

void push(struct Stack* stack, struct TreeNode* data) {
    struct StackNode* newnode = (struct StackNode*)malloc(sizeof(struct StackNode));
    newnode->data = data;
    newnode->next = stack->top;
    stack->top = newnode;
}

struct TreeNode* pop(struct Stack* stack) {
    if (stack->top == NULL) {
        return NULL;
    }
    struct TreeNode* data = stack->top->data;
    struct StackNode* temp = stack->top;
    stack->top = stack->top->next;
    free(temp);
    return data;
}

void displayStack(struct Stack* stack) {
    printf("Stack: ");
    struct StackNode* current = stack->top;
    while (current != NULL) {
        printf("%c ", current->data->data);
        current = current->next;
    }
    printf("\n");
}

struct TreeNode* buildExpressionTree(char postfix[], struct Stack* stack) {
    int i;
    for (i = 0; postfix[i] != '\0'; ++i) {
        char symbol = postfix[i];
        printf("Processing %c\n", symbol);
        displayStack(stack);

        if (isalnum(symbol)) {
            struct TreeNode* operand = createNode(symbol);
            push(stack, operand);
        } else {
            struct TreeNode* t2 = pop(stack);
            struct TreeNode* t1 = pop(stack);

            struct TreeNode* operatorNode = createNode(symbol);
            operatorNode->left = t1;
            operatorNode->right = t2;
            push(stack, operatorNode);
        }
    }
    printf("Expression tree construction completed.\n");
    return pop(stack);
}

void inorderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%c ", root->data);
        inorderTraversal(root->right);
    }
}

struct TreeNode* findLeftSibling(struct TreeNode* root, char data) {
    if (root == NULL || root->right == NULL) {
        return NULL;
    }
    if (root->right->data == data) {
        return root->left;
    }
    struct TreeNode* leftSibling = findLeftSibling(root->left, data);
    if (leftSibling != NULL) {
        return leftSibling;
    }
    return findLeftSibling(root->right, data);
}

struct TreeNode* findAncestors(struct TreeNode* root, char data) {
    if (root == NULL || root->data == data) {
        return NULL;
    }

    struct TreeNode* ancestor = findAncestors(root->left, data);
    if (ancestor != NULL) {
        return root;
    }

    ancestor = findAncestors(root->right, data);
    if (ancestor != NULL) {
        return root;
    }

    return NULL;
}

int main() {
    char postfix[50];
    printf("Enter the postfix expression: ");
    scanf("%s", postfix);

    struct Stack* stack = createStack();
    struct TreeNode* root = buildExpressionTree(postfix, stack);

    int choice;
    char target;

    do {
        printf("\nMenu:\n");
        printf("1. Inorder Traversal\n");
        printf("2. Find Left Sibling\n");
        printf("3. Find Ancestors\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Inorder traversal: ");
                inorderTraversal(root);
                printf("\n");
                break;
            case 2:
                printf("Enter the target node: ");
                scanf(" %c", &target);
                struct TreeNode* leftSibling = findLeftSibling(root, target);
                printf("The left sibling of %c is: %c\n", target, (leftSibling != NULL) ? leftSibling->data : 'N');
                break;
            case 3:
                printf("Enter the target node: ");
                scanf(" %c", &target);
                struct TreeNode* ancestor = findAncestors(root, target);
                printf("Ancestors of %c: ", target);
                while (ancestor != NULL) {
                    printf("%c ", ancestor->data);
                    ancestor = findAncestors(root, ancestor->data);
                }
                printf("\n");
                break;
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 4);

    return 0;
}

