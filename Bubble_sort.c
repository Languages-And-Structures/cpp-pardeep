#include <stdio.h>

void print_array(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bubble_sort(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        
        printf("Pass number - %d\n", i);
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                arr[j] = arr[j] ^ arr[j+1];
                arr[j+1] = arr[j] ^ arr[j+1];
                arr[j] = arr[j] ^ arr[j+1];
            }
        }
    }
}

void bubble_sort_adaptive(int *arr, int n)
{
    int issorted=0;
    for (int i = 0; i < n - 1; i++)
    {
        issorted = 1;
        printf("Pass number - %d\n", i);
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                // swap(arr[j],arr[j+1]);
                arr[j] = arr[j] ^ arr[j+1];
                arr[j+1] = arr[j] ^ arr[j+1];
                arr[j] = arr[j] ^ arr[j+1];
            }
            issorted = 0;
        }
        if (issorted)
        {
            return;
        }
    }
}

int main()
{
    int arr[] = {1, 5, 6, 4, 8, 3, 9, 6, 83};
    int n = 9;

    print_array(arr, n);
    bubble_sort(arr, n);
    print_array(arr, n);
    printf("\n");
    bubble_sort_adaptive(arr, n);
    print_array(arr, n);

    return 0;
}