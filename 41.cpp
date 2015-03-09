#include <cstdio>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
stringstream stream;

inline bool Prime(int x)
{
	for (int i = 2; i < x; i ++)
		if (x % i == 0) return 0;
	return 1;
}
inline bool pandigital(int n)  
{  
    int hash[10]; memset(hash, 0, sizeof hash);
    stream << n; string get;
    stream >> get; stream.clear();
    for (int i = 0; i < get.size(); i ++)
    	hash[get[i] - '0'] ++;
    for (int i = 1; i <= get.size(); i ++)
    	if (!hash[i] || hash[i] > 1) return 0;
    return 1;
}  

int main()
{
	for (int i = 10000001; i >= 1000 ; i -= 2)
		if (pandigital (i) && Prime (i)){
			cout << i << endl;
			return 0;
		}
}
