#include <stdio.h>
int m, n, k;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int matrix[50][50] = { 0 };
int visited[50][50] = { 0 };
int count;

void dfs(int x, int y) {
	visited[x][y] = 1;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx >= m || ny < 0 || ny >= n)
			continue;
		if (matrix[nx][ny] && !visited[nx][ny]) 
			dfs(nx, ny);
	}
}

int main() {
	int T;
	scanf("%d", &T);
	for (int t = 0; t < T; t++) {
		scanf("%d %d %d", &m, &n, &k);

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				matrix[i][j] = 0;
				visited[i][j] = 0;
			}
		}
		for (int i = 0; i < k; i++) {
			int x, y;
			scanf("%d %d", &x, &y);
			matrix[x][y] = 1;
		}
		count = 0;

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (matrix[i][j] && !visited[i][j]) {
					count++;
					dfs(i, j);
				}
			}
		}

		printf("%d\n", count);
	}
}