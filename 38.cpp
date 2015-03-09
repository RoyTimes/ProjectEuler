#include <cstdio>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
stringstream stream;

string trans(int x){
	stream << x;string y;
	stream >> y; stream.clear();
	return y;
}
int Trans(string & x){
	stream << x; int y;
	stream >> y; stream.clear();
	return y;
}
int generate(int Original_number)
{
	string s = trans(Original_number);
	string std("123456789");
	if(s.size() >= 5) return 0;
	else {
		int temp = 2;
		while(s.size() < 9)
			s += trans(Original_number * temp),
			temp ++;
		string get; get = s;
		sort (s.begin(), s.end());
		if (s == std) return Trans(get);
		else return 0;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	int ans = 0;
	for (int i = 9; i < 100000; i ++)
		ans = max (ans, generate(i));
	cout << ans << endl;
	return 0;
}
