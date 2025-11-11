#include <iostream>
using namespace std;

int main() 
{
    int n, amount;
    cin >> n;

    int coins[100]; // max N = 100
    for (int i = 0; i < n; ++i) 
	{
        cin >> coins[i];
    }

    cin >> amount;

    int dp[10001]; // max amount = 10^4

    // Initialize dp array
    for (int i = 0; i <= amount; ++i) 
	{
        dp[i] = amount + 1; // a value larger than any possible answer
    }
    dp[0] = 0; // base case: 0 coins needed to make amount 0

    // Fill dp array
    for (int i = 1; i <= amount; ++i) 
	{
        for (int j = 0; j < n; ++j) 
		{
            if (coins[j] <= i) 
			{
                int sub = dp[i - coins[j]];
                if (sub + 1 < dp[i]) 
				{
                    dp[i] = sub + 1;
                }
            }
        }
    }

    // Final result
    if (dp[amount] > amount) 
	{
        cout << -1 << endl; // not possible
    } 
	else 
	{
        cout << dp[amount] << endl; // minimum coins
    }

    return 0;
}