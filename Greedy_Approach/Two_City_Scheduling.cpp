#include <iostream>
using namespace std;

int main() 
{
    int a[4][2] = {{10,20},{30,200},{400,50},{30,20}};
    int n = 4, d[4], idx[4];

    for (int i = 0; i < n; i++) 
    {
        d[i] = a[i][0] - a[i][1];
        idx[i] = i;
    }

    for (int i = 0; i < n-1; i++)
        for (int j = 0; j < n-i-1; j++)
            if (d[j] > d[j+1]) 
            {
                swap(d[j], d[j+1]);
                swap(idx[j], idx[j+1]);
            }

    int sum = 0;
    for (int i = 0; i < n/2; i++) 
        sum += a[idx[i]][0];
    for (int i = n/2; i < n; i++) 
        sum += a[idx[i]][1];

    cout << "Min cost: " << sum;
}
