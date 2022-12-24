#include<stdio.h>

void printArr(int *Arr, int n){
    for(int i=0; i < n-1; i++){
        printf("%d ", Arr[i]);
    }
    printf("\n");
}

void selection_Sort(int *Arr, int n){
    int minIndex; 
    int temp;
    for(int i=0; i<n-1; i++){
        minIndex = i;
        for(int j=i+1; j<n; j++){
            if(Arr[j] < Arr[minIndex]){
                minIndex = j;
            }
        }
        temp = Arr[i];
        Arr[i] = Arr[minIndex];
        Arr[minIndex] = temp;
    }
}

int main(){
    int Arr[] = {62,73,6,55,43,58,72,80};
    int n = 8;

    printArr(Arr, n);
    printf("\n");
    selection_Sort(Arr, n);
    printArr(Arr, n);
}