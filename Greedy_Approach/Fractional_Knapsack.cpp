#include <iostream>
using namespace std;

int main() {
    int v[] = {60,100,120};
    int w[] = {10,20,30};
    int n = 3, W = 50;
    double r[3];

    for (int i = 0; i < n; i++)
        r[i] = (double)v[i] / w[i];

    // sort by ratio
    for (int i = 0; i < n-1; i++)
        for (int j = 0; j < n-i-1; j++)
            if (r[j] < r[j+1]) 
            {
                swap(r[j], r[j+1]);
                swap(v[j], v[j+1]);
                swap(w[j], w[j+1]);
            }

    double ans = 0;
    for (int i = 0; i < n && W > 0; i++) 
    {
        if (w[i] <= W) 
        {
            ans += v[i]; W -= w[i]; 
        }
        else 
        { 
            ans += v[i] * ((double)W / w[i]); 
            break; 
            
        }
    }
    cout << "Max value: " << ans;
}
