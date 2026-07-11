#include <iostream>
using namespace std;


void bubbleSort(int array[], int size) {

    for (int i = 0; i < size - 1; i++) {

        for (int j = 0; j < size - i - 1; j++) {


            if (array[j] > array[j + 1]) {

                swap(array[j], array[j + 1]);

            }
        }
    }
}


int main() {

    int numbers[] = {8, 3, 6, 1, 4};


    bubbleSort(numbers, 5);


    for (int number : numbers)
        cout << number << " ";


    return 0;
}
