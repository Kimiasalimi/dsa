#include <iostream>
using namespace std; 

int factorial(int n) {
    if (n == 0 || n == 1)
        return 1;
    return n * factorial(n - 1);
}

int sumOfSeries(int n) {
    if (n == 0)
        return 0;
    return factorial(n) + sumOfSeries(n - 1);
}

int main() {
    int n;

   
    cout << "Enter the value of n: ";
    cin >> n;

   
    int result = sumOfSeries(n);
    cout << "Sum of the series is: " << result << endl;

    return 0;
}