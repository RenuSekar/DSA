#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct student{
    char name[50];
    int reg_no;
    char gender[2];
    struct student* next;
};

struct student* createStudentDetails(char name[50],int reg_no,char gender[2]){
    struct student* newStudent = (struct student*)malloc(sizeof(struct student));
    strcpy(newStudent->name,name);
    newStudent->reg_no = reg_no;
    strcpy(newStudent->gender,gender);
    newStudent->next = NULL;
}

struct student *insertStudent(struct student** head,struct student* newStudent){
    if(head == NULL){
        *head = newStudent;
    }
    else{
        struct student* current = *head;
        while(current->next != NULL){
            current = current->next;
        }
        current->next = newStudent;
    }
    return head;
}

void splitByGender(struct student* head,struct student** maleList,struct student** femaleList){
    struct student* current = head;
    while(current!=NULL){
        if(*(current->gender) == 'M' || *(current->gender) == 'm'){
            insertStudent(maleList,createStudentDetails(current->name,current->reg_no,current->gender));
        }
        else{
            insertStudent(femaleList,createStudentDetails(current->name,current->reg_no,current->gender));
        }
        current = current->next;
    }
}

void display(struct student* head){
    struct student* current = head;
    printf("\nName : %s",current->name);
    printf("\nRegister No : %d",current->reg_no);
    printf("\nGender : %c",current->gender);
    printf("\n");
}

int main(){
    struct student *studentList = NULL;
    struct student *maleList = NULL;
    struct student *femaleList = NULL;
    char name[50];
    int reg_no;
    char gender[2];
  while(1){
    printf("\n 1.Insert ");
    printf("\n2.Diaplay StudentList");
    printf("\n3.SplitByGender");
    printf("\n4.Display MaleList");
    printf("\n5.Display FemaleList");
    printf("\n6.Exit");
    
    int choice;
    printf("\n Enter your choice :");
    scanf("%d",&choice);

    switch(choice){
        case 1:
        printf("\n Enter Student Name :");
        scanf("%s",name);
        printf("\n Enter Reg_no:");
        scanf("%d",&reg_no);
        printf("\n Enter gender :");
        scanf("%s",&gender);
        insertStudent(&studentList,createStudentDetails(name,reg_no,gender));
        break;

        case 2:
        display(studentList);
        break;

        case 3:
        splitByGender(studentList,&maleList,&femaleList);
        break;

        case 4:
        display(maleList);
        break;

        case 5:
        display(femaleList);
        break;
   
        case 6:
        exit(0);

        default:
        printf("\n INVALID CHOICE");

    }
  }  
}