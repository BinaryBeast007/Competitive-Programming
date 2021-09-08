#include<iostream>
using namespace std;

void countingSort(int arr[], int n) {
    // finding the maximum element
    int maxElement = arr[0];
    for(int i=1; i<n; i++) {
        maxElement = max(arr[i], maxElement);
    }
    // counting the frequency
    int countArr[maxElement+1] = {0};
    for(int i=0; i<n; i++) {
        countArr[arr[i]]++;
    }
    // prefix sum of frequency array
    for(int i=1; i<n; i++) {
        countArr[i] += countArr[i-1];
    }
    // sorting the elements in a new array
    int sorted[n];
    for(int i=n-1; i>=0; i--) {
        sorted[--countArr[arr[i]]] = arr[i];  
    }
    // copying the sorted elements back to the original array
    for(int i=0; i<n; i++) {
        arr[i] = sorted[i];
    }
}
void printArray(int arr[], int n) {
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int main() {
    int arr[] = { 4, 6, 2, 8, 3, 1, 9, 1, 4, 2, 6 };
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << "initial array : ";
    printArray(arr, n);
    cout << "sorted array : ";
    countingSort(arr, n);
    printArray(arr, n);

    return 0;
}
