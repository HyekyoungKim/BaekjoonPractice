#include <iostream>

using namespace std;

/* Problem #2581 Prime Numbers */
/* https://www.acmicpc.net/problem/2581 */
int main() {
	int M, N, sum = 0, min; // All prime numbers are greater than 1.
	cin >> M >> N;
	min = N + 1;
	for (int i = M; i <= N; i++) {
		bool prime = true;
		if (i == 1)
			prime = false;
		else {
			for (int k = 2; k <= i / 2; k++)
				if (i % k == 0) {
					prime = false;
					break;
				}
		}
		if (prime) {
			sum += i;
			min = (i < min ? i : min);
		}
	}
	if (sum > 0) {
		cout << sum << endl;
		cout << min << endl;
	}
	else
		cout << -1 << endl;
	return 0;
}