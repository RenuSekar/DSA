#include<stdio.h>

void swap(int *a,int *b){
int temp = *a;
*a = *b;
*b = temp;
}

void kthMax(int arr[],int n,int k)
{

for(int i=0;i<n-1;i++){
for(int j=0;j<n-i-1;j++){
if(arr[j]>arr[j+1])
{
swap(&arr[j],&arr[j+1]);
}
}
}

}

void KthMin(int arr[],int n,int k)
{

for(int i=0;i<n-1;i++){
for(int j=0;j<n-i-1;j++){
if(arr[j]>arr[j+1])
{
swap(&arr[j],&arr[j+1]);
}
}
}

}


int main(){
int n,k;

printf("enter the no of elements in the array:");
scanf("%d",&n);

int arr[n];

printf("enter the elements of the array:\n");
for(int i=0;i<n;i++)
{
scanf("%d",&arr[i]);
}

printf("enter the value of k:");
scanf("%d",&k);

if(k>0&&k<=n)
{
int kthMaxelement = KthMax(arr,n,k);
int kthMinelement = KthMin(arr,n,k);

printf("The %dth maximum element is: %d\n",k,kthMaxelement);
printf("The %dth minimum element is: %d\n",k,kthMinelement);
}

return 0;
}




