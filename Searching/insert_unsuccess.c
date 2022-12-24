#include <stdio.h>

void Display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int sortedInserted(int arr[], int size, int index, int capacity, int element)
{
    if (size > capacity)
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

int main()
{
    int arr[100] = {7, 8, 12, 27, 88};
    int size = 5;

    printf("The array before searching and insertion: ");
    Display(arr, size);

    printf("\n");

    int element, index;
    printf("Enter Element: ");
    scanf("%d", &element);

    printf("\n");

    printf("Enter index: ");
    scanf("%d", &index);

    printf("\n");

    // Searching the array linearly
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == element)
        {
            printf("The element %d is already in the array", arr[i]);
            printf("\n");
        }
        else
        {
            printf("Unsuccesfull Search\n");
            sortedInserted(arr, size, index, 100, element);
            size += 1;
            printf("The array after insertion: ");
            Display(arr, size);
        }
        return -1;
    }

    return 0;
}