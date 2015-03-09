#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int c[100] = {1,2,5,10,20,50,100,200}, f[500];

int main()
{
	ios::sync_with_stdio(false);
	int V = 8, N = 200;
	f[0] = 1;
	for(int i = 0 ; i < V ; i ++)
		for(int j = c[i]; j <= N ; j ++)
			f[j] += f[j - c[i]];
	cout << f[N];	

}
