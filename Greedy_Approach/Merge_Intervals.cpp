#include <iostream>
using namespace std;

int main() 
{
    int s[] = {1,2,6,7};
    int e[] = {3,4,8,11};
    int n = 4;

    int st = s[0], en = e[0];

    for (int i = 1; i < n; i++) 
    {
        if (s[i] <= en) 
        {
            if (e[i] > en) 
                en = e[i];
        } 
        else 
        {
            cout << "(" << st << "," << en << ") ";
            st = s[i];
            en = e[i];
        }
    }
    cout << "(" << st << "," << en << ")";
}
