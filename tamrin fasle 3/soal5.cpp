#include <iostream>

using namespace std;

const int MAX_SIZE = 30;

void changeValue(int a[MAX_SIZE][MAX_SIZE], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                a[i][j] += 1;
            }

            if (i + j == n - 1) {
                a[i][j] -= 1;
            }

            if (i < j) {
                a[i][j] += 2;
            }

            if (i > j) {
                a[i][j] -= 2;
            }

            if (j < i) {
                a[i][j] += 3;
            }

            if (j > i) {
                a[i][j] -= 3;
            }
        }
    }
}

int main() {
    int n;
    cout << "Enter the size of the matrix (n x n, max 30): ";
    cin >> n;

    if (n < 1 || n > MAX_SIZE) {
        cout << "Invalid size. Please enter a size between 1 and " << MAX_SIZE << "." << endl;
        return 1;
    }
    int a[MAX_SIZE][MAX_SIZE] = {0};

    changeValue(a, n);

    cout << "Modified matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}