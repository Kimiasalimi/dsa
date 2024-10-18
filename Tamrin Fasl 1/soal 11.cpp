#include <iostream>
using namespace std;

int main() {
    int n; 
    cout << "Enter the total amount in rials: ";
    cin >> n;

    for (int ten_rial = 0; ten_rial <= n / 10; ++ten_rial) {
        for (int five_rial = 0; five_rial <= n / 5; ++five_rial) {
            int remaining = n - (ten_rial * 10 + five_rial * 5);
            
            if (remaining >= 0 && remaining % 2 == 0) {
                int two_rial = remaining / 2; 
                cout << "Number of 10 rial coins: " << ten_rial 
                     << ", Number of 5 rial coins: " << five_rial 
                     << ", Number of 2 rial coins: " << two_rial << endl;
            }
        }
    }

    return 0;
}