#include <iostream>
#include <vector>

using namespace std;


void generateTruthTable(int n, vector<int>& values, int index) {
    if (index == n) {
       
        for (int i = 0; i < n; ++i) {
            cout << values[i] << " ";
        }
        cout << endl;
        return;
    }

   
    values[index] = 0;
    generateTruthTable(n, values, index + 1);

   
    values[index] = 1;
    generateTruthTable(n, values, index + 1);
}

int main() {
    int n;

   
    cout << "Enter the number of propositional variables: ";
    cin >> n;

    
    vector<int> values(n);

   
    cout << "Truth Table:" << endl;
    generateTruthTable(n, values, 0);

    return 0;
}