#include <stdio.h>

void print_array(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void selection_sort(int *a, int n)
{
    int index_of_min;
    for (int i = 0; i < n - 1; i++)
    {
        index_of_min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[index_of_min])
            {
                index_of_min = j;
            }
        }
        // can't use XOR swapping cus of memory issues
        int temp = a[i];
        a[i] = a[index_of_min];
        a[index_of_min] = temp;
    }
}

int main()
{
    int arr[] = {1, 4, 5, 0, 5, 2, 789};
    int s = sizeof(arr) / sizeof(int);

    print_array(arr, s);
    selection_sort(arr, s);
    print_array(arr, s);

    return 0;
}