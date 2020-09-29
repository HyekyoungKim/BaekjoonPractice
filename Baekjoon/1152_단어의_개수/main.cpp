#include <iostream>
#include <sstream>

using namespace std;

/* Problem #1152 Word Count */
/* https://www.acmicpc.net/problem/1152 */
int main() {
	string s, temp;
	stringstream ss;
	int count = 0;
	getline(cin, s);
	ss.str(s);
	while (ss >> temp)
		count++;
	cout << count;
	return 0;
}