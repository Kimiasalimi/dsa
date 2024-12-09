#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

void duplicateNodes(Node* head) {
    if (!head) return;

    Node* copyNode = new Node(head->data);

    copyNode->next = head->next;
    head->next = copyNode;

    duplicateNodes(copyNode->next);
}

void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void append(Node*& head, int newData) {
    Node* newNode = new Node(newData);
    if (!head) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;
}

int main() {
    Node* head = nullptr;

    append(head, 1);
    append(head, 2);
    append(head, 3);
    append(head, 4);

    cout << "initial list: ";
    printList(head);

    duplicateNodes(head);

    cout << "List after copy nodes: ";
    printList(head);

    return 0;
}