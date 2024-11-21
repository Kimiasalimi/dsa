#include <iostream>
#include <queue>
using namespace std;

class StackUsingQueues {
private:
    queue<int> q1, q2;

public:
    void push(int x) {
        q2.push(x);
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }
    int pop() {
        if (q1.empty()) {
            throw runtime_error("Queues is empty");
        }
        int topElement = q1.front();
        q1.pop();
        return topElement;
    }
    int top() {
        if (q1.empty()) {
            throw runtime_error("Queues is empty");
        }
        return q1.front();
    }
    bool isEmpty() {
        return q1.empty();
    }
};

int main() {
    StackUsingQueues stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    cout << "Top: " << stack.top() << endl;
    cout << "Pop: " << stack.pop() << endl;
    cout << "Top: " << stack.top() << endl;
    cout << "Pop: " << stack.pop() << endl;
    cout << "Pop: " << stack.pop() << endl;
    cout << "Is empty: " << (stack.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}
