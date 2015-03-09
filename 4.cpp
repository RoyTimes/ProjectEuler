#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int digit[10];
inline bool check(int x)
{
	int mul = 1;
	for(int i = 1 ; i <= 6 ; i ++, mul *= 10)
		digit[i] = x % 10, x /= 10;
	if(digit[1] == digit[6] && digit[2] == digit[5] && digit[3] == digit[4])
		return 1;
	return 0;
}

int main()
{
	cout << check(111111) << endl;


	int _max = -1;
	for(int i = 100 ; i <= 999; i ++)
		for(int j = 100; j <= 999; j ++)
			if(check(i * j)) _max = max(_max, i * j);
	cout << _max << endl;
	return 0;
}
