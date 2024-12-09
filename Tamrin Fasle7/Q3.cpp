#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;

    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

class PriorityQueue {
private:
    Node* head;
    Node* tail;

public:
    PriorityQueue() : head(nullptr), tail(nullptr) {}

    void enqueue(int val) {
        Node* newNode = new Node(val);

        if (!tail) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    int dequeue() {
        if (!head) {
            throw runtime_error("queue is empty!!");
        }

        Node* minNode = head;
        Node* current = head;
        while (current) {
            if (current->data < minNode->data) {
                minNode = current;
            }
            current = current->next;
        }

        if (minNode == head) {
            head = head->next;
            if (head) head->prev = nullptr;
        } else if (minNode == tail) {
            tail = tail->prev;
            if (tail) tail->next = nullptr;
        } else {
            minNode->prev->next = minNode->next;
            minNode->next->prev = minNode->prev;
        }

        int minValue = minNode->data;
        delete minNode;
        return minValue;
    }

    bool isEmpty() {
        return head == nullptr;
    }
};
int main() {
    PriorityQueue pq;
    int n;

    cout << "Enter the number of integers: ";
    cin >> n;

    cout << "Enter numbers : ";
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        pq.enqueue(num);
    }

    cout << "Sorted numbers: ";
    while (!pq.isEmpty()) {
        cout << pq.dequeue() << " ";
    }
    cout << endl;

    return 0;
}