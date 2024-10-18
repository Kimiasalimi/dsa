#include <iostream>
using namespace std;

double sumArray(int arr[], int n) {
    if (n == 0) {
        return 0;
    }
    return arr[n - 1] + sumArray(arr, n - 1);
}

double averageArray(int arr[], int n) {
    if (n == 0) return 0;
    double totalSum = sumArray(arr, n); 
    return totalSum / n; 
}

int main() {
    char choice;
    do {
        int n;
        cout << "Enter number of elements in the array: ";
        cin >> n;

        int* arr = new int[n];

        cout << "Enter array elements:n";
        for (int i = 0; i < n; i++) {
            cout << "Element " << i + 1 << ": ";
            cin >> arr[i];
        }

        double avg = averageArray(arr, n);
        cout << "Average is: " << avg << endl;

        delete[] arr;

        cout << "Do you want to enter another array? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    return 0;
}