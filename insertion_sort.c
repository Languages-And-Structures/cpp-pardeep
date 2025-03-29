#include <stdio.h>


void print_array(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insertion_sort(int *a,int n){
    int key;
    int j;
    for (int i = 0; i < n; i++)
    {
        key=a[i];
        j=i-1;
        while(j>=0 && a[j]>key){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }
}

int main(){
    int arr[]={2,3,45,7,85,4,8};
    int s =sizeof(arr)/sizeof(int);

    print_array(arr,s);
    insertion_sort(arr,s);
    print_array(arr,s);
     
return 0;
}