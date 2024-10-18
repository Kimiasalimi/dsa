#include <iostream>
using namespace std;


void reverseArray(int arr[], int start, int end) {
   
    if (start >= end) {
        return;
    }
    
   
    swap(arr[start], arr[end]);
    
   
    reverseArray(arr, start + 1, end - 1);
}

int main() {
    int n;
    cout << "enter num of array ";
    cin >> n;

    int* arr = new int[n];

    cout << "enter array:";
    for (int i = 0; i < n; i++) {
        cout << "array num: " << i + 1 << ": ";
        cin >> arr[i];
    }

    cout << "array befor ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

   
    reverseArray(arr, 0, n - 1);

    cout << "array after: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr;

    return 0;
}