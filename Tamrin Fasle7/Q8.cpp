#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

void push(Node** headRef, int newData) {
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->prev = nullptr;
    newNode->next = *headRef;

    if (*headRef != nullptr) {
        (*headRef)->prev = newNode;
    }

    *headRef = newNode;
}

void makeCircular(Node* head) {
    if (head == nullptr) return;

    Node* tail = head;
    while (tail->next != nullptr) {
        tail = tail->next;
    }

    tail->next = head;
    head->prev = tail;
}

void printCircularList(Node* head, int count) {
    if (head == nullptr) return;

    Node* temp = head;
    int printed = 0;

    do {
        cout << temp->data << " ";
        temp = temp->next;
        printed++;
    } while (temp != head && printed < count);

    cout << endl;
}

int main() {
    Node* head = nullptr;

    push(&head, 3);
    push(&head, 2);
    push(&head, 1);

    cout << "Original list: ";
    printCircularList(head, 3);

    makeCircular(head);

    cout << "Circular list: ";
    printCircularList(head, 6);

    return 0;
}
