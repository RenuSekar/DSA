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

int temp[n];
int d = 0; //temp index

// storing the non zeros in temp
for(i=0;i<n;i++){
if(arr[i]!=0){
temp[d]=arr[i];
d++;
}
}

//putting the non zeros in the array from temp
for(i=0;i<d;i++){
arr[i]=temp[i];
}

//filling the remaining space with zero
for(i=n-d;i<n;i++){
arr[i] = 0;
}

//printing array
printf("The updated array is:");
for(i=0;i<n;i++){
printf("\t%d",arr[i]);
}

}
