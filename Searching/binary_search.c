#include<stdio.h>

int binarySearch(int arr[], int size, int element){
    int low, mid, high;
    low = 0;
    high = size - 1;
    while(low<=high){
        int mid = (low + high)/2;
        if(arr[mid] == element){
            return mid;
        }
        
        if(arr[mid] < element){
            return low = mid + 1;
        }

        if(arr[mid] > element){
            return high = mid - 1;
        }
    }

    return -1;
}

int main(){
    // Sorted Array
    int arr[] = {2, 5, 7, 9, 13, 15, 17, 19, 1091};
    int size = sizeof(arr)/sizeof(int);
    int element = 19;
    int searchIndex = binarySearch(arr, size, element);
    printf("The element %d was found at index %d \n", element, searchIndex);
    return 0;

}
