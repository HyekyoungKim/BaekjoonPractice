#include <iostream>

using namespace std;

/* Problem #1193 Finding a Fraction */
/* https://www.acmicpc.net/problem/1193 */
int main() {
	int X, numerator = 1, denominator = 1, count = 1;
	bool down_left = true;
	cin >> X;
	for (int i = 1; count < X; i++) {
		if (down_left)
			denominator++;
		else
			numerator++;
		count++;
		for (int j = 0; j < i && count < X; j++) {
			if (down_left) {
				numerator++;
				denominator--;
			}
			else {
				numerator--;
				denominator++;
			}
			count++;
		}
		down_left = !down_left;
	}
	cout << numerator << "/" << denominator;
	return 0;
}