#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

inline bool Judge(long long x){
	for(int i = 2 ; i < x ; i ++)
		if(x % i == 0) return 0;
	return 1;
}

int main()
{
	ios::sync_with_stdio(false);
	long long cur = 2ll;
	int cut = 0;
	for(;;cur++){
		if(Judge(cur))
			cut ++;
		if(cut == 10001) {
			cout << cur << endl;
			break;
		}
	}
	return 0;
}
