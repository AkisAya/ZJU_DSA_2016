#include <stdio.h>

#define CAPCITY 1001
#define MINH -10001

int H[CAPCITY], size;

void create() {
	H[0] = MINH;
	size = 0; 	
}

void insert(int x) {
	int i = ++size;
	for(; x < H[i/2]; i = i/2) {
		H[i] = H[i/2]; 
	}
	H[i] = x;	
}

void output(int index) {
	printf("%d", H[index]);
	index = index / 2;
	while (index > 0) {
		printf(" %d", H[index]);
		index = index / 2;
	}
}



int main() {
	// create the MinHeap
	create();
	int N, M;
	int x, index;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		scanf("%d", &x);
		insert(x);
	}

	for (int i = 0; i < M; i++) {
		scanf("%d", &index);
		output(index);
		printf("\n");
	}
	
	return 0;
} 
