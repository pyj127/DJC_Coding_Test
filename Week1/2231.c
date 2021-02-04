#include <stdio.h>
#include <math.h>

int main() {
	int n;
	scanf("%d", &n);
	int result = 0;

	for (int i = n ; i > 0; i--) {
		int temp = 0;
		if (i >= 10 && i < 100) {
			temp = i + i / 10 + i % 10;
		}
		if (i >= 100 && i < 1000) {
			temp = i;
			int t = temp;
			for (int j = 2; j >= 1; j--) {
				temp += t / (int)pow(10, j);
				t = t % (int)pow(10, j);
			}
			temp += t;
		}
		if (i >= 1000 && i < 10000) {
			temp = i;
			int t = temp;
			for (int j = 3; j >= 1; j--) {
				temp += t / (int)pow(10, j);
				t = t % (int)pow(10, j);
			}
			temp += t;
		}
		if (i >= 10000 && i < 100000) {
			temp = i;
			int t = temp;
			for (int j = 4; j >= 1; j--) {
				temp += t / (int)pow(10, j);
				t = t % (int)pow(10, j);
			}
			temp += t;
		}
		if (i >= 100000 && i < 1000000) {
			temp = i;
			int t = temp;
			for (int j = 5; j >= 1; j--) {
				temp += t / (int)pow(10, j);
				t = t % (int)pow(10, j);
			}
			temp += t;
		}
		if (i == 1000000) {
			temp = i;
			int t = temp;
			for (int j = 6; j >= 1; j--) {
				temp += t / (int)pow(10, j);
				t = t % (int)pow(10, j);
			}
			temp += t;
		}
		if (temp == n) {
			result = i;
		}
	}
	printf("%d\n", result);
}