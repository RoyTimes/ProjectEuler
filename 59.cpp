#include <string>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 3000;
int In [N], tot = 0, ans = 0;
int main()
{
    FILE *f = fopen("data.in", "r");
    for (char c = fgetc(f); c != EOF; c = fgetc(f))
        if (c != ',')
            In [tot] = In [tot] * 10 + c - '0';
        else tot ++;
    fclose(f);

    int max_sum, max_alpha, temp_alpha, temp_sum;
    max_sum = max_alpha = temp_sum = temp_alpha = 0;

    for (int cut = 0; cut < 3; cut ++)
    {
        max_sum = max_alpha = 0;
        for (char c = 'a'; c <= 'z'; c ++)
        {
            temp_alpha = temp_sum = 0;
            for (int j = cut; j < tot; j += 3)
            {
                char temp = In [j] ^ c;
                if (temp <= 'z' && temp >= 'a')
                    temp_alpha ++;
                temp_sum += temp;
            }
            if (temp_alpha > max_alpha)
                max_alpha = temp_alpha,
                max_sum = temp_sum;
        }
        ans += max_sum;
    }
    cout << ans + '.' << endl;
    return 0;
}
