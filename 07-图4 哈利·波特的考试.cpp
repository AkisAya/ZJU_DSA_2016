#include <stdio.h>

#define Inf 10001    // migic length less than 10000
#define maxNum 100

int nv, ne;
int D[maxNum][maxNum];


void createGraph() {
	for(int i = 0; i < nv; i++)
		for(int j = 0; j < nv; j++)
			D[i][j] = Inf;
}

void buildGraph() {
	scanf("%d %d", &nv, &ne);
	createGraph();
	
	int i, j, length;
	for(int k = 0; k < ne; k++) {
		scanf("%d %d %d", &i, &j, &length);
		D[i-1][j-1] = length;
		D[j-1][i-1] = length;          // no direction graph
	}	
}

void Floyd() {
	int u, v, w;
	
	for(u = 0; u < nv; u++)
		for(v = 0; v < nv; v++)
			for(w = 0; w < nv; w++) {
				if(D[v][u] + D[u][w] < D[v][w]) {
					D[v][w] = D[v][u] + D[u][w];
				}
			}
}

int findMax(int i) {
	int max = -1;
	for(int j = 0; j < nv; j++) {
		if(i != j && D[i][j] > max) {
			max = D[i][j];
		}
	}
	return max;
}

void findAnimal() {
	int maxDist, minDist, Animal;
	
	Floyd();
	
	minDist = Inf;
	for(int i = 0; i < nv; i++)	 {
		maxDist = findMax(i);
		if(maxDist == Inf) {
			printf("0\n");
			return;
		}
		
		if(minDist > maxDist) {
			minDist = maxDist;
			Animal = i + 1;
		}
	}
	
	printf("%d %d\n", Animal, minDist);
}
void print() {
	for(int i = 0; i < nv; i++) {
		for(int j = 0; j < nv; j++) {
				printf("%d ", D[i][j]);
			}
			printf("\n");
	}
		
}

int main() {
	
	buildGraph();
//	print();
	findAnimal();

	return 0;
} 
