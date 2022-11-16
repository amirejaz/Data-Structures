#include <stdio.h>

void Display(int arr[], int n){
    // printf("Array: ");
    for(int i=0; i<n; i++){
        printf(" %d ", arr[i]);
    }
    printf("\n");
}

int sortedInserted(int arr[], int size, int index, int capacity, int element){
    if(size>capacity){
        return -1;
    }
    printf("Array after insertion: ");
    for(int i= size-1; i>=index; i--){
        arr[i + 1] = arr[i];
    }
    arr[index] = element;
    return 1;

}

void main(){
    int arr[100] = {7, 8, 12, 27, 88};
    int size = 5;
    Display(arr, size);

    int element = 56, index = 3;
    sortedInserted(arr, size, index, 100, element);
    size+=1;
    Display(arr, size);

    return 0;
}