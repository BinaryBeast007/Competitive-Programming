#include<iostream>
using namespace std;

// function to print an array
void print(int arr[], int n) {
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}
// function to merge two sorted array
void merge(int leftArr[], int ln, int rightArr[], int rn, int arr[], int n) {
    int i = 0, j = 0, k = 0;
    // while both indices are valid, copy the smallest element to arr
    while(i<ln && j<rn) {
        if(leftArr[i] <= rightArr[j]) {
            arr[k++] = leftArr[i++];
        }else {
            arr[k++] = rightArr[j++];
        }
    }
    // copy the left over elements
    while(i<ln) {
        arr[k++] = leftArr[i++];
    }
    while(j<rn) {
       arr[k++] = rightArr[j++];
    }
}
void merge_sort(int arr[], int n) {
    if(n < 2) return;   // sorted
    // take out middle
    int mid = n/2;
    // create two array
    int leftArr[mid], rightArr[n-mid];
    // copy the left half
    for(int i=0; i<mid; i++) {
        leftArr[i] = arr[i];
    }
    // copy the right half
    for(int i=mid; i<n; i++) {
        rightArr[i-mid] = arr[i];
    }
    // call merge sort on left half
    merge_sort(leftArr, mid);
    // call merge sort on right half
    merge_sort(rightArr, n-mid);
    // merge left and right array
    merge(leftArr, mid, rightArr, n-mid, arr, n);
}

int main() {
    int arr[] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    print(arr, n);
    merge_sort(arr, n);
    print(arr, n);

    return 0;
}
