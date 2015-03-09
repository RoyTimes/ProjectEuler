#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

inline bool is_prime(int x){
	for(int i = 2 ; i < x ; i ++)
		if(x % i == 0) return 0;
	return 1;
}
int MaxPrimeGenerate(int a, int b)
{
	for(int i = 0; ;i ++)
		if(!is_prime(abs(i*i+a*i+b)))
			return i;
}

int main()
{
	pair <int, int > ans;
	int _max = -1;
	for(int i = -1000; i <= 1000 ; i ++)
		for(int j = -1000; j <= 1000 ; j ++)
			if(_max < MaxPrimeGenerate(i, j))
				_max = MaxPrimeGenerate(i, j),
				ans.first = i, ans.second = j;
	cout << ans.first * ans.second << endl;
}
