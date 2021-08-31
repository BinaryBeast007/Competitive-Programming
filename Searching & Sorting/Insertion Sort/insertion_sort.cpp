#include<iostream>
using namespace std;

void printArray(int arr[], int size) {
    for(int i=0; i<size; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}
void insertionSort(int arr[], int size) {
    for(int i=1; i<size; i++) {
        int current = arr[i];
        int j = i-1;
        while(j>=0 && arr[j] > current) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = current;
    }
}

int main() {
    int size = 10;
    int arr[size] = { 234, 34, 348, 934, 4, 12, 49, 34798, 23, 2 };
    cout << "initial array :\n";
    printArray(arr, size);
    insertionSort(arr, size);
    cout << "sorted array :\n";
    printArray(arr, size);

    return 0;
}
