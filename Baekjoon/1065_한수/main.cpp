#include <iostream>

using namespace std;

/* Problem #1065 ÇÑ¼ö */
/* https://www.acmicpc.net/problem/1065 */
bool isHansoo(int num) {
	if (num < 100)
		return true;
	int p = num % 10;
	num /= 10;
	int q = num % 10;
	int diff = p - q;
	while (num >= 10) {
		p = q;
		num /= 10;
		q = num % 10;
		if (p - q != diff)
			return false;
	}
	return true;
}

int main() {
	int N, count = 0;
	cin >> N;
	for (int i = 1; i <= N; i++)
		if (isHansoo(i))
			count++;
	cout << count;
	return 0;
}