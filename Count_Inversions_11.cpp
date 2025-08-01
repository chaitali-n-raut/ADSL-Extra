#include <iostream>
using namespace std;

// Merge and count the number of inversions
int mergeAndCount(int arr[], int left, int mid, int right) {
    int temp[100]; // temp array
    int i = left;
    int j = mid + 1;
    int k = 0;
    int invCount = 0;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            invCount += (mid - i + 1); // all remaining elements in left part are > arr[j]
        }
    }

    // Copy remaining elements
    while (i <= mid) temp[k++] = arr[i++];
    while (j <= right) temp[k++] = arr[j++];

    // Copy back to original array
    for (int m = 0; m < k; m++) {
        arr[left + m] = temp[m];
    }

    return invCount;
}

// Divide and count inversions recursively
int countInversions(int arr[], int left, int right) {
    int total = 0;
    if (left < right) {
        int mid = (left + right) / 2;

        total += countInversions(arr, left, mid);       // Left half
        total += countInversions(arr, mid + 1, right);  // Right half
        total += mergeAndCount(arr, left, mid, right);  // Merge step
    }
    return total;
}

int main() {
    int arr[] = {2, 4, 1, 3, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    int result = countInversions(arr, 0, size - 1);
    cout << "Number of inversions: " << result << endl;

    return 0;
}
