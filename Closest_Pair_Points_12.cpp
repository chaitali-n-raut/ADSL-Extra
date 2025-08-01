#include <iostream>
using namespace std;

struct Point {
    int x, y;
};

int distanceSquared(Point a, Point b) {
    int dx = a.x - b.x;
    int dy = a.y - b.y;
    return dx * dx + dy * dy;
}

int main() {
    Point points[100];
    int n;

    cout << "Enter number of points: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter x y for point " << i + 1 << ": ";
        cin >> points[i].x >> points[i].y;
    }

    int minDist = 1e9;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int d = distanceSquared(points[i], points[j]);
            if (d < minDist) {
                minDist = d;
            }
        }
    }

    cout << "Minimum distance squared = " << minDist << endl;

    return 0;
}
