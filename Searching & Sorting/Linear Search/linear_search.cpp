#include<iostream>
using namespace std;

const int MAXN = 100;   // Max array size

int linearSearch(int arr[], int n, int element) {
    int index = -1;
    for(int i=0; i<n; i++) {
        if(arr[i] == element) {
            index = i;
            break;
        }
    }
    return index;
}

int main() {
    int arr[MAXN] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };
    int n = 10, element = 40;
    
    int index = linearSearch(arr, n, element);
    if(index != -1) {
        cout << "element " << element << " found at index " << index << "\n";
    }else {
        cout << "element not found\n";
    }

    return 0;
}
