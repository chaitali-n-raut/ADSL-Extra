#include <iostream>
using namespace std;

// Function to get max of 2 numbers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to get max of 3 numbers
int max(int a, int b, int c) {
    return max(max(a, b), c);
}

// Function to find max crossing sum
int maxCrossingSum(int arr[], int low, int mid, int high) {
    int sum = 0;
    int leftSum = -100000; // minimum value

    for (int i = mid; i >= low; i--) {
        sum += arr[i];
        if (sum > leftSum)
            leftSum = sum;
    }

    sum = 0;
    int rightSum = -100000;

    for (int i = mid + 1; i <= high; i++) {
        sum += arr[i];
        if (sum > rightSum)
            rightSum = sum;
    }

    return leftSum + rightSum;
}

// Main function using divide and conquer
int maxSubArray(int arr[], int low, int high) {
    if (low == high)
        return arr[low];

    int mid = (low + high) / 2;

    int left = maxSubArray(arr, low, mid);
    int right = maxSubArray(arr, mid + 1, high);
    int cross = maxCrossingSum(arr, low, mid, high);

    return max(left, right, cross);
}

int main() {
    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = 9;

    int result = maxSubArray(arr, 0, n - 1);

    cout << "Maximum Subarray Sum: " << result << endl;

    return 0;
}
