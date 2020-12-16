﻿#include <iostream>
#include <vector>
#define INF 9999999
using namespace std;

int main()
{
	int n = 3;
	int m = 3;
	//vector<vector<int>> a{
	//	{-1, -1, -1, -1, -1},
	//	{-1, 22, 19, 11, 13},
	//	{-1, 15, 12, 10, 18},
	//	{-1, 13, 22, 21, 26},
	//	{-1, 29, 10, 12, 22} };
	vector<vector<int>> a{
	{-1, -1, -1, -1},
	{-1, 1, 2, 3},
	{-1, 2, 1, 1},
	{-1, 1, 3, 2} };
	// a[n + 1][m + 1] - initial matrix
	// u, v - potential, u contains the most potential value
	// p - pairs, p[1...m] - row 1...n
	// way[m + 1] - where minimums are
	// minv[m + 1] - minimums needed to calculate potential
	// j0 - unused column  столбец, который хотим присвоить строке
	// i0 - adjacent row to j0 строка, которая сейчас его занимает
	// j1 - минимум достигнут

	vector<int> u(n + 1), v(m + 1), p(m + 1), way(m + 1);
	for (int i = 1; i <= n; ++i) {
		p[0] = i;
		int j0 = 0;
		vector<int> minv(m + 1, INF);
		vector<char> used(m + 1, false);
		do {
			used[j0] = true;
			int i0 = p[j0], delta = INF, j1;
			for (int j = 1; j <= m; ++j)
				if (!used[j]) {
					int cur = a[i0][j] - u[i0] - v[j];
					if (cur < minv[j])
						minv[j] = cur, way[j] = j0;
					if (minv[j] < delta)
						delta = minv[j], j1 = j;
				}
			for (int j = 0; j <= m; ++j)
				if (used[j])
					u[p[j]] += delta, v[j] -= delta;
				else
					minv[j] -= delta;
			j0 = j1;
		} while (p[j0] != 0);
		do {
			int j1 = way[j0];
			p[j0] = p[j1];
			j0 = j1;
		} while (j0);
	}
	vector<int> ans(n + 1);
	for (int j = 0; j <= m; ++j) {
		ans[p[j]] = j;
	}
	for (int i = 1; i <= n; i++) {
		cout << ans[i] << endl;
	}
	int cost = -v[0];
	cout << cost << endl;
}