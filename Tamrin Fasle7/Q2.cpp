#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void mergeLists(Node*& head1, Node*& head2, Node*& head) {
    if (!head1) {
        head = head2;
        return;
    }
    if (!head2) {
        head = head1;
        return;
    }

    if (head1->data <= head2->data) {
        head = head1;
        head1 = head1->next;
    } else {
        head = head2;
        head2 = head2->next;
    }

    Node* current = head;

    while (head1 && head2) {
        if (head1->data <= head2->data) {
            current->next = head1;
            head1 = head1->next;
        } else {
            current->next = head2;
            head2 = head2->next;
        }
        current = current->next;
    }

    if (head1) {
        current->next = head1;
    } else {
        current->next = head2;
    }

    head1 = nullptr;
    head2 = nullptr;
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
    Node* head1 = nullptr;
    Node* head2 = nullptr;

    push(head1, 8);
    push(head1, 5);
    push(head1, 3);
    push(head1, 1);

    push(head2, 9);
    push(head2, 7);
    push(head2, 4);
    push(head2, 2);

    cout << "first list: ";
    printList(head1);

    cout << "second list: ";
    printList(head2);

    Node* mergedHead = nullptr;
    mergeLists(head1, head2, mergedHead);

    cout << "merged list: ";
    printList(mergedHead);

    return 0;
}