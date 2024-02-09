#include<stdio.h>
int main(){
int n;

printf("enter the number of elements in an array:");
scanf("%d",&n);

int arr[n];
printf("enter %d elements:\n",n);
for(int i=0;i<n;i++)
{
printf("element %d :",i);
scanf("%d",&arr[i]);
}

int max = arr[0];
int min = arr[0];

for(int i=1;i<n;i++)
{
if(arr[i]>max)
{
max = arr[i];
}
if(arr[i]<min){
min = arr[i];
}
}

printf("maximum value : %d\n",max);
printf("minimum value : %d\n",min);
}
