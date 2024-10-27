#include <iostream>
using namespace std;

int combination(int n, int r) {
    if (r > n - r)
        r = n - r;
    int C = 1;
    for (int i = 0; i < r; i++) {
        C *= (n - i);
        C /= (i + 1);
    }
    return C;
}

int main() {
    int n,r;
    cout << "Enter tow number: ";
    cin >> n >> r;
    cout << "C(" << n << ", " << r << ") = " << combination(n, r) << endl;
    return 0;
}