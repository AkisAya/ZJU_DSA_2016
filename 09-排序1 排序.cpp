#include <stdio.h>


void simpleSelectionSort(int A[], int N) {
	int i, j, min, tmp;
	
	for(i = 0; i < N - 1; i++) {
		min = i;
		for(j = i; j < N; j++) {
			if(A[j] < A[min]) 
				min = j;
		}
		tmp = A[i];
		A[i] = A[min];
		A[min] = tmp;
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
	
	simpleSelectionSort(a, N);
	print(a, N);
	
	return 0;	
}
