#include <iostream>
#include <cmath>

using namespace std;

/* Problem #1011 Fly Me To The Alpha Centauri */
/* https://www.acmicpc.net/problem/1011 */
int main() {
	int T, x, y, dist;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> x >> y;
		dist = y - x;
		/* �Ÿ��� n�� �� �ּ����� �۵� Ƚ���� step(n)�̶� �ϸ�,
		* step(1) = 1	<- 1
		* step(2) = 2	<- 1 1
		* step(3) = 3	<- 1 1 1
		* step(4) = 3	<- 1 2 1
		* step(5) = 4	<- 1 2 1 1
		* step(6) = 4	<- 1 2 2 1
		* step(7) = 5	<- 1 2 2 1 1
		* step(8) = 5	<- 1 2 2 2 1
		* step(9) = 5	<- 1 2 3 2 1
		* step(10) = 6	<- 1 2 3 2 1 1
		* ...
		* ���� n = 1, 2, 3, ...�� �� step(n)�� ������ ���� �����̴�.
		* n				|1	2	3	4	5	6	7	8	9	10	11	12	13	14	15	16	...
		* step			|1	2	3	3	4	4	5	5	5	6	6	6	7	7	7	7	...
		* (int)sqrt(n)	|1	1	1	2	2	2	2	2	3	3	3	3	3	3	3	4	...
		*/
		int k = (int)sqrt((double) dist);
		int step;
		if (dist == k * k)
			step = 2 * k - 1;
		else if (dist <= k * (k + 1))
			step = 2 * k;
		else
			step = 2 * k + 1;
		cout << step << endl;
	}
	return 0;
}