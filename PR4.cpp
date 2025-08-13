#include <iostream>
#include <algorithm>
using namespace std; 
int main()
{
	int S[5] = {1,2,3}; 
	int E[5] = {3,4,5}; 
	int K = 2; 
	int n = 3; 
	/*for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n; j++)
		{
			if(E[i] > E[j])
			{
				swap(E[i], E[j]); 
				swap(S[i], S[j]); 
			}
		}
	} */

	pair<int, int> activities[100]; 
	for(int i=0;i<n;i++)
	{
		sort(activities, activities+1); 
	}
	int p[100] = { 0 }; 
	int count = 0; 
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<K; j++)
		{
			if(p[j] <= S[i])
			{
					p[j] = E[i]; 
					count++; 
					break; 
			}
		}
	}
	cout<<"\nMaximum No. Of Shops That can be Visited : " <<count<<endl; 
	return 0; 
} 