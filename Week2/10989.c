#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);

	int list[10000] = { 0 };

	for (int i = 0; i < n; i++) {
		int temp;
		scanf("%d", &temp);
		list[temp - 1]++;
	}

	for (int i = 0; i < 10000; i++) {
		while (list[i] != 0) {
			printf("%d\n", i+1);
			list[i]--;
		}
	}
}