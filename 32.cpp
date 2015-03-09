#include <set>
#include <string>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
bool hash[100];
stringstream stream;
set <int> s;
set <int> :: iterator IT;

bool Fill(string& x)
{
	for(int i = 0 ; i < (int)x.size(); i ++)
		if(hash[x[i] - '0']) return 0;
		else hash[x[i] - '0']= 1;
	return 1;
}
bool Judge(string& a, string& b, string& c)
{
	memset(hash, 0, sizeof hash);
	if(Fill(a) && Fill(b) && Fill(c)){
		for(int i = 1; i <= 9; i ++)
			if(!hash[i]) return 0;
		if(hash[0] == 1) return 0;
		return 1;
	}
	return 0;
}// Judge wether this combination is avilble

int main()
{
	ios::sync_with_stdio(false);
	for(int i = 1; i < 5000 ; i ++)
		for(int j = 1; j < 100; j ++)
		{
			string a, b, c;
			stream << i * j << ' ' << i << ' ' << j;
			stream >> a >> b >> c;
			stream.clear();
			if(Judge(a, b, c))
				s.insert(i * j);
		}
	unsigned long long sum = 0;
	for(IT = s.begin(); IT != s.end(); IT++)
		sum += * IT;
	cout << sum << endl;

	return 0;
}
