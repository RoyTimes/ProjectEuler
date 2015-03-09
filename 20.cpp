#include <string>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
string s;

int main()
{
	//freopen("data.in","r",stdin);
	cin >> s; int ans = 0;
	for(int i = 0 ; i < s.size() ; i ++)
		ans += s[i] - '0';
	cout << ans << endl;
}
