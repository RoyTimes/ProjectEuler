#include <bits/stdc++.h>
using namespace std;

const int N = 1000001;
int Prime[N], cut = 0;
bool isnotprime[N];
void Liner_prime_list ()
{
	isnotprime[1] = 1;
	for (int i = 2; i < N ;i ++)
	{
		if (!isnotprime[i]) Prime[cut ++] = i;
		for (int j = 0; j < cut && Prime[j] * i < N; j ++)
		{
			isnotprime[i * Prime[j]] = 1;
			if (i % Prime[j] == 0) break;
		}
 	}
}

unsigned long long sum[N * 5];
int main()
{
	Liner_prime_list ();
	for (int i = 1; i <= cut; i ++)
		sum[i] = sum[i - 1] + Prime[i - 1];
	int ans = 0, pos;
	for (int i = cut - 1; i >= 0 ; i --)
		for (int j = i - 1; j >= 0; j --)
		{
			if (sum[i + 1] - sum[j + 1] >= N) break;
			if (!isnotprime[sum[i + 1] - sum[j + 1]])
				if (i - j > ans)
					ans = i - j, pos = sum[i + 1] - sum[j + 1];
		}
	cout << pos << endl;
	return 0;
}
