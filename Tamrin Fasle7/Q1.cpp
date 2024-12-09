#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void deleteMax(Node*& head) {
    if (!head) return;

    Node* maxNode = head;
    Node* prevMax = nullptr;
    Node* current = head;
    Node* prev = nullptr;

    while (current) {
        if (current->data > maxNode->data) {
            maxNode = current;
            prevMax = prev;
        }
        prev = current;
        current = current->next;
    }

    if (!prevMax) {
        head = head->next;
    } else {
        prevMax->next = maxNode->next;
    }

    delete maxNode;
}

void push(Node*& head, int newData) {
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = head;
    head = newNode;
}

void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;

    push(head, 10);
    push(head, 20);
    push(head, 15);
    push(head, 30);
    push(head, 25);

    cout << "Initial list: ";
    printList(head);

    deleteMax(head);

    cout << "List after : ";
    printList(head);

    return 0;
}