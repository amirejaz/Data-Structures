#include<stdio.h>

void printArr(int *Arr, int n){
    for(int i =0; i< n; i++){
        printf("%d ", Arr[i]);
    }
}

void insertionSort(int *Arr, int n){
    for(int i = 1; i <= n-1; i++){
    int key = Arr[i];
    int j = i-1;
        while(j>=0 && Arr[j] > key){
            Arr[j+1] = Arr[j];
            j--;
        }
        Arr[j+1] = key;
    }
}

int main(){
    int Arr[] = {62,73,6,55,43,58,72,80};
    int n = 8;

    printArr(Arr, n);
    printf("\n");
    insertionSort(Arr, n);
    printArr(Arr, n);
}