#include <iostream>
using namespace std;

int bst(int arr[], int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
            return mid;
        if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1; // Return -1 if element not found
}

int main() {
    int n;
    cout << "Enter number of elements in array: ";
    cin >> n;
    if (n <= 0) {
        cout << "Invalid array size. Exiting.\n";
        return 1;
    }

    int* arr = new int[n];
    cout << "Enter elements of array in sorted order: ";
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    int target;
    cout << "Enter the element to search: ";
    cin >> target;

    int index = bst(arr, 0, n - 1, target);
    if (index != -1)
        cout << "Element found at index " << index << endl;
    else
        cout << "Element not found" << endl;

    delete[] arr; // Free dynamically allocated memory
    return 0;
}
