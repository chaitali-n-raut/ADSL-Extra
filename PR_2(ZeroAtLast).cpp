#include<iostream>
using namespace std;

void Divide(int a[], int low, int high); 
void Conquer(int a[], int low, int mid, int high);

int main() 
{
    int n, i, a[10];

    cout << "\nEnter Size Of Array : ";
    cin >> n;

    cout << "\nEnter Array Elements : ";
    for(i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    cout << "\nOriginal Array : ";
    for(i = 0; i < n; i++) 
    {
        cout << a[i] << " ";
    }

    Divide(a, 0, n - 1);

    cout << "\nAll Zeros At Last : ";
    for(i = 0; i < n; i++) 
    {
        cout << a[i] << " ";
    }

    return 0;
}

void Divide(int a[], int low, int high) 
{
    if(low >= high) 
		return;

    int mid = (low + high) / 2;
    
    Divide(a, low, mid);
    Divide(a, mid + 1, high);
    
    Conquer(a, low, mid, high);
}

void Conquer(int a[], int low, int mid, int high)
{
    int temp[high - low + 1];
    int index = 0;

    for(int i = low; i <= mid; i++)
    {
        if(a[i] != 0) 
        {
            temp[index++] = a[i];
        }
    }
    for(int i = mid + 1; i <= high; i++) 
    {
        if(a[i] != 0) 
        {
            temp[index++] = a[i];
        }
    }

    for(int i = low; i <= mid; i++) 
    {
        if(a[i] == 0) 
        {
            temp[index++] = 0;
        }
        
    }
    for(int i = mid + 1; i <= high; i++) 
    {
        if(a[i] == 0) 
        {
            temp[index++] = 0;
        }
    }

    for(int i = low, j = 0; i <= high; i++, j++) 
    {
        a[i] = temp[j];
    }
}
