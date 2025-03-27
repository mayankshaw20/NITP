// 1. Write a C program to implement Linear search and find an element in an array.

#include<stdio.h>
#include<stdlib.h>


int linear_search(int arr[],int *size,int *target){
    int start= 0;
    int end = (*size)-1;
    for(int i =0;i<(*size);i++){
        if(arr[i]==(*target)){
            return i;
        }
    }
    return -1;
}
int main(){
    int arr[]={1,2,3,4,5,6,7,8,9,10};
    int size= sizeof(arr)/sizeof(arr[0]);
    int target;
    printf("Enter the target");
    scanf("%d",&target);
    int index=linear_search(arr,&size,&target);
    if(index==-1){
        printf("Element not found in the array");
    }
    else
        printf("Desire result found at the index :: %d",index);
    return 0;
}