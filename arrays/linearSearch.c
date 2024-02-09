#include<stdio.h>
int main(){
int n;
int i;
printf("enter no of elements of the array:");
scanf("%d",&n);

int arr[n];
printf("The elements of the array are:");
for(i=0;i<n;i++){
scanf("%d",&arr[i]);
}

int num;
printf("\n enter the number to search:");
scanf("%d",&num);

for(i=0;i<n;i++){
if(arr[i]==num){
printf("%d is in %d position",num,i); 
}

}

}