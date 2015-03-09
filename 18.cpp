#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
 
const int N = 110;
int dp[N][N];
 
int main()
{
	freopen("data.in","r",stdin);
    int n; cin >> n;
    for(int i = 1 ; i <= n ; i ++)
        for(int j = 1 ; j <= i ; j ++)
            scanf("%d",&dp[i][j]),
            dp[i][j] += max(dp[i - 1][j - 1], dp[i - 1][j]);
    int ans = -1;
    for(int i = 1 ; i <= n ; i ++)
        for(int j = 1 ; j <= i ; j ++)
            ans = max(ans, dp[i][j]);
    cout << ans << endl;
}
