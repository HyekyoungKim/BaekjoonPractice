#include <iostream>

using namespace std;

/* Problem #2839 ŠEĆER */
/* https://www.acmicpc.net/problem/2839 */
int main() {
	int count_five = 0, count_three = 0, N;
	cin >> N;
	while (N > 0 && N % 5 != 0) {
		N -= 3;
		if (N < 0)
			break;
		count_three++;
	}
	if (N < 0)
		cout << -1;
	else {
		count_five = N / 5;
		cout << count_three + count_five;
	}

	return 0;
}