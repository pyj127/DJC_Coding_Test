#include <stdio.h>
int matrix[5][5];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int count = 0;
int check[1000000] = { 0 };

void dfs(int x, int y, int sum, int c) {
	if (c == 5) {
		if (!check[sum]) {
			check[sum] = 1;
			count++;
		}
		return;
	}
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5)
			continue;
		dfs(nx, ny, sum * 10 + matrix[nx][ny], c + 1);
	}
}

int main() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			scanf("%d", &matrix[i][j]);
		}
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			dfs(i, j, matrix[i][j], 0);

		}
	}
	printf("%d\n", count);
}