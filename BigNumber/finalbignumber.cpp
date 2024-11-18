#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

class BigNumber {
public:
    string digits;
    bool isNegative;
    BigNumber(const string& str = "0") {
        isNegative = (!str.empty() && str[0] == '-');
        digits = isNegative ? str.substr(1) : str;
        removeLeadingZeros();
    }

    void removeLeadingZeros() {
        size_t pos = 0;
        while (pos < digits.size() - 1 && digits[pos] == '0') {
            ++pos;
        }
        digits = digits.substr(pos);
        if (digits == "0") {
            isNegative = false;
        }
    }
    BigNumber add(const BigNumber& other) const {
        if (isNegative == other.isNegative) {
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

            BigNumber sumResult(result);
            sumResult.isNegative = isNegative;
            sumResult.removeLeadingZeros();
            return sumResult;
        }

        BigNumber absThis = *this;
        absThis.isNegative = false;
        BigNumber absOther = other;
        absOther.isNegative = false;

        if (absThis >= absOther) {
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

            BigNumber subResult(result);
            subResult.isNegative = isNegative;
            subResult.removeLeadingZeros();
            return subResult;
        }

        else {
            string result = "";
            int borrow = 0;
            int len1 = other.digits.size();
            int len2 = digits.size();

            for (int i = 0; i < len1; ++i) {
                int digit1 = other.digits[len1 - 1 - i] - '0';
                int digit2 = (i < len2) ? digits[len2 - 1 - i] - '0' : 0;
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

            BigNumber subResult(result);
            subResult.isNegative = other.isNegative;
            subResult.removeLeadingZeros();
            return subResult;
        }
    }
    BigNumber subtract(const BigNumber& other) const {
        if (isNegative) {
            BigNumber tempOther = other;
            tempOther.isNegative = !tempOther.isNegative;
            return add(tempOther);
        }
        else if (other.isNegative) {
            BigNumber tempOther = other;
            tempOther.isNegative = !tempOther.isNegative;
            return add(tempOther);
        }

        BigNumber absThis = *this;
        absThis.isNegative = false;
        BigNumber absOther = other;
        absOther.isNegative = false;

        if (absThis < absOther) { 
            BigNumber result = absOther.subtract(absThis);
            result.isNegative = true;
            return result;
        }

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

        BigNumber subResult(result);
        subResult.removeLeadingZeros();
        return subResult;
    }
    BigNumber multiply(const BigNumber& other) const {
        BigNumber product("0");
        int len1 = digits.size();
        int len2 = other.digits.size();

        for (int i = len1 - 1; i >= 0; --i) {
            string tempProduct = string(len1 - 1 - i, '0');
            int carry = 0;
            int digit1 = digits[i] - '0';
            
            for (int j = len2 - 1; j >= 0; --j) {
                int digit2 = other.digits[j] - '0';
                int productValue = digit1 * digit2 + carry;
                carry = productValue / 10;
                tempProduct = char((productValue % 10) + '0') + tempProduct;
            }

            if (carry) {
                tempProduct = char(carry + '0') + tempProduct;
            }

            BigNumber tempBigNumber(tempProduct);
            product = product.add(tempBigNumber);
        }

        product.isNegative = isNegative != other.isNegative;
        product.removeLeadingZeros();
        return product;
    }
    BigNumber divide(const BigNumber& other) const {
        if (other.digits == "0") {
            throw invalid_argument("Division by zero is undefined.");
        }

        BigNumber remainder("0");

        BigNumber absThis = *this;
        absThis.isNegative = false;
        BigNumber absOther = other;
        absOther.isNegative = false;

        string result = "";

        for (size_t i = 0; i < digits.size(); ++i) {
            remainder = remainder.multiply(BigNumber("10"));
            remainder = remainder.add(BigNumber(string(1, digits[i])));

            int count = 0;
            while (remainder >= absOther) {
                remainder = remainder.subtract(absOther);
                ++count;
            }

            if (!(result.empty() && count == 0)) {
                result += char(count + '0');
            }
        }

        bool isNegativeResult = (isNegative != other.isNegative);

        return BigNumber(isNegativeResult ? "-" + result : result);
    }
    BigNumber factorial() const {
        if (isNegative) {
            throw invalid_argument("Factorial is not defined for negative numbers.");
        }
        BigNumber result("1");
        BigNumber current("1");
        BigNumber one("1");
        while (current <= *this) {
            result = result * current;
            current = current + one;
        }
        return result;
    } 
    BigNumber karatsuba(const BigNumber& other) const {
        int len1 = digits.size();
        int len2 = other.digits.size();
        int maxLen = max(len1, len2);

        if (maxLen <= 1) {
            return (*this) * other;
        }

        int halfLen = (maxLen + 1) / 2;

        BigNumber high1 = BigNumber(digits.substr(0, len1 - halfLen));
        BigNumber low1 = BigNumber(digits.substr(len1 - halfLen));
        BigNumber high2 = BigNumber(other.digits.substr(0, len2 - halfLen));
        BigNumber low2 = BigNumber(other.digits.substr(len2 - halfLen));

        BigNumber z0 = low1.karatsuba(low2);
        BigNumber z1 = (low1.add(high1)).karatsuba(low2.add(high2));
        BigNumber z2 = high1.karatsuba(high2);

        z1 = z1.subtract(z2).subtract(z0);

        for (int i = 0; i < 2 * halfLen; ++i) {
            z2.digits += '0';
        }
        for (int i = 0; i < halfLen; ++i) {
            z1.digits += '0';
        }
        

        BigNumber result = z2.add(z1).add(z0);

        if (isNegative != other.isNegative) {
            result.isNegative = true;
        }
        result.removeLeadingZeros();
        return result;
    }
    BigNumber operator+(const BigNumber& other) const {
        return add(other);
    }

    BigNumber operator-(const BigNumber& other) const {
        return subtract(other);
    }

    BigNumber operator*(const BigNumber& other) const {
        return multiply(other);
    }

    BigNumber operator/(const BigNumber& other) const {
        return divide(other);
    }

    bool operator<(const BigNumber& other) const {
        if (isNegative != other.isNegative) {
            return isNegative;
        }

        if (digits.size() != other.digits.size()) {
            return (isNegative ? digits.size() > other.digits.size() : digits.size() < other.digits.size());
        }

        return (isNegative ? digits > other.digits : digits < other.digits);
    }
    bool operator<=(const BigNumber& other) const {
        return !(*this > other);
    }
    bool operator>(const BigNumber& other) const {
        if (isNegative != other.isNegative) {
            return other.isNegative;
        }

        if (!isNegative) {
            if (digits.size() != other.digits.size()) {
                return digits.size() > other.digits.size();
            }
            return digits > other.digits;
        }

        if (digits.size() != other.digits.size()) {
            return digits.size() < other.digits.size();
        }
        return digits < other.digits;
    }
    bool operator>=(const BigNumber& other) const {
        return !(*this < other);
    }
    bool operator==(const BigNumber& other) const {
        return isNegative == other.isNegative && digits == other.digits;
    }
    bool operator!=(const BigNumber& other) const {
        return !(*this == other);
    }
    void print() const {
        if (isNegative && digits != "0") {
            cout << "-";
        }
        cout << digits;
    }

    BigNumber shiftLeft(int n) const {
        if (n < 0) return shiftRight(-n);
        BigNumber result = *this;
        result.digits.append(n, '0');
        result.removeLeadingZeros();
        return result;
    }

    BigNumber shiftRight(int n) const {
        if (n < 0) return shiftLeft(-n);
        BigNumber result = *this;
        if (n >= result.digits.size()) {
            return BigNumber("0");
        }
        result.digits = result.digits.substr(0, result.digits.size() - n);
        result.removeLeadingZeros();
        return result;
    }
    BigNumber power(int exponent) const {
        if (exponent < 0) {
            throw invalid_argument("Exponent should be non-negative.");
        }
        if (exponent == 0) {
            return BigNumber("1");
        }
        if (exponent == 1) {
            return *this;
        }

        BigNumber base = *this;
        BigNumber result("1");

        while (exponent > 0) {
            if (exponent % 2 == 1) {
                result = result * base;
            }
            base = base * base;
            exponent /= 2;
        }

        return result;
    }
}; 
int main() {
    string input1, input2;
    int shiftAmount, exponent;
    cout << "Enter the first number: ";
    cin >> input1;
    cout << "Enter the second number: ";
    cin >> input2;

    BigNumber num1(input1);
    BigNumber num2(input2);

    cout << "Addition: ";
    (num1 + num2).print();
    cout << endl;

    cout << "Subtraction: ";
    (num1 - num2).print();
    cout << endl;

    cout << "Multiplication: ";
    (num1 * num2).print();
    cout << endl;

    cout << "Karatsuba Multiplication: ";
    num1.karatsuba(num2).print();
    cout << endl;

    try {
        cout << "Division: ";
        (num1 / num2).print();
        cout << endl;
    }
    catch (const exception& e) {
        cout << e.what() << endl;
    }

    cout << "Enter shift amount: ";
    cin >> shiftAmount;

    cout << "Shift Left: ";
    num1.shiftLeft(shiftAmount).print();
    cout << endl;

    cout << "Shift Right: ";
    num1.shiftRight(shiftAmount).print();
    cout << endl;

    cout << "Enter exponent for power operation: ";
    cin >> exponent;

    try {
        cout << "Power: ";
        num1.power(exponent).print();
        cout << endl;
    }
    catch (const exception& e) {
        cout << e.what() << endl;
    }
    cout << "Factorial :";
    num1.factorial().print();
    cout << endl;

    return 0;
}