#include<iostream>
using namespace std;

int partition(int arr[], int start, int end) {
    // set partition index as start initially 
    int partitionIndex = start, pivot = arr[end];
    for(int i=start; i<end; i++) {
        if(arr[i] <= pivot) {
            swap(arr[i], arr[partitionIndex]); // swap if element is lesser than pivot
            partitionIndex++;
        }
    }
    swap(arr[partitionIndex], arr[end]); // swap pivot with element at partition index
    return partitionIndex;
}
void quickSort(int arr[], int start, int end) {
    if(start < end) {
        int partitionIndex = partition(arr, start, end); // calling partition 
        quickSort(arr, start, partitionIndex-1); 
        quickSort(arr, partitionIndex+1, end);
    }
}
void printArray(int arr[], int n) {
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int main() {
    int arr[] = { 8, 3, 6, 1, 2, 10, 5, 7, 9, 4 };
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "initial array : ";
    printArray(arr, n);
    quickSort(arr, 0, n-1);
    cout << "sorted array : ";
    printArray(arr, n);

    return 0;
}
