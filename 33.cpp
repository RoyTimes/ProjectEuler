#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
inline int gcd(int a, int b){
	while(a^=b^=a^=b%=a); 
	return b;
}
int Judge(int x, int y){
	if(x % 10 == y / 10)
		if(x*(y%10) == y*(x/10))return 1;
	return 0;
}
int main()
{
	ios::sync_with_stdio(false);
	int sum1 = 1, sum2 = 1;
	for(int i = 10; i <= 99 ; i ++)
		for(int j = i + 1; j <= 99; j ++)
			if(Judge(i, j))
				sum1 *= i, sum2 *= j;
	cout << sum1 << ' '  << sum2 << endl;
	cout << sum2 / gcd(sum1, sum2) << endl;
	return 0;
}
