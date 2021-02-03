#include <stdio.h>

int main() {
	int n1, n2;
	scanf("%d %d", &n1, &n2);

	int a = 1;
	int b1 = 0;
	int b2 = 0;
	int c = 0;

	int i = 2;
	while (1) {

		if (n1 % i == 0 && n2 % i == 0) {
			n1 /= i;
			n2 /= i;
			a *= i;
			b1 = n1;
			b2 = n2;
			c++;
		}

		else
			i++;
		
		if (i == 10000)
			break;
	}
	int b;
	if (c == 0) {
		b = n1 * n2;
	}
	else {
		b = a * b1 * b2;
	}
	
	printf("%d\n", a);
	printf("%d\n", b);
}