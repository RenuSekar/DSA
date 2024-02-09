/*#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

void insert(struct Node **head,int data){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    if(newNode != NULL){
        newNode->data = data;
        newNode->next = NULL;
    

    struct Node *prev = NULL;
    struct Node *current = *head;

    //insert at beginning
    if(prev == NULL){
        newNode->next = *head;
        *head = newNode;
    }
    //insert at middle or end
    while(current != NULL){
        prev = current;
        current = current->next;
    }
    prev->next = newNode;
    newNode->next = current;
    }
    else{
        printf("\nMemory allocation failed");
    }
}

void display(struct Node *head){
    struct Node *current = head;
    while(current != NULL){
        printf("%d->",current->data);
        current = current->next;
    }
}
    int main() {
        struct Node *head = NULL;
        int data;
        while(1){
            printf("\n1.Insert");
            printf("\n2.display");
            printf("\n3.Exit");

            printf("\nenter choice:");
            int choice;
            scanf("%d",&choice);

            if(choice == 3){
                break;
            }

            switch(choice){
                case 1:
                printf("\nenter data:");
                scanf("%d",&data);
                insert(&head,data);
                break;
               
                case 2:
                display(head);
                break;

                case 3:
                exit(0);

                default:
                printf("\nINVALID option");

            }
        }
    }*/




/*void insertOnOrder(struct Node** head,int val){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;

    if(*head==NULL||val<(*head)->data){
        newNode->next = *head;
        *head = newNode;
    }
    else{
      struct Node *current = *head;
      while(current->next!=NULL&&current->next->data<val){
        current = current->next;
      }
      newNode->next = current->next;
      current->next = newNode;
      
    }
}

void removeDuplicates(struct Node* head){
    struct Node *current = head;
    while(current!=NULL && current->next!=NULL){
        if(current->data == current->next->data){
            struct Node* temp = current->next;
            current->next = current->next->next;
            free(temp);
        }
        else{
            current = current->next;
        }

    }
}

int sumOfUnique(struct Node *head){
    int sum = 0;
    struct Node *current = head;
    while(current!=NULL){
        int val = current->data;
        int isUnique = 1; //assumption
        struct Node *temp = head;
        while(temp!=current){
            if(temp->data == val){
                isUnique = 0;
                break;
            }
            temp =  temp->next;
        }
        if(isUnique){
          sum = sum + val;   
        }
        current = current->next;
    }
    return sum;
}

void display(struct Node *head){
    struct Node *current = head;
    while(current!= NULL){
        printf("%d->",current->data);
        current = current->next;
    }
    printf("\n");
}

int main(){
    struct Node *head = NULL;
    int n,val;
    printf("\nenter n");
    scanf("%d",&n);
     
    printf("\n enter the values of linkedlist:");
    for(int i = 0;i<n;i++){
        scanf("%d",&val);
        insertOnOrder(&head,val);
    }

    removeDuplicates(head);
    printf("\n after the removal of duplicates:");
    display(head);

    int sum = sumOfUnique(head);
    printf("\nSum of the unique values in the linkedlist is: %d",sum);

}*/

#include<stdio.h>
#include<stdlib.h>

struct TreeNode{
    int data;
    struct TreeNode *next;
};

void insertnode(struct TreeNode **head,int data){
    struct TreeNode *newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    if(newNode == NULL){
        printf("Memory Allocation failed");
        return;
    }
    newNode->data = data;
    newNode->next = NULL;

    if(*head == NULL){
        *head = newNode;
    }
    struct TreeNode *current = *head;
    while(current != NULL){
        current = current->next;
    }
    current->next = newNode;

}

void deleteNode(struct TreeNode *head,int data){
    if(head == NULL){
        printf("\n NO elements to delete");
    }
    struct TreeNode *current = head;
     struct TreeNode *temp = NULL;
    while(current != NULL){
        if(current->data == data){   
            current->next = temp;
            current = current->next->next;
            free(temp);
        }
        current = current->next;
    }
}

void display(struct TreeNode *head){
    if(head == NULL){
        printf("\nNo elements");
    }
    struct TreeNode *current = head;
    while(current != NULL){
        printf("%d->",current->data);
        current = current->next;
    }
}


int main(){
    int data;
    struct TreeNode *node = NULL;
    int choice;
 while(1){
    printf("\n1.Insert  \n2.Delete  \nDisplay  \n4.Exit");
    printf("\nEnter your choice :");
    scanf("%d",&choice);

    switch(choice){
        case 1:
        printf("\nEnter data: ");
        scanf("%d",&data);
        insertnode(&node,data);
        break;

        case 2:
        printf("\nEnter an element to delete :");
        scanf("%d",&data);
        deleteNode(node,data);
        break;

        case 3:
        display(node);
        break;

        case 4:
        exit(0);
    }

 }   
    
}