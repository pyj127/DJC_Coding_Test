#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);

	n = 1000 - n;
	int count = 0;

	while (1) {
		if (n >= 500) {
			n -= 500;
			count++;
		}
		else
			break;
	}

	while (1) {
		if (n >= 100) {
			n -= 100;
			count++;
		}
		else
			break;
	}

	while (1) {
		if (n >= 50) {
			n -= 50;
			count++;
		}
		else
			break;
	}

	while (1) {
		if (n >= 10) {
			n -= 10;
			count++;
		}
		else
			break;
	}

	while (1) {
		if (n >= 5) {
			n -= 5;
			count++;
		}
		else
			break;
	}
	
	while(1) {
		if (n >= 1) {
			n -= 1;
			count++;
		}
		else
			break;
	}
	printf("%d\n", count);
}