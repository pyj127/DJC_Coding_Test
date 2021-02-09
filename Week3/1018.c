#include <stdio.h>
#include <limits.h>

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	
	char board[50][50];

	for (int i = 0; i < n; i++) {
		scanf("%s", &board[i]);
	}
	
	int count, count1;
	int min = INT_MAX;

	for (int i = 0; i <= n - 8; i++) {
		for (int j = 0; j <= m - 8; j++) {
			count = 0;
			count1 = 0;
			if (board[i][j] == 'W') {
				for (int u = 0; u < 8; u++) {
					for (int w = 0; w < 8; w++) {
						if (u % 2 == 0) {
							if (w % 2 == 0) {
								if (board[i + u][j + w] != 'W')
									count++;
							}
							else {
								if (board[i + u][j + w] != 'B')
									count++;
							}
						}
						else {
							if (w % 2 == 0) {
								if (board[i + u][j + w] != 'B')
									count++;
							}
							else {
								if (board[i + u][j + w] != 'W')
									count++;
							}
						}
					}
				}
				for (int u = 0; u < 8; u++) {
					for (int w = 0; w < 8; w++) {
						if (u % 2 == 0) {
							if (w % 2 == 0) {
								if (board[i + u][j + w] != 'B')
									count1++;
							}
							else {
								if (board[i + u][j + w] != 'W')
									count1++;
							}
						}
						else {
							if (w % 2 == 0) {
								if (board[i + u][j + w] != 'W')
									count1++;
							}
							else {
								if (board[i + u][j + w] != 'B')
									count1++;
							}
						}
					}
				}
				if (count1 < count)
					count = count1;
			}
			else {
				for (int u = 0; u < 8; u++) {
					for (int w = 0; w < 8; w++) {
						if (u % 2 == 0) {
							if (w % 2 == 0) {
								if (board[i + u][j + w] != 'B')
									count++;
							}
							else {
								if (board[i + u][j + w] != 'W')
									count++;
							}
						}
						else {
							if (w % 2 == 0) {
								if (board[i + u][j + w] != 'W')
									count++;
							}
							else {
								if (board[i + u][j + w] != 'B')
									count++;
							}
						}
					}
				}
				for (int u = 0; u < 8; u++) {
					for (int w = 0; w < 8; w++) {
						if (u % 2 == 0) {
							if (w % 2 == 0) {
								if (board[i + u][j + w] != 'W')
									count1++;
							}
							else {
								if (board[i + u][j + w] != 'B')
									count1++;
							}
						}
						else {
							if (w % 2 == 0) {
								if (board[i + u][j + w] != 'B')
									count1++;
							}
							else {
								if (board[i + u][j + w] != 'W')
									count1++;
							}
						}
					}
				}
				if (count1 < count)
					count = count1;
			}

			if (min > count) {
				min = count;
			}
		}
	}

	printf("%d\n", min);
}