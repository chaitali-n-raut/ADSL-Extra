#include <iostream>
using namespace std;

int main() 
{
    int a[] = {4,3,1,2};
    int n = 4, T = 7;

    for (int i = 0; i < n-1; i++)
        for (int j = 0; j < n-i-1; j++)
            if (a[j] > a[j+1])
                swap(a[j], a[j+1]);

    int time = 0, cnt = 0;

    for (int i = 0; i < n; i++) 
    {
        if (time + a[i] <= T) 
        {
            time += a[i];
            cnt++;
        }
    }
    cout << "Tasks: " << cnt;
}
