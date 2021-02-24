#include <stdio.h>
int k;
int s[13];
int temp[13];

void dfs(int node, int count) {
	if (count == 6) {
		for (int i = 0; i < 6; i++)
			printf("%d ", temp[i]);
		printf("\n");
		return;
	}
	for (int i = node; i < k; i++) {
		temp[count] = s[i];
		dfs(i + 1, count + 1);
	}
}

int main() {
	while (1) {
		scanf("%d", &k);

		if (!k)
			break;

		for (int i = 0; i < k; i++) {
			scanf("%d", &s[i]);
		}
		dfs(0, 0);
		printf("\n");
	}
}