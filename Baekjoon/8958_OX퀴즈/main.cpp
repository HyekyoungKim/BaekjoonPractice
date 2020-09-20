#include <iostream>
#include <string>
using namespace std;

/* Problem #8958 Score */
/* https://www.acmicpc.net/problem/8958 */
int main()
{
	int T, points, sum;
	string s;
	cin >> T;
	for (int i = 0; i < T; i++) {
		points = 0;
		sum = 0;
		cin >> s;
		for (unsigned int j = 0; j < s.length(); j++) {
			if (s.at(j) == 'X')
				points = 0;
			else
				points++;
			sum += points;
		}
		cout << sum << endl;
	}
	return 0;
}