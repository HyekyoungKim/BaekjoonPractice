#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

/* Problem #16235 Tree Investment */
/* https://www.acmicpc.net/problem/16235 */
int main()
{
	int N, M, K;
	cin >> N >> M >> K;

	/* Initialize an N x N array A for the amount of nutrients to be added*/
	int A[11][11];
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> A[i][j];

	/* Initialize an N x N array (nutrients) for the amount of nutrients in each cell */
	int nutrients[11][11];
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			nutrients[i][j] = 5;

	/* Initialize an N x N array (trees) for the planted trees in each cell */
	deque<int> trees[11][11];
	int x, y, z;
	for (int i = 0; i < M; i++) {
		cin >> x >> y >> z; // (x, y): position, z: age
		trees[x][y].push_back(z);
	}
	for (int i = 1; i < N; i++)
		for (int j = 1; j < N; j++)
			sort(trees[i][j].begin(), trees[i][j].end()); // Trees are sorted in ascending order of age.


	for (int year = 0; year < K; year++) {
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++) {
				/* Spring: trees grow */
				deque<int> temp;
				while (!trees[i][j].empty()) {
					int age = trees[i][j].front();
					if (age <= nutrients[i][j]) {
						nutrients[i][j] -= age;
						trees[i][j].pop_front();
						temp.push_back(age + 1);
					}
					else // For all remaining trees, age > nutrients[i][j].
						break;
				}
				
				/* Summer: the dead trees turn into nutients */
				int amount = 0;
				while (!trees[i][j].empty()) {
					amount += trees[i][j].front() / 2;
					trees[i][j].pop_front();
				}
				nutrients[i][j] += amount;
				trees[i][j].swap(temp);
			}

		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++) {
				/* Fall: the trees breed */
				deque<int>::iterator iter;
				for (iter = trees[i][j].begin(); iter != trees[i][j].end(); iter++) {
					if (*iter % 5 == 0) {
						// Use push_front() instead of push_back() to maintain the deque in ascending order
						if (i > 1) {
							if (j > 1)
								trees[i - 1][j - 1].push_front(1);
							trees[i - 1][j].push_front(1);
							if (j < N)
								trees[i - 1][j + 1].push_front(1);
						}
						if (j > 1)
							trees[i][j - 1].push_front(1);
						if (j < N)
							trees[i][j + 1].push_front(1);
						if (i < N) {
							if (j > 1)
								trees[i + 1][j - 1].push_front(1);
							trees[i + 1][j].push_front(1);
							if (j < N)
								trees[i + 1][j + 1].push_front(1);
						}
					}
				}

				/* Winter: nutrients are added */
				nutrients[i][j] += A[i][j];
			}
	}

	/* Count the number of trees that survived */
	int count = 0;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			count += trees[i][j].size();
	cout << count;

	return 0;
}