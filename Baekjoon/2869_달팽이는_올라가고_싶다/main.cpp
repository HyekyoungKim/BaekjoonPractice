#include <iostream>

using namespace std;

/* Problem #2869 A Snail Wants To Go Up */
/* https://www.acmicpc.net/problem/2869 */
int main() {
	int A, B, V, day;
	cin >> A >> B >> V;
	day = (V - A) / (A - B);
	if (day * (A - B) == V - A)
		day++;
	else
		day += 2;
	cout << day;
	return 0;
}