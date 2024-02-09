/*#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct hash{
    int index;
    int key;
    char name[50];
};

struct hash_table{
    struct hash table[10];
};

int hashing(int key,int table_length){
    int index = (key)%(table_length);
    return index;
}
void insert(struct hash_table *stud_list,int table_length,int key,char name[50]){
    int index = hashing(key,table_length);
    while(stud_list->table[index].key != 0){
        index =  (index + 1)%table_length;
    }
    stud_list->table[index].key = key;
    strcpy(stud_list->table[index].name,name);
    printf("Insertion done\n");
}

void search(struct hash_table *stud_list,int table_length,int key){
    int index = hashing(key,table_length);
    while(stud_list->table[index].key != key){
        index = (index + 1)%table_length;
    }
    printf("%d -> %s found",stud_list->table[index].key,stud_list->table[index].name);
}

int main(){
    struct hash_table stud_list;
    char name[50];
    int key;
    int table_length;
    int choice;

    printf("Enter the table length : ");
    scanf("%d",&table_length);
    
    while(1){
        printf("1.Insert\n2.search\n3.exit\nEnter your choice:");
        scanf("%d ",&choice);
        
        switch(choice){
            case 1:
                printf("Enter your key and name: ");
                scanf("%d %s", &key, name);
                insert(&stud_list, table_length, key, name);
                break;

            case 2:
            printf("Enter the key to search :");
            scanf("%d\n",&key);
            search(&stud_list,table_length,key);
            break;

            case 3:
            exit(0);

            default:
            printf("INVALID CHOICE");

        }
    }

    return 0;
}*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct hash {
    int key;
    char name[50];
};

struct hash_table {
    struct hash table[10];
};

int hashing(int key, int table_length) {
    return key % table_length;
}

void insert(struct hash_table *stud_list, int table_length, int key, char name[50]) {
    int index = hashing(key, table_length);

    while (stud_list->table[index].key != 0) {
        index = (index + 1) % table_length;
    }

    stud_list->table[index].key = key;
    strcpy(stud_list->table[index].name, name);
    printf("Insertion done\n");
}

void search(struct hash_table *stud_list, int table_length, int key) {
    int index = hashing(key, table_length);

    while (stud_list->table[index].key != key) {
        index = (index + 1) % table_length;
    }

    printf("%d -> %s found\n", stud_list->table[index].key, stud_list->table[index].name);
}

int main() {
    struct hash_table stud_list;
    int key;
    char name[50];
    int table_length;
    int choice;

    printf("Enter the table length: ");
    scanf("%d", &table_length);

    while (1) {
        printf("1. Insert\n2. Search\n3. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter your key: ");
                scanf("%d", &key);
                printf("Enter name: ");
                scanf("%s", name);
                insert(&stud_list, table_length, key, name);
                break;

            case 2:
                printf("Enter the key to search: ");
                scanf("%d", &key);
                search(&stud_list, table_length, key);
                break;

            case 3:
                exit(0);

            default:
                printf("INVALID CHOICE\n");
        }
    }

    return 0;
}
