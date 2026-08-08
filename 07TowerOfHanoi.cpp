#include <iostream>
using namespace std;

// Recursive function to solve Tower of Hanoi
void towerOfHanoi(int n, char source, char auxiliary, char destination) {
    if (n == 1) {
        cout << "Move disk 1 from " << source
             << " to " << destination << endl;
        return;
    }

    // Move n-1 disks from source to auxiliary
    towerOfHanoi(n - 1, source, destination, auxiliary);

    // Move the largest disk
    cout << "Move disk " << n << " from "
         << source << " to " << destination << endl;

    // Move n-1 disks from auxiliary to destination
    towerOfHanoi(n - 1, auxiliary, source, destination);
}

int main() {
    int disks;

    cout << "Enter the number of disks: ";
    cin >> disks;

    cout << "\nSteps to solve Tower of Hanoi:\n";
    towerOfHanoi(disks, 'A', 'B', 'C');

    return 0;
}
