#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
inline int div(int x)
{
	int cut = 0;
	for(int i = 1; i * i <=x ; i ++)
		if(x % i == 0)
			if(x == i * i) cut ++;
			else cut += 2;
	return cut;
}

int main()
{
	int cur = 1;
	for(int i = 2 ;; i ++){
		cur += i;
		if(div(cur)>= 500){
			cout << cur << endl;
			break;
		}
	}
	fclose(stdin); fclose(stdout);
	return 0;
}
