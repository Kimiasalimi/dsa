#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

int problem173(string s, int x){
    s.erase(remove(s.begin(), s.end(), ' '), s.end());

    if (s == "x") {
        return x;
    }

    bool isNumber = true;
    for (char c : s) {
        if (!isdigit(c)) {
            isNumber = false;
            break;
        }
    }

    if (isNumber) {
        return stoi(s);
    }

    int i = s.length() - 1;

    while (i >= 0) {
        if (s[i] == '+' || s[i] == '-') {
            if (s[i] == '+') {
                return problem173(s.substr(0, i), x) + problem173(s.substr(i + 1), x);
            } else {
                return problem173(s.substr(0, i), x) - problem173(s.substr(i + 1), x);
            }
        }
        i--;
    }

    i = s.length() - 1;

    while (i >= 0) {
        if (s[i] == '*' || s[i] == '/') {
            if (s[i] == '*') {
                return problem173(s.substr(0, i), x) * problem173(s.substr(i + 1), x);
            } else {
                return problem173(s.substr(0, i), x) / problem173(s.substr(i + 1), x);
            }
        }
        i--;
    }

    return 0;
}

int main() {
    int x;
    cin >> x;
    cout << problem173("x*x+x+x-x*x", x) << endl;
    return 0;
}