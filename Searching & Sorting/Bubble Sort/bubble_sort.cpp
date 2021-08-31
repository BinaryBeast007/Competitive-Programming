#include<iostream>
using namespace std;

void printArray(int arr[], int size) {
    for(int i=0; i<size; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}
void bubbleSort(int arr[], int size) {
    int counter = 1;
    while(counter < size) {
        bool swaped = false;
        for(int i=0; i<size-counter; i++) {
            if(arr[i] > arr[i+1]) {
                swap(arr[i], arr[i+1]);
                swaped = true;
            }
        }
        if(!swaped) {
            break;
        }
        counter++;
    }
}

int main() {
    int size = 10;
    int arr[size] = { 234, 34, 348, 934, 4, 12, 49, 34798, 23, 2 };
    cout << "initial array :\n";
    printArray(arr, size);
    bubbleSort(arr, size);
    cout << "sorted array :\n";
    printArray(arr, size);

    return 0;
}
