#include <bits/stdc++.h>
using namespace std;
stringstream stream;

inline string Trans(unsigned int x)
{
	stream << x; string get; stream >> get;
	stream.clear(); return get;
}
inline bool Equal (unsigned int x, unsigned int y){
	string a, b; a = Trans(x), b = Trans(y);
	sort (a.begin(), a.end());sort(b.begin(), b.end());
	return (a == b);
}
inline bool Judge(unsigned int x){
	for (int i = 1; i <= 6; i ++)
		if (!Equal (x, i * x))
			return 0;
	return 1;

}
int main()
{
	for (unsigned int i = 100; i <= 1000000; i ++)
		if (Judge (i)) {
			cout << i << endl;
			break;
		}
	return 0;
}
