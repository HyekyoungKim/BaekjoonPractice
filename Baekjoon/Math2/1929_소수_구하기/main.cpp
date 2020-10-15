#include <iostream>

using namespace std;

/* �����佺�׳׽��� ü(Sieve of Eratosthenes)�� Ǯ��� */
/* https://ko.wikipedia.org/wiki/�����佺�׳׽���_ü ���� */
int main() {
	int M, N; // 1 <= M <= N <= 1,000,000
	cin >> M >> N;
	bool* prime = new bool[N + 1];
	for (int i = 2; i <= N; i++)
		prime[i] = true;
	for (int i = 2; i <= N; i++) {
		if (prime[i]) { // i is a prime number
			if (i >= M)
				cout << i << endl;
			for (int k = 2; i * k <= N; k++)
				prime[i * k] = false;
		}
	}
	delete[] prime;
	return 0;
}