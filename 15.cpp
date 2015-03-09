#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

unsigned long long dp[30][30];
int main()
{
	int n = 20;
	for(int i = 0 ; i <= n ; i ++)
		dp[0][i] = 1, dp[i][0] = 1;
	for(int i = 1 ; i <= n ; i ++)
		for(int j = 1 ; j <= n ; j ++)
			dp[i][j] = dp[i][j-1] + dp[i-1][j];
	cout << dp[n][n] << endl;
	return 0;
}
