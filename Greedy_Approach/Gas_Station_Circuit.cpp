#include <iostream>
using namespace std;

int main() 
{
    int g[] = {1,2,3,4,5};
    int c[] = {3,4,5,1,2};
    int n = 5;

    int total = 0, tank = 0, start = 0;

    for (int i = 0; i < n; i++) 
    {
        tank += g[i] - c[i];
        total += g[i] - c[i];
        if (tank < 0) 
        { 
            start = i+1; 
            tank = 0; 
            
        }
    }
    if (total >= 0) 
        cout << "Start index: " << start;
    else 
        cout << "No solution";
}
