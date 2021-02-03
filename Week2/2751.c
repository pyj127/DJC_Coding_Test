#include <stdio.h>
#include <stdlib.h>

int result[1000000];

//정복
void merge(int list[], int left, int mid, int right) {
	int i = left;
	int j = mid + 1;
	int k = left;

	while (i <= mid && j <= right) {
		if (list[i] <= list[j])
			result[k] = list[i++];
		else
			result[k] = list[j++];
		k++;
	}
	
	if (i > mid) {
		for (int u = j; u <= right; u++) {
			result[k] = list[u];
			k++;
		}
	}
	else {
		for (int u = i; u <= mid; u++) {
			result[k] = list[u];
			k++;
		}
	}
	
	for (int u = left; u <= right; u++) {
		list[u] = result[u];
	}
}

//분할
void mergeSort(int list[], int left, int right) {
	//array 크기가 1보다 큰 경우
	if (left < right) {
		//array 내에 정렬해야 될 element 존재

		int mid = (left + right) / 2;

		mergeSort(list, left, mid);
		mergeSort(list, mid + 1, right);

		merge(list, left, mid, right);
	}
}

int main() {
	int n;
	scanf("%d", &n);

	int* a = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	
	//merge sort
	mergeSort(a, 0, n - 1);
	
	for (int i = 0; i < n; i++) {
		printf("%d\n", a[i]);
	}

	free(a);
}