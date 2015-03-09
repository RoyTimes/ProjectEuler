#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;


const int N = 2000000;     
//const int N = 10;

int prime[N + 100], num_prime = 0;      
int isNotPrime[N] = {1, 1}; 

void liner_prime()
{
	for(int i = 2 ; i < N ; i ++){
		if(!isNotPrime[i]) 
			prime[num_prime ++] = i;
		for(int j = 0; j < num_prime && i * prime[j] < N; j ++){
			isNotPrime[i * prime[j]] = 1;
			if(i % prime[j] == 0) break;
		}
	}
}

int main()
{
	freopen("data.out","w",stdout);

	ios::sync_with_stdio(false);
	unsigned long long sum = 0;
	liner_prime();
	for(int i = 0; i < num_prime; i ++)
		sum += prime[i], cout << prime[i] << endl;

	cout << sum << endl;
	fclose(stdin); fclose(stdout);
	return 0;
}
