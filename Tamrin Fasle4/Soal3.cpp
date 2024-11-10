#include <iostream>
using namespace std;

class DualQueue {
private:
    int arr[100];
    int front1, rear1;
    int front2, rear2;
    int size;

public:
    DualQueue() {
        front1 = rear1 = -1;
        front2 = rear2 = 100;
        size = 0;
    }

    bool isFull() {
        return size == 100;
    }

    bool isEmpty1() {
        return front1 == -1;
    }

    bool isEmpty2() {
        return rear2 == 100;
    }

    void enqueue1(int value) {
        if (isFull()) {
            cout << "Both queues are full.\n";
            return;
        }
        if (front1 == -1) front1 = 0;
        arr[rear1] = value;
        rear1 = (rear1 + 1) % 100;
        size++;
    }

    void enqueue2(int value) {
        if (isFull()) {
            cout << "Both queues are full.\n";
            return;
        }
        if (front2 == 100) front2 = 99;
        arr[front2] = value;
        front2 = (front2 - 1 + 100) % 100;
        size++;
    }

    void dequeue1() {
        if (isEmpty1()) {
            cout << "Queue 1 is empty.\n";
            return;
        }
        cout << "Dequeued from Queue 1: " << arr[front1] << endl;
        front1 = (front1 + 1) % 100;
        size--;
        if (size == 0) {
            front1 = rear1 = -1;
        }
    }

    void dequeue2() {
        if (isEmpty2()) {
            cout << "Queue 2 is empty.\n";
            return;
        }
        cout << "Dequeued from Queue 2: " << arr[front2] << endl;
        front2 = (front2 - 1 + 100) % 100;
        size--;
        if (size == 0) {
            front2 = rear2 = 100;
        }
    }

    void display1() {
        if (isEmpty1()) {
            cout << "Queue 1 is empty.\n";
            return;
        }
        cout << "Elements in Queue 1: ";
        int i = front1;
        while (i != rear1) {
            cout << arr[i] << " ";
            i = (i + 1) % 100;
        }
        cout << arr[rear1] << endl;
    }

    void display2() {
        if (isEmpty2()) {
            cout << "Queue 2 is empty.\n";
            return;
        }
        cout << "Elements in Queue 2: ";
        int i = front2;
        while (i != (rear2 + 1) % 100) {
            cout << arr[i] << " ";
            i = (i - 1 + 100) % 100;
        }
        cout << endl;
    }
};

int main() {
    DualQueue dq;
    dq.enqueue1(10);
    dq.enqueue1(20);
    dq.enqueue2(30);
    dq.enqueue2(40);
    dq.display1();
    dq.display2();
    dq.dequeue1();
    dq.dequeue2();
    dq.display1();
    dq.display2();
    return 0;
}