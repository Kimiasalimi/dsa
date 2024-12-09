#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void push(Node** headRef, int newData) {
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = *headRef;
    *headRef = newNode;
}

void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void sortList(Node** headRef) {
    if (*headRef == nullptr || (*headRef)->next == nullptr) return;

    bool swapped;
    do {
        swapped = false;
        Node** current = headRef;

        while ((*current)->next != nullptr) {
            Node* first = *current;
            Node* second = first->next;

            if (first->data > second->data) {
                first->next = second->next;
                second->next = first;
                *current = second;
                swapped = true;
            }
            current = &((*current)->next);
        }
    } while (swapped);
}

int main() {
    Node* head = nullptr;

    push(&head, 3);
    push(&head, 1);
    push(&head, 4);
    push(&head, 2);

    cout << "Original list: ";
    printList(head);

    sortList(&head);

    cout << "Sorted list: ";
    printList(head);

    return 0;
}
