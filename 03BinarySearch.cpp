#include <iostream>
using namespace std;


int binarySearch(int array[], int size, int target) {

    int left = 0;
    int right = size - 1;


    while (left <= right) {

        int middle = (left + right) / 2;


        if (array[middle] == target)
            return middle;


        if (array[middle] < target)
            left = middle + 1;

        else
            right = middle - 1;
    }


    return -1;
}



int main() {

    int numbers[] = {10, 20, 30, 40, 50};


    cout << binarySearch(numbers, 5, 40);


    return 0;
}
