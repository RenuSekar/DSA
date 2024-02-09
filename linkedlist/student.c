#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>

struct student{
    char name[50];
    int reg_no;
    char gender;
    struct student *next;
};

struct student* create_student_details(char name[50],int reg_no,char gender){
    struct student *newstudent = (struct student*)malloc(sizeof(struct student));
    if(newstudent == NULL)
    printf("Memory allocation failed");
    else
    strcpy(newstudent->name,name);
    newstudent->reg_no = reg_no;
    newstudent->gender = gender;
    newstudent->next = NULL;
    return newstudent;
}

void insert_student(struct student *head,char name[50],int reg_no,char gender){
    struct student *newstudent = create_student_details(name,reg_no,gender);
    if(head == NULL){
        newstudent->next = head;
        head = newstudent;
    }
    else{
        struct student *current = head;
        while(current->next != NULL){
            current = current->next;
        }
        current->next = newstudent;
        printf("\n Insertion Success");
    }
}

void display(struct student *head){
    if(head == NULL){
        printf("\n No student details found");
    }
    else{
        struct student *current = head;
        while(current!=NULL){
            printf("Name : %s \n REG_NO : %d \n Gender : %c",current->name,current->reg_no,current->gender);
            current = current->next;
        }
    }
}
int main(){
    char name[50];
    int reg_no;
    char gender;
    struct student *head;
    
    while(1){
        printf("\n\n MAIN MENU \n\n");
        printf("\n 1.Insert a Student");
        printf("\n 2. Display the student list");
        printf("\n 3.exit");
    
        int choice;
        printf("\n Enter your choice:");
        scanf("%d",choice);


        switch(choice){
        case 1:
        printf("\n Enter name :");
        scanf("%s",name);
        printf("\n Enter reg_no:");
        scanf("%d",reg_no);
        printf("\n Enter gender:");
        scanf("%c",gender);
        insert_student(head,name,reg_no,gender);
        break;

        case 2:
        display(head);
        break;

        case 3:
        exit(0);

        default:
        printf("\n Invalid Option");
       }
    }
    

}