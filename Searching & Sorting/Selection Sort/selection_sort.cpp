#include<iostream>
using namespace std;

void printArray(int arr[], int size) {
    for(int i=0; i<size; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}
void selectionSort(int arr[], int size) {
    for(int i=0; i<size-1; i++) {
        int minIdx = i;
        for(int j=i+1; j<size; j++) {
            if(arr[minIdx] > arr[j]) {
                minIdx = j;
            }
        }
        swap(arr[i], arr[minIdx]);
    }
}

int main() {
    int size = 10;
    int arr[size] = { 234, 34, 348, 934, 4, 12, 49, 34798, 23, 2 };
    cout << "initial array :\n";
    printArray(arr, size);
    selectionSort(arr, size);
    cout << "sorted array :\n";
    printArray(arr, size);

    return 0;
}
