#include <iostream>
#include <cstring>
using namespace std;

int main() 
{
    string A, B;
    cin >> A >> B;

    int m = A.length();
    int n = B.length();

    int dp[1001][1001]; // max length of A and B is 1000

    // Initialize the dp table
    for (int i = 0; i <= m; ++i) 
	{
        for (int j = 0; j <= n; ++j) 
		{
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (A[i - 1] == B[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    cout << dp[m][n] << endl; // length of LCS

    return 0;
}