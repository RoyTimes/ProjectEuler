#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 28124;
int abundant[MAX], is_not_answer[MAX];
int FindDivSum(int x){
	int sum = 0;
	for(int i = 1; i < x; i ++)
		if(x % i == 0) sum += i;
	return sum; 
}
int main()
{
	for(int i = 12; i <= MAX ; i ++)
		if(i < FindDivSum(i))
			abundant[i] = 1;
	for(int i = 2 ; i < MAX ; i ++)
		for(int j = 2 ; j < MAX - i ; j ++)
			if(is_not_answer[i + j] != 2)
				is_not_answer[i + j] = abundant[i] + abundant[j];
	unsigned long long sum = 0;
	for(int i = 0; i < MAX; i ++)
		if(is_not_answer[i] != 2) sum += i;
	cout << sum << endl;
	return 0;
}
