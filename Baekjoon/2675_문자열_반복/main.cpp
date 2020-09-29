#include <iostream>
#include <string>

using namespace std;

/* Problem #2675 Repeating Characters */
/* https://www.acmicpc.net/problem/2675 */
int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int R;
		string S;
		cin >> R >> S;
		int len = S.length();
		for (int j = 0; j < len; j++)
			for (int k = 0; k < R; k++)
				cout << S.at(j);
		cout << endl;
	}
	return 0;
}