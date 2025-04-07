#include <stdio.h>

int indexdeletion(int arr[], int size, int capacity, int index)
{
    if (index >= capacity)
    {
        return -1;
    }
    for (int i = index; i < size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    return 1;
}

void display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("Element at %d is %d \n", i, arr[i]);
    }
}

int main()
{
    int arr[100] = {1, 2, 6, 77};
    int size = 4;
    int capacity = 100;
    int index = 0;
    if (indexdeletion(arr, size, capacity, index) == 1)
    {
        printf("deletion sucessfull \n");
        size -= 1;
        display(arr, size);
    }
    else
    {
        printf("!! deletion not sucessfull !! ");
    }
    return 0;
}