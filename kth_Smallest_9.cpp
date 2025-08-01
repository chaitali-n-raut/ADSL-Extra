#include <iostream>
using namespace std;

int findKth(int a[], int m, int b[], int n, int k) {
    // Always work on the smaller array
    if (m > n)
        return findKth(b, n, a, m, k);

    if (m == 0)
        return b[k - 1];

    if (k == 1)
        return (a[0] < b[0]) ? a[0] : b[0];

    int partA = (k / 2 < m) ? k / 2 : m;
    int partB = k - partA;

    if (a[partA - 1] < b[partB - 1])
        return findKth(a + partA, m - partA, b, n, k - partA);
    else
        return findKth(a, m, b + partB, n - partB, k - partB);
}

int main() {
    int a[2] = {1, 3};
    int b[1] = {2};
    int k = 2;

    int result = findKth(a, 2, b, 1, k);
    cout << result << endl;

    return 0;
}
