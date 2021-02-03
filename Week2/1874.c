#include <stdio.h>
#include <stdlib.h>

int stack[100005] = { 0 };
int level = -1;
char result[200005];
int c = 0;

void push(int n) {
	stack[++level] = n;
	result[c++] = '+';
}

int pop() {
	level--;
	result[c++] = '-';
	return stack[level + 1];
}

int comp(int *lst, int *temp, int n) {
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (lst[i] == temp[i])
			cnt++;
	}
	if (cnt == n)
		return 1;
	return 0;
}

int main() {
	int n;
	scanf("%d", &n);

	int* lst = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &lst[i]);
	}
	if (n == 1) {
		printf("+\n-\n");
	}
	else {
		int k = 0;
		int* temp = (int*)malloc(sizeof(int) * n);
		int t = 0;
		for (int i = 0; i < n; i++) {
			push(i + 1);
			if (level != -1) {
				while (level != -1 && stack[level] == lst[k]) {
					temp[t++] = pop();
					k++;
				}
			}
		}

		while (level != -1) {
			temp[t++] = pop();
		}

		if (comp(lst, temp, n) == 1) {
			for (int j = 0; j < c; j++) {
				printf("%c\n", result[j]);
			}
		}
		else {
			printf("NO\n");
		}
		free(temp);
	}

	free(lst);
}