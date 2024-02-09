#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Book{
    char title[50];
    char author[50];
    char ISBN[20];
    int available; //1 if available, 0 if checked out
    struct Book *next;
};

struct Book *catalog = NULL; //linkedlist to store details of books in the library

void addBook(char title[],char author[],char ISBN[],int available){
    struct Book *Newbook = (struct Book*)malloc(sizeof(struct Book));
    strcpy(Newbook->title,title);
    strcpy(Newbook->author,author);
    strcpy(Newbook->ISBN,ISBN);
    Newbook->available = available;
    Newbook->next = catalog;
    catalog = Newbook;
}

void removeBook(char ISBN[]){
    struct Book *current = catalog;
    struct Book *prev = NULL;

    while(current!=NULL){
        if(strcmp(current->ISBN,ISBN)==0){
            if(prev==NULL){
                current = current->next;
            }
        else{
            prev->next = current->next;
            
        }
        free(current);
        }
         prev = current;
        current = current->next;
    }
    printf("\n book is not found in the catalog");
}

void searchBook(char query[]){
    struct Book *current = catalog;
    while(current!=NULL){
        if(strstr(current->title,query)!=NULL||strstr(current->author,query)!=NULL){
            printf("\nBook Title:%s\nAuthor : %s\nISBN :%s\navailability:%s",current->title,current->author,current->ISBN,current->available?"Available":"Checkedout");
        }
        current = current->next;
    }
}

void displayAvailableBooks(){
    struct Book *current = catalog;
    while(current!=NULL){
        if(current->available){
            printf("\nBook Title:%s \nAuthor :%s \nISBN: %s",current->title,current->author,current->ISBN);
        }
        current = current->next;
    }
}


void displayCheckedOutBooks(){
    struct Book *current = catalog;
    while(current!=NULL){
        if(!current->available){
            printf("\nBook Title:%s \nAuthor :%s \nISBN: %s",current->title,current->author,current->ISBN);
        }
        current = current->next;
    }
}

void checkOutBook(char ISBN[]){
    struct Book *current = catalog;
    while(current!=NULL){
        if(strcmp(current->ISBN,ISBN)==0){
            if(current->available){
                current->available = 0;
                printf("\nBook checked out succcessfully");
            }else{
                printf("\nBook is already checkedout");
            }
        }
        current = current->next;
    }
}

void returnBook(char ISBN[]){
    struct Book *current = catalog;
    while(current!=NULL){
        if(strcmp(current->ISBN,ISBN)==0){
            if(current->available){
                current->available = 1;
                printf("\nBook returned successfully");
            }
            else{
                printf("\nBook is already available");
            }
        }
        current = current->next;
    }
}

int main(){
    int choice;
    char buffer[100];
    do{
        printf("\n\n LIBRARY MANAGEMENT SYSTEM\n");
        printf("\n 1.Add a book");
        printf("\n 2.Remove a book");
        printf("\n 3.Search a book");
        printf("\n 4.Display the Available books");
        printf("\n 5.Display the checked out books");
        printf("\n 6.check out a book");
        printf("\n 7.return a book");
        printf("\n 8.exit");

        printf("\nenter your choice:");
        scanf("%d",&choice);

        switch(choice){
            case 1:
            printf("\nadd a title:");
            scanf("%s",buffer);
            char title[50];
            strcpy(title,buffer);

            printf("\n author:");
            scanf("%s",buffer);
            char author[50];
            strcpy(author,buffer);

            printf("\n ISBN:");
            scanf("%s",buffer);
            char ISBN[20];
            strcpy(ISBN,buffer);

            int available;
            printf("\n Is the book available?1 for available,0 for checked out):");
            scanf("%d",&available);

            addBook(title,author,ISBN,available);
            break;

            case 2:
            printf("\n enter a ISBN to remove the particular book:");
            scanf("%s",buffer);
            removeBook(buffer);
            break;

            case 3:
            printf("Enter a keyword to search for a book: ");
            scanf("%s", buffer);
            searchBook(buffer);
            break;

            case 4:
             printf("Available Books:\n");
             displayAvailableBooks();
             break;

            case 5:
             printf("Checked Out Books:\n");
             displayCheckedOutBooks();
             break;

             case 6:
             printf("Enter ISBN of the book to check out: ");
                scanf("%s", buffer);
                checkOutBook(buffer);
                break;
            
            case 7:
             printf("Enter ISBN of the book to return: ");
                scanf("%s", buffer);
                returnBook(buffer);
                break;

            case 8:
                printf("Exiting the program.\n");
                break;

             default:
                printf("Invalid choice. Please enter a valid option.\n");
                break;

        }
       
    }
     while(choice!=8);
}
