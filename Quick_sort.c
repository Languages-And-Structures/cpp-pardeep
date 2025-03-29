#include <stdio.h>

void print_array(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int partition(int *a, int low, int high)
{
    int pivot = a[low];
    int i = low + 1;
    int j = high;
    do
    {
        while (a[i] <= pivot)
        {
            i++;
        }
        while (a[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    } while (i < j);
    int temp = a[low];
    a[low] = a[j];
    a[j] = temp;

    return j;
}

void quick_sort(int *a, int low, int high)
{
    int partition_index;
    if (low < high)
    {
        partition_index = partition(a, low, high);
        quick_sort(a, low, partition_index - 1);
        quick_sort(a, partition_index + 1, high);
    }
}
int main()
{
    int arr[] = {1, 4, 5, 0, 5, 2, 789};
    int s = sizeof(arr) / sizeof(int);

    print_array(arr, s);
    quick_sort(arr, 0, s - 1);
    print_array(arr, s);

    return 0;
}