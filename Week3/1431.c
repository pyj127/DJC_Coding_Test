#include <stdio.h>
#include <string.h>

struct S {
	char str[51];
	int length;
	int sum;
};

int main() {
	int n;
	scanf("%d", &n);

	struct S s[1000];
	for (int i = 0; i < n; i++) {
		scanf("%s", s[i].str);
		s[i].length = strlen(s[i].str);
		s[i].sum = 0;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < s[i].length; j++) {
			if ((s[i].str[j] >= '0' && s[i].str[j] <= '9')) {
				s[i].sum += s[i].str[j] - '0';
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (s[i].length < s[j].length) {
				struct S temp;
				temp = s[i];
				s[i] = s[j];
				s[j] = temp;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i != j && s[i].length == s[j].length) {
				if (s[i].sum == 0 && s[j].sum == 0) {
					for (int k = 0; k < s[i].length; k++) {
						if (s[i].str[k] < s[j].str[k] && i > j) {
							struct S temp;
							temp = s[i];
							s[i] = s[j];
							s[j] = temp;
							break;
						}
						if (s[i].str[k] > s[j].str[k] && i < j) {
							struct S temp;
							temp = s[i];
							s[i] = s[j];
							s[j] = temp;
							break;
						}
						if (s[i].str[k] == s[j].str[k])
							continue;
						else
							break;
					}
				}
				else if (s[i].sum == 0) {
					if (i > j) {
						struct S temp;
						temp = s[i];
						s[i] = s[j];
						s[j] = temp;
					}
				}
				else if (s[j].sum == 0) {
					if (i < j) {
						struct S temp;
						temp = s[i];
						s[i] = s[j];
						s[j] = temp;
					}
				}
				else {
					if (s[i].sum < s[j].sum) {
						if (i > j) {
							struct S temp;
							temp = s[i];
							s[i] = s[j];
							s[j] = temp;
						}
					}
					if (s[i].sum == s[j].sum) {
						for (int k = 0; k < s[i].length; k++) {
							if (s[i].str[k] < s[j].str[k] && i > j) {
								struct S temp;
								temp = s[i];
								s[i] = s[j];
								s[j] = temp;
								break;
							}
							if (s[i].str[k] > s[j].str[k] && i < j) {
								struct S temp;
								temp = s[i];
								s[i] = s[j];
								s[j] = temp;
								break;
							}
							if (s[i].str[k] == s[j].str[k])
								continue;
							else
								break;
						}
					}
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		printf("%s\n", s[i].str);
	}
}