#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int dic[1000];
void init(){
	dic[1] = 3,	dic[2] = 3,	dic[3] = 5, dic[4] = 4,
	dic[5] = 4,	dic[6] = 3, dic[7] = 5, dic[8] = 5, 
	dic[9] = 4, dic[10] = 3, dic[11] = 6, dic[12] = 6,
	dic[13] = 8, dic[14] = 8, dic[15] = 7, dic[16] = 7,
	dic[17] = 9, dic[18] = 8, dic[19] = 8, dic[20] = 6,
	dic[30] = 6, dic[40] = 5, dic[50] = 5, dic[60] = 5,
	dic[70] = 7, dic[80] = 6, dic[90] = 6, dic[100] = 7, dic[1000] = 8;
}  
int _get(int x){
	if(x <= 20) return dic[x];
	return dic[x % 10] + dic[x-x%10];
}
int get(int x)
{
	int tot = 0;
	if(dic[x]) return dic[x];

	if(x > 100 && x < 1000){
		int remain = x % 100;
		tot += _get(remain);
		tot += dic[100] + dic[x / 100];
		if(remain > 0)tot += 3;
	}
	else if(x < 100) tot += _get(x);
	return tot;
}

int main()
{
	init();
	unsigned long long sum = 0;
	for(int i = 1 ; i <= 1000 ; i ++)
		sum += get(i);
	//1000 && 100
	cout << sum + 6 << endl;
	return 0;
}
