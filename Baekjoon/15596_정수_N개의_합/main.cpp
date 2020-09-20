#include <vector>
#include <iostream>

/* Problem #15596 정수 N개의 합*/
/* https://www.acmicpc.net/problem/15596 */
long long sum(std::vector<int> &a)
{
	long long ans = 0;
	int n = a.size();
	for (int i = 0; i < n; i++)
		ans += a[i];
	return ans;
}

int main()
{
	std::vector<int> a = { 1,2,3,4,5,6,7,8,9,10 };
	std::cout << sum(a) << std::endl;
	return 0;
}