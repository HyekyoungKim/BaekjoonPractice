#include <iostream>

using namespace std;

/* Problem #10250 ACM Hotel */
/* https://www.acmicpc.net/problem/10250 */
int main() {
	int T, H, W, N, floor, room;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> H >> W >> N;
		floor = (N % H == 0 ? H : N % H);
		room = (N % H == 0 ? N / H : N / H + 1);
		if (room < 10)
			cout << floor << "0" << room << endl;
		else
			cout << floor << room << endl;
	}
	return 0;
}