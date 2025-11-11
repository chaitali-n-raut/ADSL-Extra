#include <iostream>
using namespace std;

int main() 
{
    int s[] = {1,3,0,5,8,5};
    int f[] = {2,4,6,7,9,9};
    int n = 6;

    cout << "Selected: 0 ";
    int last = 0;

    for (int j = 1; j < n; j++) 
    {
        if (s[j] >= f[last]) 
        {
            cout << j << " ";
            last = j;
        }
    }
    return 0;
}
