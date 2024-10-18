#include <iostream>
using namespace std;

int multiply(int a, int b) {
    
    if (b == 0) {
        return 0;
    }
    
    if (b < 0) {
        return -multiply(a, -b);
    }
   
    return a + multiply(a, b - 1);
}

int main() {
    int a, b;
    cout << "Enter two numbers (a and b): ";
    cin >> a >> b;

    int result = multiply(a, b);
    cout << "Result of " << a << " * " << b << " = " << result << endl;

    return 0;
}