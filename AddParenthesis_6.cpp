#include <iostream>
using namespace std;

const int MAX = 100;

struct Building {
    int left;
    int right;
    int height;
};

struct Point {
    int x;
    int height;
};

void mergeSkylines(Point a[], int n1, Point b[], int n2, Point result[], int &resSize) {
    int i = 0, j = 0, h1 = 0, h2 = 0, idx = 0;

    while (i < n1 && j < n2) {
        int x;
        if (a[i].x < b[j].x) {
            x = a[i].x;
            h1 = a[i].height;
            i++;
        } else if (b[j].x < a[i].x) {
            x = b[j].x;
            h2 = b[j].height;
            j++;
        } else {
            x = a[i].x;
            h1 = a[i].height;
            h2 = b[j].height;
            i++;
            j++;
        }

        int maxH = (h1 > h2) ? h1 : h2;
        if (resSize == 0 || result[resSize - 1].height != maxH) {
            result[resSize].x = x;
            result[resSize].height = maxH;
            resSize++;
        }
    }

    while (i < n1) {
        result[resSize++] = a[i++];
    }
    while (j < n2) {
        result[resSize++] = b[j++];
    }
}

void buildSkyline(Building buildings[], int left, int right, Point skyline[], int &size) {
    if (left == right) {
        skyline[0].x = buildings[left].left;
        skyline[0].height = buildings[left].height;
        skyline[1].x = buildings[left].right;
        skyline[1].height = 0;
        size = 2;
        return;
    }

    int mid = (left + right) / 2;
    Point leftSky[MAX], rightSky[MAX], mergedSky[MAX];
    int sizeLeft = 0, sizeRight = 0, sizeMerged = 0;

    buildSkyline(buildings, left, mid, leftSky, sizeLeft);
    buildSkyline(buildings, mid + 1, right, rightSky, sizeRight);

    mergeSkylines(leftSky, sizeLeft, rightSky, sizeRight, skyline, size);
}

int main() {
    int n;
    cin >> n;

    Building buildings[MAX];
    for (int i = 0; i < n; i++) {
        cin >> buildings[i].left >> buildings[i].right >> buildings[i].height;
    }

    Point skyline[MAX * 2];
    int skylineSize = 0;

    buildSkyline(buildings, 0, n - 1, skyline, skylineSize);

    for (int i = 0; i < skylineSize; i++) {
        cout << skyline[i].x << " " << skyline[i].height << endl;
    }

    return 0;
}
