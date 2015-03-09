#include <string>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100010;
const int In [N];
int tot = 0;


string Crype (int a, int b, int c){
	for (int i = 0; i < tot; i ++)
}

int main()
{
	freopen ("data.in", "r",stdin);
	ios::sync_with_stdio(false);
	
	while (cin >> In[tot ++]);

	for (int i = 'a'; i <= 'z'; i ++)
		for (int j = 'a'; j <= 'z'; j ++)
			for (int k = 'a'; k <= 'z'; k ++){
				string get = Crype (i, j, k);
				if (Judge (get)){
					cout << GetSum (get) << endl;
					return 0;
				}
			}
}