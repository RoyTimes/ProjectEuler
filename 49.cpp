#include <bits/stdc++.h>
using namespace std;
stringstream stream;
set <int> s; 

inline bool Prime(int x)
{
	for (int i = 2; i * i <= x ; i ++)
		if (x % i == 0) return 0;
	return 1;
}
int IntTransString(string & x){
	stream << x; int y;
	stream >> y; stream.clear();
	return y;
}
string StringTransInt(int x)
{
	stream << x; string y;
	stream >> y; stream.clear();
	return y;
}
inline int get_set (int Index){
	set <int> :: iterator IT = s.begin();
	while (Index --) IT ++;
	return * IT;
}
inline bool Judge(int x)
{
	string get = StringTransInt(x);
	sort (get.begin(), get.end());
	
	s.clear(); s.insert(x);
	while (next_permutation(get.begin(),get.end()))
		if (Prime(IntTransString(get)))
			s.insert (IntTransString(get));

	if (s.size() < 3) return 0;
	for (int i = 0; i < s.size(); i ++)
		for (int j = i + 1; j < s.size(); j ++)
			for (int k = j + 1; k < s.size(); k ++)
				if (get_set(k) + get_set(i) == 2 * get_set(j)){
					cout << get_set(i) << ' ' << get_set(j) << ' ' << get_set(k) << endl; 
					return 1;
				}
	return 0;
}

int main()
{
	ios::sync_with_stdio(false);
	for (int i = 1000; i < 10000; i ++)
		if (Prime(i) && Judge(i));
	return 0; 
}
