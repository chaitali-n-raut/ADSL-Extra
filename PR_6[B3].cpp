#include <iostream>
using namespace std;

int main() 
{
    int task[] = {3,4,7,15};
    int n = 4, days = 10;

    int sum = 0, maxTask = task[0];
    for (int i = 0; i < n; i++) 
    {
        sum += task[i];
        if (maxTask < task[i]) 
        {
            maxTask = task[i];
        }
    }

    cout << "\nTotal Work Done : " << sum;
    cout << "\nMaximum Task : " << maxTask;

    int low = 1, high = maxTask, ans = maxTask;

    while (low <= high) 
    {
        int mid = (low + high) / 2;

        int usedDays = 0;
        for (int i = 0; i < n; i++) 
        {
            
            usedDays += (task[i] + mid - 1) / mid;
        }

        if (usedDays <= days) 
        {
            ans = mid;       
            high = mid - 1;
        }
        else 
        {
            low = mid + 1;    
        }
    }
    cout << "\nMinimum Work Per Day Needed : " << ans << endl;

    return 0;
}