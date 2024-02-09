#include<stdio.h>

void swap(int *a,int *b)
{
int temp;
temp = *a;
*a = *b;
*b = temp;
}

void sortArray(int arr[],int n)
{
int low = 0;
int mid = 0;
int high = n-1;

while(mid<=high){
switch(arr[mid])
{
case 0:
swap(&arr[low],&arr[mid]);
low++;
mid++;
break;

case 1:
mid++;
break;

case 2:
swap(&arr[mid],&arr[high]);
high--;
break;
}
}
}

void printArray(int arr[],int n)
{
for(int i=0;i<n;i++)
{
printf("%d",arr[i]);
}
}

int main()
{
int n;

printf("enter the no of elements in an array:");
scanf("%d",&n);

int arr[n];

printf("enter the elements of the array:\n");
for(int i=0;i<n;i++)
{
scanf("%d",&arr[i]);
}
sortArray(arr,n);
printf("sorted array :");
printArray(arr,n);
}
