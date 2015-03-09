#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int arr[11], cut = 1;


/*int main()
{
	freopen("data.out","w",stdout);
	string s("0123456789");
	while (next_permutation(s.begin(), s.end()))
	    cout << s << endl;
	return 0;
}*/

int main()
{
	freopen("data.out","r",stdin);
	ios::sync_with_stdio(false);
	string s;
	for(int i = 0 ; i < 1000000 - 1; i ++)
		cin >> s;
	cout << s << endl;
	return 0;
}
