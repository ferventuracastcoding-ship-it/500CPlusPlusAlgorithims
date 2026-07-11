#include <iostream>
using namespace std;

int main() {

    int numbers[] = {5, 10, 20, 30, 40};

    int size = 5;

    int target = 30;

    bool found = false;


    for(int i = 0; i < size; i++) {

        if(numbers[i] == target) {

            cout << "Found at index "
                 << i << endl;

            found = true;

            break;
        }
    }


    if(!found)
        cout << "Not Found";


    return 0;
}
