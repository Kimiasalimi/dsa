#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the position of Fibonacci number: ";
    cin >> n;
    if (n <= 0) {
        cout << "Invalid input. Please enter a positive integer.";
        return 1;
    }
    if (n == 1 || n == 2) {
        cout << "Fibonacci number at position " << n << " is 1." << endl;
        return 0;
    }
    int fib[n];
    fib[0] = 1;
    fib[1] = 1;
    for (int i = 2; i < n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    cout << "Fibonacci number at position " << n << " is " << fib[n - 1] << "." << endl;
    return 0;
}