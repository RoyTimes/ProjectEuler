#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int get[30][30];
int main()
{
	freopen("data.in","r",stdin);
	ios::sync_with_stdio(false);

	memset(get, 0, sizeof get);
	for(int i = 0; i< 20 ; i ++)
		for(int j = 0 ; j< 20 ; j ++)
			cin >> get[i][j];

	int _max= 0;
	for(int i = 0; i < 20 ; i ++)
		for(int j = 0; j < 20; j ++)
		{
			int get_cur1 = get[i][j]*get[i+1][j+1]*get[i+2][j+2]*get[i+3][j+3];
			int get_cur2 = get[i][j]*get[i+1][j]*get[i+2][j]*get[i+3][j];
			int get_cur3 = get[i][j]*get[i][j+1]*get[i][j+2]*get[i][j+3];
			_max = max(_max, get_cur1);_max = max(_max, get_cur2);
			_max = max(_max, get_cur3);
		}
	for(int i= 0 ; i < 16; i++)
		for(int j = 4 ; j < 20 ; j++)
			_max = max(_max, get[i][j]*get[i+1][j-1]*get[i+2][j-2]*get[i+3][j-3]);

	cout << _max << endl;
	fclose(stdin); fclose(stdout); return 0;
}
