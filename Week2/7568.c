#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	int x[50];
	int y[50];

	for (int i = 0; i < n; i++) {
		scanf("%d %d", &x[i], &y[i]);
	}
	int result[50] = { 0 };

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (x[i] < x[j] && y[i] < y[j])
				result[i]++;
		}
	}
	for (int i = 0; i < n; i++) {
		printf("%d ", result[i] + 1);
	}
	printf("\n");
}