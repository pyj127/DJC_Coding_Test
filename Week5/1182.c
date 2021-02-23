#include <stdio.h>
int n, s;
int arr[20];
int count = 0;

void dfs(int node, int sum) {
	if (node == n)
		return;
	if (sum + arr[node] == s)
		count++;

	dfs(node + 1, sum + arr[node]);
	dfs(node + 1, sum);
}

int main() {
	scanf("%d %d", &n, &s);
	
	for (int i = 0; i < n; i++) 
		scanf("%d", &arr[i]);

	dfs(0, 0);
	printf("%d\n", count);
}