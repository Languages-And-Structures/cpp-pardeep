#include <stdio.h>

int indexinsertion(int arr[], int size, int element, int capacity, int index)
{
    if (size >= capacity)
    {
        return -1;
    }
    for (int i = size - 1; i >= index; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[index] = element;
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
    int element = 45;
    int capacity = 100;
    int index = 2;
    size += 1;
    if (indexinsertion(arr, size, element, capacity, index) == 1)
    {
        printf("insertion sucessful \n");
        display(arr, size);
    }
    else
    {
        printf("!! insertion not sucessful!! ");
    }
    return 0;
}