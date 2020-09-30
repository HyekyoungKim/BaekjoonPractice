#include <iostream>
#include <string>

using namespace std;

/* Problem #1316 Group Word Checker */
/* https://www.acmicpc.net/problem/1316 */
int main() {
	int N, count = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		string s;
		bool exist[26] = { false };
		cin >> s;
		int len = s.length();
		char context = '\0';
		int pos = 0;
		while (pos < len) {
			while (pos < len && s.at(pos) == context)
				pos++;
			if (pos >= len)
				break;
			char cur = s.at(pos);
			if (exist[cur - 'a'])
				break;
			else {
				exist[cur - 'a'] = true;
				context = cur;
				pos++;
			}
		}
		if (pos >= len)
			count++;
	}
	cout << count;
	return 0;
}