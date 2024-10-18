#include <iostream>
#include <vector>

using namespace std;

void printSubsets(vector<int> &set, vector<int> &currentSubset, int index) {
    if (index == set.size()) {
        cout << "{ ";
        for (int num : currentSubset) {
            cout << num << " ";
        }
        cout << "}" << endl;
        return;
    }

    currentSubset.push_back(set[index]);
    printSubsets(set, currentSubset, index + 1);
    currentSubset.pop_back();
    printSubsets(set, currentSubset, index + 1);
}

int main() {
    int n;
    cout << "Enter the number of elements in the set: ";
    cin >> n;

    vector<int> set(n);
    cout << "Enter the elements of the set: ";
    for (int i = 0; i < n; i++) {
        cin >> set[i];
    }

    vector<int> currentSubset;
    printSubsets(set, currentSubset, 0);
    
    return 0;
}