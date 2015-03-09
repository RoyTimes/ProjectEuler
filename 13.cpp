#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	string s;
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	while(cin >> s) cout << s << '+';
	fclose(stdin);fclose(stdout);
	return 0;
}
