#include <iostream>
using namespace std;

void hanoi(int n, char from, char aux, char to) {
    if (n == 1) {
        cout << from << " -> " << aux << endl;
        cout << aux << " -> " << to << endl;
        return;
    }
    
    hanoi(n - 1, from, aux, to);
    
    cout << from << " -> " << aux << endl;
    
    cout << aux << " -> " << to << endl;
    
    hanoi(n - 1, to, aux, from);
}

int main() {
    int n;
    cout << "Enter the number of disks: ";
    cin >> n;
    
    hanoi(n, 'S', 'A', 'D');
    
    return 0;
}