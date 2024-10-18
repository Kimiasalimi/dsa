#include<iostream>

int divide(int a, int b) {
   
    if (b == 0) {
        std::cout << "Error: Division by zero." << std::endl;
        return 0; 
    }

 
    if (a == 0) {
        return 0;
    }

   
    if (a < 0) {
        return -divide(-a, b);
    }

   
    if (b > a) {
        return 0;
    }

   
    return 1 + divide(a - b, b);
}

int main() {
    int a, b;

    std::cout << "Enter numerator (a): ";
    std::cin >> a;
    std::cout << "Enter denominator (b): ";
    std::cin >> b;

    int result = divide(a, b);
    if (b != 0) { 
        std::cout << "Result of " << a << " / " << b << " is: " << result << std::endl;
    }

    return 0;
}