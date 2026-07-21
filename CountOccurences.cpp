#include <iostream>
#include <vector>
using namespace std;

int firstOccurrence(const vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1, result = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            result = mid;
            right = mid - 1;
        } else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return result;
}

int lastOccurrence(const vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1, result = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            result = mid;
            left = mid + 1;
        } else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return result;
}

int countOccurrences(const vector<int>& arr, int target) {
    int first = firstOccurrence(arr, target);
    if (first == -1)
        return 0;

    int last = lastOccurrence(arr, target);
    return last - first + 1;
}

int main() {
    vector<int> arr = {1,2,2,2,3,4,5};
    cout << countOccurrences(arr, 2);
    return 0;
}
