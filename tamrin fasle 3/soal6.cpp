#include <iostream>
#include <iomanip>

using namespace std;

void khayamPascal(int n) {
    int triangle[n][n]; 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i) {
                triangle[i][j] = 1;
            } else {
                triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << setw(n - i) << " ";
        for (int j = 0; j <= i; j++) {
            cout << triangle[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter the number of rows for Pascal's triangle: ";
    cin >> n;
    khayamPascal(n);
    return 0;
}