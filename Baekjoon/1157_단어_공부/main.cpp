#include <iostream>
#include <string>

using namespace std;

/* Problem #1157 Word Study */
/* https://www.acmicpc.net/problem/1157 */
int main() {
	int count[26] = { 0 };
	string s;
	cin >> s;
	int len = s.length();
	for (int i = 0; i < len; i++) {
		char c = s.at(i);
		if (c >= 'a' && c <= 'z')
			count[c - 'a']++;
		else if (c >= 'A' && c <= 'Z')
			count[c - 'A']++;
	}
	int max_idx = 0;
	bool dup = false;
	for (int i = 1; i < 26; i++) {
		if (count[i] == count[max_idx])
			dup = true;
		else if (count[i] > count[max_idx]) {
			dup = false;
			max_idx = i;
		}
	}
	if (dup)
		cout << "?";
	else
		cout << char('A' + max_idx);
	return 0;
}