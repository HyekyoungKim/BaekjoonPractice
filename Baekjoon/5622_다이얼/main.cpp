#include <iostream>
#include <string>

using namespace std;

/* Problem #5622 BAKA */
/* https://www.acmicpc.net/problem/5622 */
int main() {
	string s;
	cin >> s;
	int len = s.length();
	int count = 0;
	for (int i = 0; i < len; i++) {
		switch (s.at(i))
		{
		case 'A': 
		case 'B':
		case 'C':
			count += 3;
			break;
		case 'D':
		case 'E':
		case 'F':
			count += 4;
			break;
		case 'G':
		case 'H':
		case 'I':
			count += 5;
			break;
		case 'J':
		case 'K':
		case 'L':
			count += 6;
			break;
		case 'M':
		case 'N':
		case 'O':
			count += 7;
			break;
		case 'P':
		case 'Q':
		case 'R':
		case 'S':
			count += 8;
			break;
		case 'T':
		case 'U':
		case 'V':
			count += 9;
			break;
		case 'W':
		case 'X':
		case 'Y':
		case 'Z':
			count += 10;
			break;
		default:
			break;
		}
	}
	cout << count;
	return 0;
}