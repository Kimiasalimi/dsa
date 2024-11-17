#include <iostream>
#include <stack>
#include <queue>
#include <unordered_set>
#include <vector>
using namespace std;

vector<int> findIntersection(stack<int> st, queue<int> q) {
    unordered_set<int> stackElements;
    vector<int> intersection;

    while (!st.empty()) {
        stackElements.insert(st.top());
        st.pop();
    }

    while (!q.empty()) {
        if (stackElements.find(q.front()) != stackElements.end()) {
            intersection.push_back(q.front());
        }
        q.pop();
    }

    return intersection;
}

int main() {
    stack<int> st;
    queue<int> q;

    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);

    vector<int> result = findIntersection(st, q);

    cout << "sharing elements: ";
    for (int num : result) {
        cout << num << " ";
    }

    return 0;
}
