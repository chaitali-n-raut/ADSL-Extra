#include <iostream>
using namespace std;

// Count how many times 'num' occurs between index left and right
int count(int arr[], int left, int right, int num) {
    int c = 0;
    for (int i = left; i <= right; i++) {
        if (arr[i] == num)
            c++;
    }
    return c;
}

// Recursive function to find majority element in arr[left...right]
int majority(int arr[], int left, int right) {
    // Base case: single element
    if (left == right)
        return arr[left];

    // Divide
    int mid = (left + right) / 2;

    // Conquer
    int leftMajor = majority(arr, left, mid);
    int rightMajor = majority(arr, mid + 1, right);

    // If both sides return same element
    if (leftMajor == rightMajor)
        return leftMajor;

    // Count both in full range
    int leftCount = count(arr, left, right, leftMajor);
    int rightCount = count(arr, left, right, rightMajor);

    // Return the one with higher count
    return (leftCount > rightCount) ? leftMajor : rightMajor;
}

int main() {
    int arr[] = {1, 1, 2, 1, 3, 1, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    int ans = majority(arr, 0, n - 1);
    cout << "Majority Element: " << ans << endl;

    return 0;
}