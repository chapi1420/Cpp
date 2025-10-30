#include <iostream>
using namespace std;

int linearSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target)
            return i; // Target found
    }
    return -1; // Target not found
}

int main() {
    int arr[] = {5, 3, 8, 4, 2, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 4;

    int result = linearSearch(arr, n, target);

    if (result != -1)
        cout << "Element found at index " << result << endl;
    else
        cout << "Element not found" << endl;

    return 0;
}
