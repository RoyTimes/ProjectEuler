#include <string>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
string s;

int main()
{
	freopen("data.in","r",stdin);
	ios::sync_with_stdio(false);
	cin >> s; int sum = 0;
	for(int i = 0 ; i < s.length(); i ++)
		sum += s[i] - '0';
	cout << sum << endl;
	fclose(stdin); fclose(stdout); return 0;
}
