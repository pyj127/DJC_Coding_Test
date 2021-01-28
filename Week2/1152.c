#include <stdio.h>

int main() {
	char s[1000000];
	int count = 0;
	
	for (int i = 0; i < 1000000; i++) {
		scanf("%c", &s[i]);
		if (s[i] == '\n')
			break;
	}
	for (int i = 1; i < 1000000; i++) {
		if (s[i] == ' ' && s[i - 1] != ' ' && s[i + 1] != ' ' && s[i + 1] != '\n')
			count++;
		if (s[i] == '\n')
			break;
	}
	if (s[0] == '\n' || (s[0] == ' ' && s[1] == '\n'))
		printf("0\n");
	else
		printf("%d\n", count+1);
}