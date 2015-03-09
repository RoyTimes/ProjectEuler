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
inline bool Judge (int x)
{
	int a[11], b[11], digit = 0, get = x, num = 0;
	while (get) a[digit ++] = get % 10, get /= 10;

	for (int i = 1; i < (1 << 5) ; i ++)
	{
		set <int> s; s.insert(x);
		for (int j = 0; j < 10; j ++)
		{
			for (int k = 0; k < digit; k ++)
				b[k] = a[k];
			for (int k = 0; k < 5; k ++)
				if (i & (1 << k))
					b[k + 1] = j;
			for (int k = digit - 1; k >= 0; k --)
				num = num * 10 + b[k];
			if (!isnotprime[num]) s.insert(num);
		}
		if (*s.begin() == x && s.size() == 8) return 1;
	}
	return 0;
}
int main()
{
	ios::sync_with_stdio(false);
	Liner_prime_list ();
	for (int i = 100001; i < N ; i += 2)
		if (!isnotprime[i] && Judge (i)) {
			cout << i << endl;
			break;
		}
	return 0;
}
