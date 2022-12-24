#include <stdio.h>

int main()
{

    int arr[] = {2, 5, 7, 9, 13, 15, 17, 19, 20};
    int size = sizeof(arr) / sizeof(int);
    printf("%d\n", size);

    int low, mid, high;
    low = 0;
    high = size - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (size % 2 == 0)
        {
            printf("The middle index of the array is: ");
            printf("%d\n", mid);
        }
        if (size % 2 == 1)
        {
            printf("The middle indexes of the array is: ");
            printf("%d , ", mid);
            printf("%d", mid + 1);
        }
        return NULL;
    }

    return 0;
}
