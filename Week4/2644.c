#include <stdio.h>
int n, n1, n2, m;
int visited[100] = { 0 };
int result = 0;
int matrix[100][100] = { 0 };


void dfs(int cur_vertex, int count) {
	visited[cur_vertex] = 1;

	if (cur_vertex == n2 - 1) {
		result = count;
		return;
	}
	for (int i = 0; i < n; i++) {
		if (matrix[cur_vertex][i] && !visited[i]) {
			dfs(i, count + 1);
		}
	}
}

int main() {
	scanf("%d", &n);
	scanf("%d %d", &n1, &n2);
	scanf("%d", &m);

	for (int i = 0; i < m; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		matrix[x - 1][y - 1] = 1;
		matrix[y - 1][x - 1] = 1;
	}
	dfs(n1 - 1, 0);
	if (result == 0)
		printf("-1\n");
	else
		printf("%d\n", result);
}