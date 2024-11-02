#include <iostream>
#include <string>
using namespace std;

class BigNumber {
private:
    string digits;
    BigNumber(string str) : digits(str) {}

public:
    BigNumber(int number = 0) {
        if (number == 0) {
            digits = "0";
        }
        else {
            while (number > 0) {
                digits = char((number % 10) + '0') + digits;
                number /= 10;
            }
        }
    }

    BigNumber operator+(const BigNumber& other) const {
        string result = "";
        int carry = 0;
        int len1 = digits.size();
        int len2 = other.digits.size();
        int maxLen = max(len1, len2);

        for (int i = 0; i < maxLen || carry; ++i) {
            int digit1 = (i < len1) ? digits[len1 - 1 - i] - '0' : 0;
            int digit2 = (i < len2) ? other.digits[len2 - 1 - i] - '0' : 0;
            int sum = digit1 + digit2 + carry;
            carry = sum / 10;
            result = char((sum % 10) + '0') + result;
        }

        return BigNumber(result);
    }

    BigNumber operator-(const BigNumber& other) const {
        string result = "";
        int borrow = 0;
        int len1 = digits.size();
        int len2 = other.digits.size();

        for (int i = 0; i < len1; ++i) {
            int digit1 = digits[len1 - 1 - i] - '0';
            int digit2 = (i < len2) ? other.digits[len2 - 1 - i] - '0' : 0;
            int diff = digit1 - digit2 - borrow;
            if (diff < 0) {
                diff += 10;
                borrow = 1;
            }
            else {
                borrow = 0;
            }
            result = char(diff + '0') + result;
        }

        size_t pos = 0;
        while (pos < result.size() && result[pos] == '0') {
            ++pos;
        }

        if (pos == result.size()) {
            result = "0";
        }
        else {
            string newResult = "";
            for (size_t i = pos; i < result.size(); ++i) {
                newResult += result[i];
            }
            result = newResult;
        }

        return BigNumber(result);
    }

    BigNumber operator<<(int shift) const {
        return BigNumber(digits + string(shift, '0'));
    }

    BigNumber operator>>(int shift) const {
        if (shift >= (int)digits.size()) {
            return BigNumber(0);
        }
        string result = "";
        int newSize = digits.size() - shift;

        for (int i = 0; i < newSize; ++i) {
            result += digits[i];
        }

        return BigNumber(result);
    }

    void print() const {
        cout << digits;
    }
};

int main() {
    int input1, input2, shiftValue, choice;
    cout << "Enter the first number: ";
    cin >> input1;
    cout << "Enter the second number: ";
    cin >> input2;
    BigNumber num1(input1);
    BigNumber num2(input2);
    cout << "Which number would you like to shift? (1 for first number, 2 for second number): ";
    cin >> choice;
    cout << "Enter the number of positions to shift: ";
    cin >> shiftValue;
    BigNumber shifted;
    char shiftDirection;
    cout << "Enter shift direction (L for left, R for right): ";
    cin >> shiftDirection;
    if (choice == 1) {
        if (shiftDirection == 'L' || shiftDirection == 'l') {
            shifted = num1 << shiftValue;
        }
        else if (shiftDirection == 'R' || shiftDirection == 'r') {
            shifted = num1 >> shiftValue;
        }
        else {
            cout << "Invalid shift direction!" << endl;
            return 1;
        }
    }
    else if (choice == 2) {
        if (shiftDirection == 'L' || shiftDirection == 'l') {
            shifted = num2 << shiftValue;
        }
        else if (shiftDirection == 'R' || shiftDirection == 'r') {
            shifted = num2 >> shiftValue;
        }
        else {
            cout << "Invalid shift direction!" << endl;
            return 1;
        }
    }
    else {
        cout << "Invalid choice!" << endl;
        return 1;
    }
    BigNumber sum = num1 + num2;
    BigNumber diff = num1 - num2;
    cout << "Sum: ";
    sum.print();
    cout << endl;
    cout << "Difference: ";
    diff.print();
    cout << endl;
    cout << "Shifted Result: ";
    shifted.print();
    cout << endl;
    return 0;
}
