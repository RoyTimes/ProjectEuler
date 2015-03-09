#include <set>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const unsigned int Start = 40755;

inline bool Judge(unsigned int x)
{
	unsigned int get = -1;
	for (unsigned int i = 1; i <= x; i ++)
		if (i * (2 * i - 1) == x) {get = i; break;}
	if (get == -1) return 0;
	return (get * (get + 1) / 2 == x) &&
			(get * (3 * get - 1) / 2 == x);
}

int main()
{
	ios::sync_with_stdio(false);
	for (unsigned int i = Start; i > 0; i ++)
		if (Judge(i)) {cout << i << endl; return 0;}
	return 0;
}
