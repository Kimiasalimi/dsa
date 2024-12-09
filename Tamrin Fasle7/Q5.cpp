#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

class Stack {
private:
    Node* top;

public:
    Stack() : top(nullptr) {}

    bool isEmpty() {
        return top == nullptr;
    }

    void push(int val) {
        Node* newNode = new Node(val);
        newNode->next = top;
        top = newNode;
    }

    int pop() {
        if (isEmpty()) {
            throw runtime_error("stack is emty!");
        }

        Node* temp = top;
        int poppedValue = top->data;
        top = top->next;
        delete temp;
        return poppedValue;
    }

    int peek() {
        if (isEmpty()) {
            throw runtime_error(" stack is empty!");
        }
        return top->data;
    }

    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }
};

int main() {
    Stack stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    cout << "The top element of the stack" << stack.peek() << endl;

    cout << "delete: " << stack.pop() << endl;
    cout << "delete: " << stack.pop() << endl;

    cout << " is the stack empty? " << (stack.isEmpty() ? "no" : " yes") << endl;

    stack.push(40);
    cout << "The top element of the stack:  " << stack.peek() << endl;

    return 0;
}