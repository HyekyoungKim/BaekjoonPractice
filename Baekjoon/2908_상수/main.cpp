#include <iostream>

using namespace std;

/* Problem #2908 FILIP */
/* https://www.acmicpc.net/problem/2908 */
int main() {
	int a, b;
	cin >> a >> b;
	int a1 = a % 10;
	int a2 = (a / 10) % 10;
	int a3 = a / 100;
	int b1 = b % 10;
	int b2 = (b / 10) % 10;
	int b3 = b / 100;
	if (a1 > b1 || (a1 == b1 && a2 > b2)
		|| (a1 == b1 && a2 == b2 && a3 > b3)) // a' > b'
		cout << a1 * 100 + a2 * 10 + a3;
	else // a' < b'
		cout << b1 * 100 + b2 * 10 + b3;
	
	return 0;
}