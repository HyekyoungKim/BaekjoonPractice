#include <iostream>

using namespace std;

/* Problem #2775 */
/* https://www.acmicpc.net/problem/2775 */
int main() {
	int T, k, n;
	int room[15][15];
	for (int i = 1; i <= 14; i++)
		room[0][i] = i;
	for (int i = 1; i <= 14; i++)
		room[i][1] = room[i - 1][1];
	for (int floor = 1; floor <= 14; floor++)
		for (int room_num = 2; room_num <= 14; room_num++)
			room[floor][room_num] = room[floor][room_num - 1] + room[floor - 1][room_num];
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> k >> n;
		cout << room[k][n] << endl;
	}
	return 0;
}