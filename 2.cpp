#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 4000000;
long long f[100], i;

int main()
{
	f[1] = 1, f[2] = 2;
	for(i = 3;; i ++)
	{
		f[i] = f[i - 1] + f[i - 2];
		if(f[i] >= N) break;
	}

	int sum = 0;
	for(int j = 0 ; j <= i + 10; j ++)
		if(f[j] % 2 == 0) sum += f[j];

	cout << sum << endl;
	return 0;
}
