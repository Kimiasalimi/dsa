#include <iostream>
#include <stack>
using namespace std;

class QueueUsingStacks {
private:
    stack<int> s1, s2;

public:
    void enqueue(int x) {
        s1.push(x);
    }

    int dequeue() {
        if (s2.empty()) {
            if (s1.empty()) {
                throw runtime_error("Queue is empty");
            }
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int topVal = s2.top();
        s2.pop();
        return topVal;
    }

    bool isEmpty() {
        return s1.empty() && s2.empty();
    }

    int front() {
        if (s2.empty()) {
            if (s1.empty()) {
                throw runtime_error("Queue is empty");
            }
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }
};

int main() {
    QueueUsingStacks q;

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    cout << "dequeue: " << q.dequeue() << endl;
    cout << "dequeue: " << q.dequeue() << endl;

    q.enqueue(4);

    cout << "Front: " << q.front() << endl;

    cout << "dequeue: " << q.dequeue() << endl;
    cout << "dequeue: " << q.dequeue() << endl;

    cout << "Is empty: " << (q.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}
