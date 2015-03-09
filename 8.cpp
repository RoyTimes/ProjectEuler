#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
char input[1010];

int main()
{
	//data.in contains the 1000digits number of the input
	freopen("data.in","r",stdin);
	ios::sync_with_stdio(false);
	cin >> input; fclose(stdin);

	long long _max = -1, _get = 1;
	int len = strlen(input);
	for(int i = 0 ; i < len - 13 ; i ++)
	{
		_get = 1;
		for(register int j = i ; j < i + 13 ; j ++)
			_get *= input[j] - '0';
		_max = max(_max, _get);
	}
	cout << _max << endl;
	fclose(stdout);
	return 0;
}
