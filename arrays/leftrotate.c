#include<stdio.h>
int main()
{
int n;
printf("enter n:");
scanf("%d",&n);

int arr[n];
printf("\narray elements:");
for(int i=0;i<n;i++){
scanf("%d",&arr[i]);
}

int temp = arr[0];
for(int i=1;i<n;i++){
arr[i-1] = arr[i];
}
arr[n-1] = temp;

printf("The array elements after left rotation is:");
for(int i=0;i<n;i++){
printf("\t%d",arr[i]);
}

}