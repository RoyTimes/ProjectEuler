#include <cstdio>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
stringstream stream;
string s("0123456789");

inline unsigned long long Trans(const string & x)
{
	stream << x; unsigned long long y;
	stream >> y; stream.clear();
	return y;
}

inline bool Judge(const string & get)
{
	if (Trans(get.substr(1, 3)) % 2 != 0)return 0;
	if (Trans(get.substr(2, 3)) % 3 != 0)return 0;
	if (Trans(get.substr(3, 3)) % 5 != 0)return 0;
	if (Trans(get.substr(4, 3)) % 7 != 0)return 0;
	if (Trans(get.substr(5, 3)) % 11 != 0)return 0;
	if (Trans(get.substr(6, 3)) % 13 != 0)return 0;
	if (Trans(get.substr(7, 3)) % 17 != 0)return 0;
	return 1;
}

int main()
{
	ios::sync_with_stdio(false);
	unsigned long long sum = 0;
	while (next_permutation(s.begin(), s.end()))
		if (Judge(s)) sum += Trans(s);
	cout << sum << endl;
	return 0;
}
