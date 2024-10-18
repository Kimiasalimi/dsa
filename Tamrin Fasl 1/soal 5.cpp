#include <iostream>
using namespace std;

int findMax(int arr[], int n) {
   
    if (n <= 0) {
        return 0; 
    }

    
    if (n == 1) {
        return arr[0];
    }

    
    int maxOfRest = findMax(arr, n - 1);
    return (arr[n - 1] > maxOfRest) ? arr[n - 1] : maxOfRest;
}

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

   
    int* arr = new int[n];

    cout << "Enter " << n << " elements:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int maxElement = findMax(arr, n);
    
    cout << "Maximum element in the array is: " << maxElement << endl;

   
    delete[] arr;

    return 0;
}