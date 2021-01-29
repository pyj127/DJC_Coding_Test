#include <stdio.h>
#include <limits.h>

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	int a[100];

	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	int min = INT_MAX;
	int result = 0; 

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			for (int k = j + 1; k < n; k++) {
				int temp = m - (a[i] + a[j] + a[k]);

				if (min > temp && temp >= 0) {
					min = temp;
					result = a[i] + a[j] + a[k];
				}
			}
		}
	}
	printf("%d\n", result);
}