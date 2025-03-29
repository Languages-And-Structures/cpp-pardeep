// used for adding two sorted arrays
#include <stdio.h>

void print_array(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void merge_sort(int *a,int *b,int *c,int n,int m){
    int i=0,j=0,k=0;
    while (i<n && j<m)
    {
        if (a[i]<b[j])
        {
            c[k]=a[i];
            i++,k++;
        }
        else
        {
            c[k]=b[j];
            j++,k++;
        }
    }
    while (i<n)
    {
        c[k]=a[i];
        i++,k++;
    }
    while (j<m)
    {
        c[k]=b[j];
        j++,k++;
    }
}

int main(){
    int a[]={1,2,3,4,5};
    int b[]={6,7,8,9,10};
    int n=sizeof(a)/sizeof(int);
    int m=sizeof(b)/sizeof(int);
    int c[n+m];

    
    merge_sort(a,b,c,n,m);
    print_array(c,n+m);
     
return 0;
}