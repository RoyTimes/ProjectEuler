#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 10110;
int hash[N], late[N];

int get(int u, int d)
{
    int cut = 0;
    memset(hash, 0, sizeof hash);
    memset(late, 0, sizeof late);
    while(u % d){
        cut ++;
        while(u < d) u *= 10;
        int temp = u / d;
        if(hash[u]) return cut - late[u];
        hash[u] = 1, late[u] = cut;
        u -= temp * d;
    }
    return 0;
}

int main()
{
    int _max = -1, ans = 0;
    for(int i = 1 ; i < 1000 ; i ++)
        if(get(1,  i) > _max)
            _max = get(1, i), ans = i;
    cout << ans << endl;
    return 0;
}
