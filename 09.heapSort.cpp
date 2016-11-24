#include <stdio.h>


void adjust(int a[], int i, int N) {
	int child, tmp;
	for(tmp = a[i]; (2 * i + 1) < N; i = child) {
		child = 2 * i + 1;
		if (child != N - 1 && a[child + 1] > a[child])
			child++;
		if(tmp < a[child])
			a[i] = a[child];
		else 
			break;
	}
	a[i] = tmp;
}

void heapSort(int a[], int N) {
	int i, tmp;
	// build the maxheap
	for(i = (N - 1) / 2; i >= 0; i--)
		adjust(a, i, N);
	
	for(i = N - 1; i > 0; i--) {
		tmp = a[0];
		a[0] = a[i];
		a[i] = tmp;
		adjust(a, 0 ,i);
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
	
	heapSort(a, N);
	print(a, N);
	
	return 0;	
}
