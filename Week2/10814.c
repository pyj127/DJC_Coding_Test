#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct info {
	int age;
	char name[101];
	int time;
}info;

int compare(const void* m, const void* n) {
	struct info* a, * b;
	a = (struct info*)m;
	b = (struct info*)n;

	if (a->age < b->age)
		return -1;
	if (a->age == b->age && a->time < b->time)
		return -1;
	if (a->age > b->age)
		return 1;
	if (a->age == b->age && a->time > b->time)
		return 1;
	return 0;
}

int main() {
	int n;
	scanf("%d", &n);
	
	struct info *p = (info *)malloc(sizeof(struct info) * n);
	int t = 0;

	for (int i = 0; i < n; i++) {
		scanf("%d %s", &p[i].age, &p[i].name);
		p[i].time = t;
		t++;
	}

	qsort(p, n, sizeof(p[0]), compare);
	
	for (int i = 0; i < n; i++) {
		printf("%d %s\n", p[i].age, p[i].name);
	}
}