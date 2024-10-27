#include <iostream>
#include <vector>

void changeValue(std::vector<std::vector<int>>& a, int n) {
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
    int n = 3;
    std::vector<std::vector<int>> a(n, std::vector<int>(n, 0));

    changeValue(a, n);

    for (const auto& row : a) {
        for (const auto& val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
