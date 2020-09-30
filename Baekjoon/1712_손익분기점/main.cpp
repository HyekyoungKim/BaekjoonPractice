#include <iostream>

using namespace std;

/* Problem #1712 Break-even Point */
/* https://www.acmicpc.net/problem/1712 */
int main() {
	/* A: fixed cost, B: variable cost,
	C: unit price, x: sales volume */
	int A, B, C, x;
	cin >> A >> B >> C;
	/* cost: A + Bx, sales: Cx,
	profit: Cx - (A + Bx)
	Let x' be the break-even point.
	Then, x' = A / (C - B) + 1 if C > B.
	If C <= B, then there is no break-even point. */
	if (C <= B)
		cout << -1;
	else
		cout << A / (C - B) + 1;

	return 0;
}