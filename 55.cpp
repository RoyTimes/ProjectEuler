//#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
stringstream stream;
typedef unsigned long long ull;

inline bool is_palindrome(ull x){
	stream << x; string get;
	stream >> get; stream.clear();
	for (int i = 0; i < (int)get.size()/2+1; i ++)
		if (get[i] != get[(int)get.size() - i - 1])
			return false;
	return true;
}
inline ull next(ull x){
	stream << x; string get;
	stream >> get; stream.clear();
	for (int i = (int)get.size() - 1; i >= 0; i --)
		stream << get[i] << flush;
	ull res; stream >> res; stream.clear();
	return res + x; 
}
inline bool Judge(ull x){
	int cut = 0;
	ull get_ans = next(x);
	while (!is_palindrome(get_ans)){
		if (cut ++ >= 50) return false;
		get_ans = next(get_ans);
	}
	return true;
}

int main()
{
	ios::sync_with_stdio(false);
/*
	TEST BLOCK

	stream << 12345678; string get;
	stream >> get; stream.clear();
	for (int i = (int)get.size(); i >= 0; i --)
		stream << get[i] << flush;

	string buf; stream >> buf;
	cout << "BUF: " << buf << endl; stream.clear();

*/

	int rank = 10;
	cout << rank << endl;


	int cut = 0;
	for (int i = 1; i <= 10000; i++)
		if (Judge (i)) cut++;
	cout << 10000 - cut << endl;
	return 0;
}
