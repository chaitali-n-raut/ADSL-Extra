#include<iostream>
using namespace std; 
int main()
{
	int d[100][100]; 
	int n = 3, sum = 4; 
	int coins[] = {1,2,3}; 
	for(int i=0;i<=n;i++)
	{
		d[i][0] = 1; 
	}
	for(int j=1;j<=sum;j++)
	{
		d[0][j] = 0; 
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=sum;j++)
		{
			if(coins[i-1]<=j)
			{
				d[i][j] = d[i-1][j] + d[i][j-coins[i-1]]; 
			}
			else
			{
				d[i][j] = d[i-1][j]; 
			}
		}
	}
	cout<<"\nOutput : "<<d[n][sum]; 
	return 0; 
	
}