#include <stdio.h>

int search(int arr[],int size,int element){
    for (int i = 0; i < size; i++)
    {
        if (arr[i]==element)
        {
            printf("Found Element %d at %d index\n",element,i);
            return 1;
        }
    }
    return -1;
}
int main(){
    int arr[100]={1,2,3,4,5,6,7,8};
    int size = sizeof(arr)/sizeof(int);
    int element;
    printf("Enter the numeber you wanna search: ");
    scanf("%d",&element);
    if (search(arr,size,element)==-1)
    {
        printf("ERR_Element not found");
    }
    
return 0;
}