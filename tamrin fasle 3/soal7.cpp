#include <iostream>
using namespace std;

bool isTranspose(int a[][100], int b[][100], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // بررسی می‌کنیم که آیا عنصر b[j][i] برابر است با a[i][j]
            if (a[i][j] != b[j][i]) {
                return false; // اگر هر عنصری متفاوت باشد، ترانهاده نیست
            }
        }
    }
    return true; // در صورتی که همه عناصر برابر باشند، ترانهاده است
}

int main() {
    int n;
    cout << "Enter the size of the matrices: ";
    cin >> n;
    
    int a[100][100], b[100][100];
    cout << "Enter elements of matrix a:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    cout << "Enter elements of matrix b:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> b[i][j];
        }
    }

    if (isTranspose(a, b, n)) {
        cout << "Matrix b is the transpose of matrix a.\n";
    } else {
        cout << "Matrix b is not the transpose of matrix a.\n";
    }

    return 0;
}