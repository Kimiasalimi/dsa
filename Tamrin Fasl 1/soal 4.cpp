#include <iostream>
using namespace std;

int printBinary(int n) {
  
    if (n == 0) {
        return 0;
    }
    
  
    printBinary(n / 2);
   
    cout << n % 2;
}

int main() {
    int number;
    cout << "enter a number: ";
    cin >> number;

    cout << "binary: " << number << " : ";
    if (number == 0) {
        cout << "0";
    } else {
        printBinary(number);
    }
    cout << endl;

    return 0;
}