/*#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>*/
#include <bits/stdc++.h>
using namespace std;

inline bool Prime(int x)
{
	for (int i = 2; i * i <= x; i ++)
		if (x % i == 0)
			return 0;
	return 1;
}
inline bool Judge(long long x)
{
	unsigned int i = 1;
	long long t;
	while ((t = (x - 2 * (i*i))) > 0){
		if (Prime(t)) return 1;
		i ++;
	}
	return 0;

}
int main()
{
	ios::sync_with_stdio(false);
	for (long long i = 1001; i <  100000000; i += 2)
		if (!Prime(i) && !Judge(i)){
			cout << i << endl;
			return 0;
		}
	cout << "Wrong Solution" << endl;
	return 0;
}
