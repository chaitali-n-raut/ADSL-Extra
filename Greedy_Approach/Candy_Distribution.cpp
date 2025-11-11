#include <iostream>
using namespace std;

int main() 
{
    int r[] = {1,0,2};
    int n = 3, c[3];

    for (int i = 0; i < n; i++)
        c[i] = 1;

    for (int i = 1; i < n; i++)
        if (r[i] > r[i-1]) 
            c[i] = c[i-1] + 1;

    for (int i = n-2; i >= 0; i--)
        if (r[i] > r[i+1] && c[i] <= c[i+1])
            c[i] = c[i+1] + 1;

    int sum = 0;
    for (int i = 0; i < n; i++) 
        sum += c[i];

    cout << "Candies: " << sum;
}
