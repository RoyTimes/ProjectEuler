#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

inline bool Judge(long long x){
	for(int i = 2ll; i * i < x ; i ++)
		if(x % i == 0) return 0;
	return 1;
}

int main()
{
	//freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);

	long long get = 600851475143ll;
	for(long long i = 2ll;; i ++)
		if(get % i == 0 && Judge(get / i)){
			cout << get / i << endl;
			break;
		}
	return 0;
}
