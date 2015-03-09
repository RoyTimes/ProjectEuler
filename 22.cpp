#include <vector>
#include <string>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int INF = 0x3f3f3f3f;
string get;
vector <string> s;
vector <string> :: iterator  IT;
void Analysis()
{
	for(int i = 0 ; i < strlen(get.c_str()); i ++){
		int jump = 1;
		if(get[i] == '"')
			while(get[i + jump] != '"') jump ++;
		s.push_back(get.substr(i + 1, jump - 1));
		i += jump + 1;
	}
}

int main()
{
	freopen("data.in","r",stdin);
	//freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin >> get;
	Analysis(); sort(s.begin(), s.end());

	unsigned long long sum = 0;
	for(int i = 0; i < (int)s.size(); i ++){
		string cur = s[i]; int tot = 0;
		for(int j = 0; j < cur.size(); j ++)
			tot += cur[j] - 'A' + 1;
		sum += tot * (i + 1);
	}
	cout << sum << endl;
}
