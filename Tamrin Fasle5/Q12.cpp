#include <iostream>
#include <queue>
using namespace std;

class StackUsingQueues {
private:
    queue<int> q1, q2;

public:
    // افزودن عنصر به پشته
    void push(int x) {
        // افزودن به q2
        q2.push(x);

        // انتقال عناصر q1 به q2
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        // تعویض نام q1 و q2
        swap(q1, q2);
    }

    // حذف عنصر از پشته
    int pop() {
        if (q1.empty()) {
            throw runtime_error("پشته خالی است!");
        }
        int topElement = q1.front();
        q1.pop();
        return topElement;
    }

    // گرفتن عنصر بالای پشته
    int top() {
        if (q1.empty()) {
            throw runtime_error("پشته خالی است!");
        }
        return q1.front();
    }

    // بررسی خالی بودن پشته
    bool isEmpty() {
        return q1.empty();
    }
};

int main() {
    StackUsingQueues stack;

    // افزودن عناصر به پشته
    stack.push(1);
    stack.push(2);
    stack.push(3);

    // نمایش و حذف عناصر پشته
    cout << "Top: " << stack.top() << endl; // 3
    cout << "Pop: " << stack.pop() << endl; // 3
    cout << "Top: " << stack.top() << endl; // 2
    cout << "Pop: " << stack.pop() << endl; // 2
    cout << "Pop: " << stack.pop() << endl; // 1

    // بررسی خالی بودن پشته
    cout << "Is empty: " << (stack.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}
