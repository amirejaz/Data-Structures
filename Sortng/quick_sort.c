#include <stdio.h>

void printArr(int *Arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        printf("%d ", Arr[i]);
    }
    printf("\n");
}

int partition(int Arr[], int low, int high)
{
    int pivot = Arr[low];
    int i = low + 1;
    int j = high;
    int temp;
    do
    {
        while (Arr[i] <= pivot)
        {
            i++;
        }

        while (Arr[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            temp = Arr[i];
            Arr[i] = Arr[j];
            Arr[j] = temp;
        }
    } while (i < j);

    // swapping low and j
    temp = Arr[low];
    Arr[low] = Arr[j];
    Arr[j] = temp;
    return j;
}

void quick_Sort(int Arr[], int low, int high)
{
    int partitionIndex; // index of pivot after partition
    if (low < high)
    {
        partitionIndex = partition(Arr, low, high);
        quick_Sort(Arr, low, partitionIndex - 1);
        quick_Sort(Arr, partitionIndex + 1, high);
    }
}

int main()
{
    int Arr[] = {62, 73, 6, 55, 43, 58, 72, 80};
    int n = 8;

    printArr(Arr, n);
    quick_Sort(Arr, 0, n - 1);
    printArr(Arr, n);
}