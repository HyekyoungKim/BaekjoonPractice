#include <iostream>
#include <queue>

using namespace std;

/* Problem #1929 소수 구하기 */
/* https://www.acmicpc.net/problem/1929 */
/* 에라토스테네스의 체(Sieve of Eratosthenes)로 풀어보기 */
/* https://ko.wikipedia.org/wiki/에라토스테네스의_체 참조 */
int main() {
	int M, N; // 1 <= M <= N <= 1,000,000
	cin >> M >> N;
	priority_queue<int, vector<int>, greater<int>> not_prime;
	for (int i = 2; i <= N; i++) {
		if (not_prime.empty() || i != not_prime.top()) { // i is a prime number
			if (i >= M)
				cout << i << '\n'; // '\n' is faster than endl
			for (int k = 2; i * k <= N; k++)
				not_prime.push(i * k);
		}
		else // i is not a prime number
			while (!not_prime.empty() && i == not_prime.top())
				not_prime.pop();
	}
	return 0;
}