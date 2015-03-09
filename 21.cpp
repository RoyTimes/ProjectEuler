#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int Pair[100000];
int get(int x){
	int sum = 0;
	for(int i = 1 ; i < x ; i ++)
		if(x % i == 0) sum += i;
	return sum;
}
int main()
{
	ios::sync_with_stdio(false);

	int ans = 0;
	memset(Pair, 0, sizeof Pair);
	for(int i = 1; i <= 10000; i ++){
		int temp = get(i);
		if(temp > i && get(temp) == i)
			ans += temp + i;
	}
	cout << ans << endl;
}
