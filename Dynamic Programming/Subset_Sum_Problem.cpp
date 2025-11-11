#include<iostream>
using namespace std; 
int main()
{
	int set[] = {6,2,4}; 
	int sum = 3, n=3; 
	bool dp[n][sum]; 
	for(int i=0;i<n;i++)
	{
		dp[i][0] = true; 
	}
	for(int j=1;j<=sum;j++)
	{
		dp[0][j] = false; 
	}
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=sum;j++)
		{
			if(set[i-1] <= j)
			{
				dp[i][j] = dp[i-1][j] || dp[i-1][j-set[i-1]]; 
			}
			else
			{
				dp[i][j] = dp[i-1][j]; 
			}
		}
	}
	if(dp[n][sum])
	{
		cout<<"\nOutput : True"<<endl; 
	}
	else
	{
		cout<<"\nOutput : False"<<endl; 
	}
	return 0; 
}
		