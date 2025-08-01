#include <iostream>
using namespace std;

// Function to find minimum element in rotated sorted array
int findMinimum(int arr[], int low, int high) {
    // If array is not rotated at all
    if (high < low)
        return arr[0];

    // If only one element left
    if (high == low)
        return arr[low];

    int mid = (low + high) / 2;

    // Check if mid+1 is the minimum element
    if (mid < high && arr[mid+1] < arr[mid])
        return arr[mid+1];

    // Check if mid is the minimum element
    if (mid > low && arr[mid] < arr[mid-1])
        return arr[mid];

    // Decide which half to search
    if (arr[high] > arr[mid])
        return findMinimum(arr, low, mid - 1);
    else
        return findMinimum(arr, mid + 1, high);
}

int main() {
    int arr[] = {3, 4, 5, 1, 2};
    int size = sizeof(arr) / sizeof(arr[0]);

    int minValue = findMinimum(arr, 0, size - 1);
    cout << "Minimum element is: " << minValue << endl;

    return 0;
}
