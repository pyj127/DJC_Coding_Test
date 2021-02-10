#include <stdio.h>
int queue[50];

int front() {
	return queue[0];
}

int size() {
	int i = 0;
	while (queue[i] > 0) {
		i++;
	}
	return i;
}

int tmp_pos(int pos) {
	int s = size();
	int t = 0;
	for (int i = 0; i < s; i++) {
		if (pos == queue[i])
			break;
		else
			t++;
	}
	return t + 1;
}

void  op1() {
	int s = size();
	for (int i = 0; i < s - 1; i++) {
		queue[i] = queue[i + 1];
	}
	queue[s - 1] = 0;
}

void  op2() {
	int s = size();
	int temp = queue[0];
	for (int i = 0; i < s - 1; i++) {
		queue[i] = queue[i + 1];
	}
	queue[s - 1] = temp;
}

void  op3() {
	int s = size();
	int temp = queue[s - 1];
	
	for (int i = s - 2; i >= 0; i--) {
		queue[i + 1] = queue[i];
	}
	queue[0] = temp;
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);

	int pos[50];
	for (int i = 0; i < m; i++) {
		scanf("%d", &pos[i]);
	}
	
	for (int i = 0; i < n; i++) {
		queue[i] = i + 1;
	}
	int count = 0;

	for (int i = 0; i < m; i++) {
		if (pos[i] == front()) {
			//1번 연산
			op1();
		}
		else if (tmp_pos(pos[i]) <= size() / 2 + 1) {
			//2번 연산
			int t = tmp_pos(pos[i]);
			for (int j = 0; j < t - 1; j++) {
				op2();
				count++;
			}
			op1();
		}
		else {
			//3번 연산
			int t = tmp_pos(pos[i]);
			int s = size();
			for (int j = 0; j < s - t + 1; j++) {
				op3();
				count++;
			}
			op1();
		}
	}
	printf("%d\n", count);
}