#include <stdio.h>
//sorted array only
int binarysearch(int arr[], int size, int element){
    int low=0,mid,high=size-1;
    while(low<=high){
    mid=(low+high)/2;
    if (arr[mid]==element)
    {
        return mid;
    }
    if (arr[mid]<element)
    {
       low = mid + 1;
    }
    else{
        high=mid - 1;
    }
    }
    return -1;
}

int main(){
    int arr[]={1,2,3,4,5,6,7,8};
    int size = sizeof(arr)/sizeof(int);
    int element;
    printf("Enter the number you wanna search: ");
    scanf("%d",&element); 
    int index=binarysearch(arr,size,element);
    if (index==-1)
    {
        printf("ERR_Element not found");
    }
    else{
        printf("Found Element %d at %d index\n",element,index);
    }
return 0;
}