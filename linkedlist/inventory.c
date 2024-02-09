#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Item{
    int productID;
    char name[25];
    float price;
    int quantity;
    struct Item *next;
};

struct Item *head = NULL;
void addItem(int productID,char name[],float price,int quantity){
    struct Item *newItem = (struct Item*)malloc(sizeof(struct Item));
    newItem->productID = productID;
    strcpy(newItem->name,name);
    newItem->price = price;
    newItem->quantity = quantity;

    if(head==NULL||productID<head->productID){
        newItem->next = head;
        head = newItem;
    }
    else{
        struct Item *current = head;
        while(current->next!=NULL&&current->productID<productID){
            current = current->next;
        }
        newItem->next = current->next;
        current->next = newItem;
    }
 } 

void removeItem(int productID) {
    struct Item *current = head;
    struct Item *prev = NULL;

    while (current != NULL && current->productID != productID) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("\nItem with product ID %d not found.", productID);
        return;
    }

    if (prev == NULL) {
        // Item to remove is the first element in the list
        head = current->next;
    } else {
        prev->next = current->next;
    }

    free(current);
    printf("\nItem with product ID %d removed.", productID);
}


void display(){
    struct Item *current = head;
    while(current!=NULL){
        printf("\nProductID : %d",current->productID);
        printf("\nname : %s",current->name);
        printf("\nprice : %f",current->price);
        printf("\nquantity : %d",current->quantity);
        current = current->next;
    }
}

void updateQuantity(int productID,int newQuantity){
    struct Item *current = head;
    while(current!=NULL){
        if(current->productID == productID){
            current->quantity = newQuantity;
            printf("\n The quantity of %d is updated to %d",productID,newQuantity);
        }
        current = current->next;
    }
}

int main(){
    int choice,productID,quantity;
    char name[25];
    float price;
 while(1){
    printf("\n\n \\INVENTORY ITEMS\\ \n\n");
    printf("\n1.Add a item");
    printf("\n2.remove a item");
    printf("\n3.Display");
    printf("\n4.Update Quantity");
    printf("\n5.exit");

    printf("\n\n enter your choice:");
    scanf("%d",&choice);

    switch(choice){
        case 1:
        printf("\nEnter a productID:");
        scanf("%d",&productID);

        printf("\nEnter product Name:");
        scanf("%s",name);

        printf("\nEnter price:");
        scanf("%f",&price);

        printf("\nEnter the quantity:");
        scanf("%d",&quantity);

        addItem(productID,name,price,quantity);
        break;

        case 2:
        printf("\nEnter a productID to delete the item:");
        scanf("%d",&productID);

        removeItem(productID);
        break;

        case 3:
        display();
        break;

        case 4:
        printf("\n enter the productID whose quantity need to be updated:");
        scanf("%d",&productID);
        printf("\nEnter the new quantity:");
        scanf("%d",&quantity);
        updateQuantity(productID,quantity);
        break;

        case 5:
        exit(0);

        default:
        printf("\nINVALID OPTION");
    }
  } 
}