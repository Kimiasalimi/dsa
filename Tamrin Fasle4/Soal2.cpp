#include <iostream>
#include <stdexcept>

using namespace std;

class PriorityQueue {
private:
static const int MAX_SIZE = 100;
pair<int, int> arr[MAX_SIZE];
int size;
void heapifyUp(int index) {
while (index > 0 && arr[index].first < arr[(index - 1) / 2].first) {
swap(arr[index], arr[(index - 1) / 2]);
index = (index - 1) / 2;
}
}

void heapifyDown(int index) {
int leftChild = 2 * index + 1;
int rightChild = 2 * index + 2;
int smallest = index;

if (leftChild < size && arr[leftChild].first < arr[smallest].first) {
smallest = leftChild;
}

if (rightChild < size && arr[rightChild].first < arr[smallest].first) {
smallest = rightChild;
}

if (smallest != index) {
swap(arr[index], arr[smallest]);
heapifyDown(smallest);
}
}

public:
PriorityQueue() : size(0) {}

void enqueue(int priority, int data) {
if (size >= MAX_SIZE) {
throw runtime_error("Queue is full");
}

arr[size] = {priority, data};
size++;

heapifyUp(size - 1);
}

void dequeue() {
if (size == 0) {
throw runtime_error("Queue is empty");
}

cout << "Dequeued: " << arr[0].second << " with priority " << arr[0].first << endl;

arr[0] = arr[size - 1];
size--;

heapifyDown(0);
}

void display() {
if (size == 0) {
cout << "Queue is empty." << endl;
return;
}

cout << "Priority Queue: ";
for (int i = 0; i < size; i++) {
cout << "(" << arr[i].second << ", " << arr[i].first << ") ";
}
cout << endl;
}

bool isEmpty() {
return size == 0;
}
};

int main() {
PriorityQueue pq;
int numElements, priority, data, choice;

cout << "How many elements do you want to add to the priority queue? ";
cin >> numElements;

for (int i = 0; i < numElements; i++) {
cout << "Enter priority for element " << i + 1 << ": ";
cin >> priority;
cout << "Enter data for element " << i + 1 << ": ";
cin >> data;
pq.enqueue(priority, data);
}

cout << "\nPriority Queue after inserting elements:\n";
pq.display();

do {
cout << "\nDo you want to dequeue an element? (1 = Yes, 0 = No): ";
cin >> choice;
if (choice == 1) {
pq.dequeue();
}
} while (choice == 1);

cout << "\nPriority Queue after dequeueing elements:\n";
pq.display();

return 0;
}