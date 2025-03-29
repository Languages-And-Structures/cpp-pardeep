//one of the fastest sorting algos but takes a lot of space

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

void print_array(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int maximum(int *a,int n){
    int max=INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (max<a[i])
        {
            max=a[i];
        }
        
    }
    return max;
}

void count_sort(int *a,int n){
    int max=maximum(a,n);

    int *count=(int*)malloc((max+1)* sizeof(int));

    for (int i = 0; i < max+1; i++)
    {
       count[i]=0;
    }
    
    for (int i = 0; i < n; i++)
    {
        count[a[i]]++;
    }
    int i,j;
    i=0;
    j=0;
    while (i<=max)
    {
        if (count[i]>0)
        {
            a[j]=i;
            count[i]--;
            j++;
        }
        else{
            i++;
        }
    } 
    free(count);
}

int main(){
    int arr[]={2,3,45,7,85,4,8};
    int s =sizeof(arr)/sizeof(int);

    print_array(arr,s);
    count_sort(arr,s);
    print_array(arr,s);


return 0;
}