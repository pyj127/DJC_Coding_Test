#include <stdio.h>

int main() {
	int n, m;
	scanf("%d %d", &n, &m);

	char s[1000][51];

	for (int i = 0; i < n; i++) {
		scanf("%s", s[i]);
	}

	int count_A, count_C, count_G, count_T;
	int count = 0;
	char result[51];

	for (int i = 0; i < m; i++) {
		count_A = 0;
		count_C = 0;
		count_G = 0;
		count_T = 0;

		for (int j = 0; j < n; j++) {
			if (s[j][i] == 'A') {
				count_A++;
			}
			if (s[j][i] == 'C') {
				count_C++;
			}
			if (s[j][i] == 'G') {
				count_G++;
			}
			if (s[j][i] == 'T') {
				count_T++;
			}
		}
		if (count_A >= count_C && count_A >= count_G && count_A >= count_T) {
			result[i] = 'A';
			count += (n - count_A);
		}
		else if (count_C > count_A && count_C >= count_G && count_C >= count_T) {
			result[i] = 'C';
			count += (n - count_C);
		}
		else if (count_G > count_A && count_G > count_C && count_G >= count_T) {
			result[i] = 'G';
			count += (n - count_G);
		}
		else if (count_T > count_A && count_T > count_C && count_T > count_G) {
			result[i] = 'T';
			count += (n - count_T);
		}
	}
	for (int i = 0; i < m; i++) {
		printf("%c", result[i]);
	}
	printf("\n");
	printf("%d\n", count);
}