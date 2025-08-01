#include <iostream>
using namespace std;

// Function to merge two halves
void merge(int arr[], int low, int mid, int high) {
    int temp[1000]; // Temporary array
    int i = low, j = mid + 1, k = 0;

    // Merge two sorted halves
    while(i <= mid && j <= high) {
        if(arr[i] < arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    // Copy remaining elements
    while(i <= mid) temp[k++] = arr[i++];
    while(j <= high) temp[k++] = arr[j++];

    // Copy back to original array
    for(int t = 0; t < k; t++) {
        arr[low + t] = temp[t];
    }
}

// Recursive Merge Sort function
void mergeSort(int arr[], int low, int high) {
    if(low < high) {
        int mid = (low + high) / 2;
        mergeSort(arr, low, mid);         // Sort left half
        mergeSort(arr, mid + 1, high);    // Sort right half
        merge(arr, low, mid, high);       // Merge both
    }
}

int main() {
    int arr[] = {5, 2, 3, 1};
    int n = 4;

    // Call merge sort
    mergeSort(arr, 0, n - 1);

    // Print sorted array
    cout << "Sorted Array: ";
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}
