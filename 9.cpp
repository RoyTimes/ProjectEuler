#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
inline bool Judge(int a, int b, int c){
	return (a * a + b * b == c * c);
}

int main()
{
	ios::sync_with_stdio(false);
	int a, b, c;
	for(int i = 1 ; i <= 1000 ; i ++)
		for(int j = 1 ; j <= 1000 ; j ++)
		{
			a = i, b = j, c = 1000 - a - b;
			if(c < 0) continue;
			if(Judge(a, b, c)){
				cout << (long long)(a * b * c) << endl;
				break;
			}
		}
	fclose(stidn); fclose(stdout);
	return 0;
}
