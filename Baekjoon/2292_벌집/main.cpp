#include <iostream>

using namespace std;

/* Problem #2292 Hive */
/* https://www.acmicpc.net/problem/2292 */
int main() {
	int N, num = 1, step = 0;
	cin >> N;
	do {
		num += step * 6;
		step++;
	} while (num < N);
	cout << step;
	return 0;
}