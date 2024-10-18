#include <iostream>
#include <string>
using namespace std;

bool isDuplicate(string s) {
    int n = s.size();

    for (int i = 1; i <= n / 2; i++) {
        if (n % i == 0) {
            string sub = s.substr(0, i);
            string repeated = "";
            for (int j = 0; j < n / i; j++) {
                repeated += sub;
            }
            if (repeated == s) return true;
        }
    }
    return false;
}

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;
    
    if (isDuplicate(s)) {
        cout << "The string is a Duplicate." << endl;
    } else {
        cout << "The string is not a Duplicate." << endl;
    }

    return 0;
}
