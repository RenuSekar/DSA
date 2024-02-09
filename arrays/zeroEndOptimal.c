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
int j = -1;
for(i=0;i<n;i++){
if(arr[i]==0){
j++;
arr[i]=arr[j];
break;
}
}

for(i=j+1;i<n;i++){
if(arr[i]!=0){
int temp = arr[i];
arr[i]=arr[j];
arr[j]=temp;
}
}

printf("the updated array is:");
for(i=0;i<n;i++){
printf("%d",arr[i]);
}
}