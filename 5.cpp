#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

long long gcd(long long a, long long b){
    while (a ^= b ^= a ^= b %= a);
    return b;
}

int main()
{
	ios::sync_with_stdio(false);
	long long cur = 2;
	for(int i = 3 ; i <= 20; i ++)
		cur = cur * i / gcd(cur, i);
	cout << cur << endl;
	fclose(stdin); fclose(stdout);
	return 0;
}
