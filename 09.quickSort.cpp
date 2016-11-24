#include <stdio.h>


void swap(int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp; 
}

void qSort(int a[], int low, int high) {
//	int pivot = a[low];
	int pivotPoint;
	
	int medium = (low + high) / 2;
	if (a[low] >= a[high] && a[low] <= a[medium] || a[low] <= a[high] && a[low] >= a[medium])
		pivotPoint = low;
	else if(a[medium] >= a[high] && a[medium] <= a[low] || a[medium] >= a[low] && a[medium] <= a[high])
		pivotPoint = medium;
	else 
		pivotPoint = high;
		
	int pivot = a[pivotPoint];	
	int left = low, right = high;
	
	if(low >= high) return;
	swap(&a[pivotPoint], &a[right]);  // swap the pivot with the last one
	while(1) {
		while((low < high) && (pivot >= a[low])) low++;
		while((low < high) && (pivot <= a[high])) high--;
		
		if(low < high)
			swap(&a[low], &a[high]);
		else
			break;
	}
	swap(&a[low], &a[right]);  // swap the pivot with the last one
	
	qSort(a, left, low-1);
	qSort(a, low+1, right); 
}

void quickSort(int a[], int N) {
	qSort(a, 0, N-1);
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
	
	quickSort(a, N);
	print(a, N);
	
	return 0;	
}
