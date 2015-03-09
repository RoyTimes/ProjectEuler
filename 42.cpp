#include <string>
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
bool hash[100010];
string get; 
vector <string> s;
vector <string> :: iterator  IT;
void Analysis()
{
	for(int i = 0 ; i < get.size(); i ++){
		int jump = 1;
		if(get[i] == '"')
			while(get[i + jump] != '"') jump ++;
		s.push_back(get.substr(i + 1, jump - 1));
		i += jump + 1;
	}
}
int Sum_Digit(string & x)
{
	int sum = 0;
	for (int i = 0 ;i < (int)x.size(); i ++)
		sum += x[i] - 'A' + 1;
	return sum;
}

int main()
{
	freopen("data.in","r",stdin);
	ios::sync_with_stdio(false);
	cin >> get; fclose(stdin);
	Analysis();sort(s.begin(), s.end());
	
	for (int i = 1; i <= 300 ; i ++)
		hash[i * (i + 1) / 2] = 1;
	int cut = 0;
	for (IT = s.begin(); IT != s.end(); IT ++)
		if (hash[Sum_Digit(* IT)]) cut ++;
	cout << cut << endl;
	fclose(stdout);
	return 0;
}
