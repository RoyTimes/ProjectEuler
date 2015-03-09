#include <set>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

multiset <int> s;
void init(){

	for (int i = 0 ; i <= 1000; i ++)
		for (int j = i ; j <= 1000; j ++)
			for (int k = 0 ; k <= 1000; k ++)
				if (i * i + j * j == k * k)
					s.insert (i + j + k);
	return;
}

int main()
{
	init();
	int _max = 0, flag;
	for (int i = 1; i <= 1000; i ++)
		if (_max < (int)s.count(i))
			_max = s.count(i), flag = i;
	cout << flag << endl;
	return 0;
}
