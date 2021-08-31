#include<iostream>
using namespace std;

int binarySearch(int arr[], int l, int r, int x) {
    while(l <= r) {
        int mid = l + (r-l)/2;
        // check if x is present at mid
        if(x == arr[mid]) {
            return mid;
        }else if(x < arr[mid]) { // if x is smaller, ignore the right half
            r = mid-1;
        }else {     // // if x is greater, ignore the left half
            l = mid+1;
        }
    }
    return -1;  // if x is not found, return -1
}   

int main() {
    // array must be sorted
    int arr[] = { 7, 12, 34, 36, 54, 76, 77, 89, 95, 98 };
    int n = sizeof(arr)/sizeof(arr[0]); // size of array
    int x = 95; // element to search for
    // binarySearch(array, left index, right index, element to search)
    int index = binarySearch(arr, 0, n-1, x); 
    if(index != -1) {
        cout << "element " << x << " is at index " << index << "\n";
    }else {
        cout << "element " << x << " is not found!";
    }

    return 0;
}
