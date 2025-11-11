#include <iostream>
#include <algorithm>
using namespace std;

int main() 
{
    int arr[] = {900, 940, 950, 1100, 1500, 1800};
    int dep[] = {910, 1200, 1120, 1130, 1900, 2000};
    int n = 6;

    sort(arr, arr + n);   // important
    sort(dep, dep + n);   // important

    int plat = 1, res = 1, i = 1, j = 0;

    while (i < n && j < n) 
	{
        if (arr[i] <= dep[j]) 
		{
            plat++; 
            i++; 
        } 
		else 
		{ 
            plat--; 
            j++;    
        }
        if (plat > res) res = plat;
    }

    cout << "Minimum Platforms Needed = " << res;
}
