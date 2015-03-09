#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	long long sum1 = 0;
	for(int i = 1 ; i <= 100 ; i ++)
		sum1 += i * i;
	cout << abs(sum1 - 5050 * 5050) << endl;
	fclose(stdin); fclose(stdout);
	return 0;
}
