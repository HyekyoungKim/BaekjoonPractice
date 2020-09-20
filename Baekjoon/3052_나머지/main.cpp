#include <iostream>
using namespace std;

/* Problem #3052 MODULO */
/* https://www.acmicpc.net/problem/3052 */
int main()
{
	int remainder[42] = {};
	int num, count = 0;
	for (int i = 0; i < 10; i++) {
		cin >> num;
		remainder[num % 42] = 1;
	}
	for (int i = 0; i < 42; i++)
		if (remainder[i] == 1)
			count++;
	cout << count;
	return 0;
}