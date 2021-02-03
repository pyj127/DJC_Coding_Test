#include <stdio.h>
#include <string.h>

int main() {
	char s[101];
	scanf("%s", s);

	int count = 0;

	for (int i = 0; i < strlen(s); i++) {
		if (s[i] == '0')
			continue;
		else if (i == (strlen(s) - 1)) {
			if (s[i] == '0')
				break;
			else
				count++;
		}
		else {
			if (s[i] == 'c') {
				if (s[i + 1] == '=' || s[i + 1] == '-') {
					count++;
					s[i] = '0';
					s[i + 1] = '0';
				}
				else
					count++;
			}
			else if (s[i] == 'd') {
				if (s[i + 1] == '-') {
					count++;
					s[i] = '0';
					s[i + 1] = '0';
				}
				else if (i < (strlen(s) - 2)) {
					if (s[i] == 'd' && s[i + 1] == 'z' && s[i + 2] == '=') {
						count++;
						s[i] = '0';
						s[i + 1] = '0';
						s[i + 2] = '0';
					}
					else
						count++;
				}
				else
					count++;
			}
			else if (s[i] == 'l' && s[i+1]=='j') {
				count++;
				s[i] = '0';
				s[i + 1] = '0';
			}
			else if (s[i] == 'n' && s[i + 1] == 'j') {
				count++;
				s[i] = '0';
				s[i + 1] = '0';
			}
			else if (s[i] == 's' && s[i + 1] == '=') {
				count++;
				s[i] = '0';
				s[i + 1] = '0';
			}
			else if (s[i] == 'z' && s[i + 1] == '=') {
				count++;
				s[i] = '0';
				s[i + 1] = '0';
			}
			else {
				count++;
				s[i] = '0';
			}
		}
	}
	printf("%d\n", count);
}