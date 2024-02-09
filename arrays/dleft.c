#include<stdio.h>
int main()
{
int n;
int i;
printf("enter n:");
scanf("%d",&n);

int arr[n];
printf("enter the elements of the array:");
for(i=0;i<n;i++)
{
scanf("%d",&arr[i]);
}

int d;
printf("enter d:");
scanf("%d",&d);

// storing the d number of elements in temp
int temp[d];
for(i=0;i<d;i++){
temp[i] = arr[i];
}

//shifting the remaining elements to the front
for(i=d;i<n;i++){
arr[i-d] = arr[i];
}

//putting the temp bacak
for(i=n-d;i<n;i++){
arr[i] = temp[i-(n-d)];
}

printf("The updated array is:");
for(i=0;i<n;i++){
printf("\t%d",arr[i]);
}

}

