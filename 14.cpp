#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
inline long long get_next(long long x){
	if(x & 1) return x * 3 + 1;
	else return x >> 1;
}

long long get(long long x)
{
	long long cut = 0;
	while(1){
		if(x == 1) break;
		x = get_next(x), cut++;
		if(x < 0) puts("Warning");
	}
	return cut;
}

int main()
{
	ios::sync_with_stdio(false);
	long long _max = 0; int flag;
	for(long long i = 1000000; i >= 1 ; i --){
		if(_max < get(i)) _max = get(i), flag = i;
	}
	cout << _max + 1 << ' ' << flag << endl;
	fclose(stdin); fclose(stdout); return 0;
}
