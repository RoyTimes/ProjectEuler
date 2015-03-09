#include <string>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
stringstream stream;
string x;

string trans(int x)
{
	stream << x; string y;
	stream >> y; stream.clear();
	return y;
}
unsigned long long sum()
{
	unsigned long long tot = 1;
	for (int i = 1; i <= 1000000; i *= 10)
		tot *= x[i - 1] - '0';
	return tot;
}

int main()
{
	int cut = 1;
	while (x.size() <= 1000010)
		x += trans(cut ++);
	cout << sum() << endl;
	return 0;
}
