#include <iostream>

using namespace std;

/* Problem #1978 소수 찾기(Finding Prime Numbers) */
/* https://www.acmicpc.net/problem/1978 */
int main() {
	int N, count = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int k;
		cin >> k;
		bool prime = true;
		if (k == 1)
			prime = false;
		else {
			for (int j = 2; j <= k / 2; j++)
				if (k % j == 0) {
					prime = false;
					break;
				}
		}
		if (prime)
			count++;
	}
	cout << count;
	return 0;
}