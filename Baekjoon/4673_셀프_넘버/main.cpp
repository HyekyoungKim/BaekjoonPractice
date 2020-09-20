#include <iostream>
using namespace std;

/* Problem #4673 Self Numbers */
/* https://www.acmicpc.net/problem/4673 */
int d(int n)
{
	int selfnum = n;
	while (n > 0) {
		selfnum += n % 10;
		n /= 10;
	}
	return selfnum;
}

int main()
{
	bool exists[10001];
	int selfnum;
	for (int i = 1; i <= 10000; i++)
		exists[i] = false;
	for (int i = 1; i <= 10000; i++) {
		selfnum = d(i);
		if (selfnum <= 10000)
			exists[selfnum] = true;
	}
	for (int i = 1; i <= 10000; i++)
		if (!exists[i])
			cout << i << endl;
	return 0;
}