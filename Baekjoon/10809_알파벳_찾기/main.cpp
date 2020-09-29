#include <iostream>
#include <string>

using namespace std;

/* Problem #10809 Finding Alphabet */
/* https://www.acmicpc.net/problem/10809 */
int main() {
	int abc[26];
	for (int i = 0; i < 26; i++)
		abc[i] = -1;
	string s;
	cin >> s;
	int len = s.length();
	for (int i = 0; i < len; i++) {
		int idx = static_cast<int>(s.at(i)) - 'a';
		if (abc[idx] == -1)
			abc[idx] = i;
	}
	for (int i = 0; i < 26; i++)
		cout << abc[i] << " ";
	return 0;
}