#include <cstdio>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
stringstream stream;

// This program is really slow but got the right answer

bool Prime(int x){
	for(int i = 2 ; i < x; i ++)
		if(x % i == 0) return 0;
	return 1;
}
int next(int x){
	string get;stream << x;
	stream >> get;stream.clear();
	int size = get.size();
	int mul = 1; while(-- size) mul *= 10;
	return ((x % 10) * mul + x / 10);
}
bool Judge(int x){
	int get = next(x);
	while(get != x){
		if(!Prime(get))return 0;
		get = next(get);
	}
	return 1;
}
int main()
{
	int cut = 4;
	for(int i = 11; i <= 1000000; i ++)
		if(Prime(i) && Judge(i))
			cut ++;
	cout << cut << endl;
	return 0; 
}
