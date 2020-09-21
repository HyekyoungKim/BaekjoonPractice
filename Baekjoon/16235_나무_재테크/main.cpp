#include <iostream>
#include <list>
#include <queue>
using namespace std;

int main()
{
	int N, M, K;
	cin >> N >> M >> K;

	/* Initialize an N x N array A for the amount of nutrients to be added*/
	int** A = new int* [N+1];
	for (int i = 0; i < N + 1; i++)
		A[i] = new int[N + 1];
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> A[i][j];

	/* Initialize an N x N array nutrients for the amount of nutrients in each cell */
	int** nutrients = new int* [N + 1];
	for (int i = 0; i < N + 1; i++)
		nutrients[i] = new int[N + 1];
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			nutrients[i][j] = 5;

	/* Initialize an N x N array trees for the number of planted trees */
	list<int>** trees = new list<int>* [N + 1];
	for (int i = 0; i < N + 1; i++)
		trees[i] = new list<int>[N + 1];
	int x, y, z;
	for (int i = 0; i < M; i++) {
		cin >> x >> y >> z; // (x, y): position, z: age
		trees[x][y].push_back(z);
	}

	for (int year = 0; year < K; year++) {
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++) {
				/* Spring: the trees grow */
				priority_queue<int, vector<int>, greater<int>> pq;
				while (!trees[i][j].empty()) {
					pq.push(trees[i][j].front());
					trees[i][j].pop_front();
				}
				while (!pq.empty()) {
					int age = pq.top();
					if (age <= nutrients[i][j]) {
						nutrients[i][j] -= pq.top();
						pq.pop();
						trees[i][j].push_back(age + 1);
					}
					else
						break;
				}

				/* Summer: the dead trees turn into nutients */
				int amount = 0;
				while (!pq.empty()) {
					amount += pq.top() / 2;
					pq.pop();
				}
				nutrients[i][j] += amount;
			}

		/* Fall: the trees breed */
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++) {
				list<int>::iterator iter;
				for (iter = trees[i][j].begin(); iter != trees[i][j].end(); iter++) {
					if (*iter % 5 == 0) {
						if (i > 1) {
							if (j > 1)
								trees[i - 1][j - 1].push_back(1);
							trees[i - 1][j].push_back(1);
							if (j < N)
								trees[i - 1][j + 1].push_back(1);
						}
						if (j > 1)
							trees[i][j - 1].push_back(1);
						if (j < N)
							trees[i][j + 1].push_back(1);
						if (i < N) {
							if (j > 1)
								trees[i + 1][j - 1].push_back(1);
							trees[i + 1][j].push_back(1);
							if (j < N)
								trees[i + 1][j + 1].push_back(1);
						}
					}
				}
			}

		/* Winter: nutrients are added */
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				nutrients[i][j] += A[i][j];
	}

	/* Count the number of trees that survived */
	int count = 0;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			count += trees[i][j].size();
	cout << count;

	/* Free allocated memory */
	for (int i = 0; i < N + 1; i++)
		delete[] A[i];
	delete[] A;
	for (int i = 0; i < N + 1; i++)
		delete[] trees[i];
	delete[] trees;
	return 0;
}