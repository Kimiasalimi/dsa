#include <iostream>
using namespace std;

double factorial(int n) {
    if (n == 0 || n == 1)
        return 1;
    return n * factorial(n - 1);
}

double sumOfSeries(int n) {
    if (n == 0)
        return 0;
    return (1.0 / factorial(n)) + sumOfSeries(n - 1);
}

int main() {
    int n;

   
    cout << "Enter the value of n: ";
    cin >> n;

   
    double result = sumOfSeries(n);
    cout << "Sum of the series is: " << result << endl;

    return 0;
}