#include <stdio.h>

void display(int arr[], int n){
    for(int i=0; i<n; i++){
        printf("%d\n", arr[i]);
    }
};

void main(){
    //code 1
    // int a[50], size, i;
    // printf("Enter the size of an array: ");
    // scanf("%d", &size);

    // printf("Enter the elements of an array: ");
    // for(i=0; i<size; i++){
    //     scanf("%d", &a[i]);
    // }

    // printf("The elements of an array are: ");
    // for(i=0; i<size; i++){
    //     printf("%d", a[i]);
    // }

    // code 2
    // int arr[5] = {1,5,7,8,9};
    // int i;

    // printf("The elements of an rray are: \n");
    // for(i=0; i<5; i++){
    //     printf("arr[%d] = %d, ", i, arr[i]);
    // }
   
    // code 3
    int arr[100] = {1,4,7,89};
    display(arr, 4);

    return 0;

}