#include <stdio.h>


void insertionSort(int a[], int N) {
	
	int i, j, tmp;
	for(i = 1; i < N; i++) {
		tmp = a[i];
		for(j = i; (j > 0) && tmp < a[j - 1]; j--) {
			a[j] = a[j - 1];
		}
		a[j] = tmp;			
	}
}

void print(int a[], int n) {
	printf("%d", a[0]);
	for(int i = 1; i < n; i++) 
		printf(" %d", a[i]);
}


int main() {
	int N;	
	scanf("%d", &N);
	int a[N];
	for(int i = 0; i < N; i++)
		scanf("%d", &a[i]);
	
	insertionSort(a, N);
	print(a, N);
	
	return 0;	
}
