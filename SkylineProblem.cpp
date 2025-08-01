#include <iostream>
using namespace std;

int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // Take last element as pivot
    int i = low;

    for (int j = low; j < high; j++) {
        if (arr[j] > pivot) {  // > because we want k-th largest
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
        }
    }

    // Swap pivot to correct position
    int temp = arr[i];
    arr[i] = arr[high];
    arr[high] = temp;

    return i;
}

int findKthLargest(int arr[], int low, int high, int k) {
    if (low <= high) {
        int pos = partition(arr, low, high);

        if (pos == k - 1)  // Found the k-th largest
            return arr[pos];
        else if (pos > k - 1)
            return findKthLargest(arr, low, pos - 1, k);
        else
            return findKthLargest(arr, pos + 1, high, k);
    }

    return -1;
}

int main() {
    int arr[] = {3, 2, 1, 5, 6, 4};
    int size = 6;
    int k = 2;

    int result = findKthLargest(arr, 0, size - 1, k);
    cout << "The " << k << "-th largest element is: " << result << endl;

    return 0;
}
 