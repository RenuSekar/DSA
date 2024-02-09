 #include<stdio.h>

void swap(int *a,int *b)
{
int temp;
temp = *a;
*a = *b;
*b = temp;
}

void moveNeg(int arr[],int n){
int pivot = 0;
int i = -1;
for(int j = 0;j<n;j++){
if(arr[j]<pivot){
i++;
swap(&arr[i],&arr[j]);
}
}
}

void printArray(int arr[],int n){
for(int i=0;i<n;i++){
printf("%d\t",arr[i]);
}
}

int main(){
int n;
printf("enter the no of elements in the array:");
scanf("%d",&n);

int arr[n];
printf("\n The elements of the array are:");
for(int i=0;i<n;i++){
scanf("%d",&arr[i]);
}

moveNeg(arr,n);
printf("Negatives moved to one side of the element:");
printArray(arr,n);
}
