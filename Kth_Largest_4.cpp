#include <iostream>
using namespace std;

// Swap two numbers
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Partition the array so larger elements come first
int partition(int numbers[], int start, int end) {
    int pivot = numbers[end]; // choose last element as pivot
    int index = start; // position to place larger number

    for (int i = start; i < end; i++) {
        if (numbers[i] > pivot) {
            swap(numbers[i], numbers[index]);
            index++;
        }
    }

    swap(numbers[index], numbers[end]); // move pivot to correct position
    return index; // return pivot index
}

// QuickSelect to find k-th largest number
int findKthLargest(int numbers[], int start, int end, int k) {
    if (start <= end) {
        int pivotIndex = partition(numbers, start, end);

        if (pivotIndex == k - 1) {
            return numbers[pivotIndex];
        }
        else if (pivotIndex > k - 1) {
            return findKthLargest(numbers, start, pivotIndex - 1, k);
        }
        else {
            return findKthLargest(numbers, pivotIndex + 1, end, k);
        }
    }

    return -1; // fallback (shouldn't reach here if input is valid)
}

int main() {
    int numbers[] = {3, 2, 1, 5, 6, 4};
    int size = 6;
    int k = 2;

    int result = findKthLargest(numbers, 0, size - 1, k);

    cout << "The " << k << "-th largest element is: " << result << endl;

    return 0;
}
