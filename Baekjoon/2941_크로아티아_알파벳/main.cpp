#include <iostream>
#include <string>

using namespace std;

/* Problem #2941 LJESNJAK */
/* https://www.acmicpc.net/problem/2941 */
int main() {
	int count = 0;
	string s;
	cin >> s;
	int len = s.length();
	for (int i = 0; i < len; i++) {
		switch (s.at(i))
		{
		case 'c':
			if (i + 1 < len)
				switch (s.at(i + 1))
				{
				case '=':
				case '-':
					i++;
					break;
				default:
					break;
				}
			break;
		case 'd':
			if (i + 1 < len)
				switch (s.at(i + 1))
				{
				case 'z':
					if (i + 2 < len && s.at(i + 2) == '=')
						i += 2;
					break;
				case '-':
					i++;
				default:
					break;
				}
			break;
		case 'l':
		case 'n':
			if (i + 1 < len && s.at(i + 1) == 'j')
				i++;
			break;
		case 's':
		case 'z':
			if (i + 1 < len && s.at(i + 1) == '=')
				i++;
			break;
		default:
			break;
		}
		count++;
	}
	cout << count;
	return 0;
}