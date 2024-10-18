#include <iostream>
#include <vector>

using namespace std;

const int N = 8;

bool isSafe(const vector<int> &positions, int row, int col) {
    for (int i = 0; i < row; i++) {
        if (positions[i] == col || 
            positions[i] - i == col - row || 
            positions[i] + i == col + row) {
            return false;
        }
    }
    return true;
}

void placeQueens(vector<int> &positions, int row, int &solutionCount) {
    if (row == N) {
        solutionCount++;
        for (int r = 0; r < N; r++) {
            for (int c = 0; c < N; c++) {
                if (positions[r] == c)
                    cout << "Q ";
                else
                    cout << ". ";
            }
            cout << endl;
        }
        cout << endl;
        return;
    }

    for (int col = 0; col < N; col++) {
        if (isSafe(positions, row, col)) {
            positions[row] = col;
            placeQueens(positions, row + 1, solutionCount);
        }
    }
}

int main() {
    vector<int> positions(N);
    int solutionCount = 0;
    placeQueens(positions, 0, solutionCount);
    cout << "Total solutions: " << solutionCount << endl;
    return 0;
}