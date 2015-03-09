#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

inline bool Prime (int x){
	for (int i = 2; i * i < x; i ++)
		if (x % i == 0) return false;
	return true;
}
#define A (4 * i * i - 6 * i + 3)
#define B (4 * i * i - 8 * i + 5)
#define C (4 * i * i - 10 * i + 7)

int main()
{
	freopen("data.out", "w", stdout);
	//ios::sync_with_stdio(false);

	int cut = 0, tot = 1;
	for (int i = 2;; i ++){
		
		cout << A << " - " << B << " - " << C << endl;

		if (Prime (A)) cut ++;
		if (Prime (B)) cut ++;
		if (Prime (C)) cut ++;

		tot += 4;
		double pre = (double) cut / (double) tot;
		printf("%lf\n", pre);
		if (pre - 0.1 <= 0) {
			cout << 2 * i - 1 << endl;
			return 0;
		}
	}


}



/*


i >> 2 * i - 1
a >> (4i^2 - 4i + 1)
b >> a - 2i + 2 == 4i^2 - 6i + 3
c >> b - 2i + 2 == 4i^2 - 8i + 5
d >> c - 2i + 2 == 4i^2 - 10i + 7






*/



















