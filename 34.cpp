#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int Sum(int x){
	int sum = 1;
	for(int i = 1; i <= x ; i ++)
		sum *= i;
	return sum;
}
int Div(int x){
	int sum = 0;
	while(x)
		sum += Sum(x % 10), x /= 10;
	return sum;
}

int main()
{
	ios::sync_with_stdio(false);
	int sum = 0;
	for (int i = 3; i <= 10000010; i ++)
		if(Div(i) == i) sum += i;
	cout << sum << endl;
	return 0;
}
