#include<stdlib.h>

void Display(int arr[], int n){
    for(int i=0; i<n; i++){
        printf("Array: %d ", arr[i]);
    }
    printf("\n");
}

int showDeletion(int arr[], int index, int size, int capacity){
    for(int i=index; i<=size-1; i++){  // also i<size
        arr[i] = arr[i+1];
    }
}


void main(){
    int arr[100] = {4,7,12,18,8};
    int size=5, capacity=100, index=2;
    Display(arr, size);
    showDeletion(arr, index, size, capacity);
    Display(arr, size);
    return 0;
}