#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int queue[2000000] = { 0 };
int front = -1;
int rear = -1;

void push(int n) {
	queue[++rear] = n;
}

void pop() {
	if (rear == front)
		printf("-1\n");
	else {
		front += 1;
		printf("%d\n", queue[front]);
	}
}

void size() {
	printf("%d\n", rear-front);
}

void empty() {
	if (rear == front)
		printf("1\n");
	else
		printf("0\n");
}

void print_front() {
	if (rear == front)
		printf("-1\n");
	else
		printf("%d\n", queue[front + 1]);
}
void print_back() {
	if (rear == front)
		printf("-1\n");
	else
		printf("%d\n", queue[rear]);
}

int main() {
	int n;
	scanf("%d", &n);
	getchar();

	char s[7];
	for (int i = 0; i < n; i++) {
		scanf("%[^\n]s", s);
		if (strstr(s, "push") != NULL) {
			char* temp = strtok(s, " ");
			temp = strtok(NULL, " ");
			int t = atoi(temp);
			push(t);
		}
		else if (strcmp(s, "pop") == 0) {
			pop();
		}
		else if (strcmp(s, "size") == 0) {
			size();
		}
		else if (strcmp(s, "empty") == 0) {
			empty();
		}
		else if (strcmp(s, "front") == 0) {
			print_front();
		}
		else if (strcmp(s, "back") == 0) {
			print_back();
		}
		getchar();
	}
}