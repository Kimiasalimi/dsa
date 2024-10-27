#include <iostream>
using namespace std;

class BigNumber {
private:
    static const int MAX = 500;
    int digits[MAX];
    int size;

public:
    BigNumber() {
        size = 1;
        digits[0] = 1;
        for (int i = 1; i < MAX; i++) {
            digits[i] = 0;
        }
    }

    void multiply(int num) {
        int carry = 0;
        for (int i = 0; i < size; i++) {
            int product = digits[i] * num + carry;
            digits[i] = product % 10;
            carry = product / 10;
        }
        while (carry) {
            digits[size] = carry % 10;
            carry /= 10;
            size++;
        }
    }

    void print() const {
        for (int i = size - 1; i >= 0; i--) {
            cout << digits[i];
        }
        cout << endl;
    }
};

BigNumber fact(int n) {
    BigNumber result;
    for (int i = 2; i <= n; i++) {
        result.multiply(i);
    }
    return result;
}

int main() {
    int n;
    cout << "Please enter the number n: ";
    cin >> n;
    if (n < 0 || n > 100) {
        cout << "The number must be between 1 and 100." << endl;
    } else {
        BigNumber result = fact(n);
        cout << "The factorial of the number " << n << " is: ";
        result.print();
    }
    return 0;
}