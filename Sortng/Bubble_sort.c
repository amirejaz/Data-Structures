#include<stdio.h>
#include<stdlib.h>

void displaySorted_Arr(int *A, int n){
    for(int i = 0; i<n; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
}


void bubbleSort(int *A, int n){
    int isSorted = 0;
    int temp;
    for(int i=0; i< n-1; i++){
        printf("Sorting in pass: %d\n", i+1);
        isSorted = 1;
        for(int j =0; j<n-1-i;j++){
            if(A[j] > A[j+1]){
                temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
                // swap(A[j], A[j+1]);
                isSorted = 0;
            }
        }
        if(isSorted){
                return;
            }
    }
}

int main(){
    int A[] = {71,2,35,45,8,18,12};
    int n = 7;

    displaySorted_Arr(A, n);
    bubbleSort(A, n);
    displaySorted_Arr(A, n);

    
    
}