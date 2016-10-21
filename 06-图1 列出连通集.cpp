#include <stdio.h>
#include <queue>

#define MaxV 10


int MGraph[MaxV][MaxV], Nv, Ne;

void CreateGraph() {
	scanf("%d %d", &Nv, &Ne);
	// init Graph
	for (int i = 0; i < Nv; i++) {
		for (int j = 0; j < Nv; j++) {
			MGraph[i][j] = 0; 
		}
	}
	// build graph
	int v, w;
	for (int i = 0; i < Ne; i++) {
		scanf("%d %d", &v, &w);
		MGraph[v][w] = 1;
		MGraph[w][v] = 1;  // no direction 
	}	
}

void OutputGraph(){
	for (int i = 0; i < Nv; i++) {
		for (int j = 0; j < Nv; j++){
			printf("%d ", MGraph[i][j]);
		}
		printf("\n");
	}	
}


bool visited[MaxV];

void DFS(int v) {
	int w;
	visited[v] = true;
	printf("%d ", v);
	for (w = 0; w < Nv; w++) {
		if (MGraph[v][w] == 1) { // w is adjcent to v
			if (!visited[w]) DFS(w);
		}
	}
}

void DFS_M() {
	for (int i = 0; i < Nv; i++) 
		visited[i] = false;
		
	for (int i = 0; i < Nv; i++) {
		if (!visited[i]){
			printf("{ ");
			DFS(i);
			printf("}\n");
		}
	}		
}

void BFS_M() {
	
	int v, w;
	
	for (int i = 0; i < Nv; i++) 
		visited[i] = false;
	
	std::queue<int> Q;
	for (int i = 0; i< Nv; i++) {
		if (!visited[i]) {
			printf("{ ");
			visited[i] = true;
			printf("%d ", i);
			Q.push(i);
			while (!Q.empty()) {
				v = Q.front();
				Q.pop();
				for (w = 0; w < Nv; w++) {
					if (MGraph[v][w] == 1) { // w is adjcent to v
						if (!visited[w]) {
							visited[w] = true;
							printf("%d ", w);
							Q.push(w);
						}
					}
				}
			}
			printf("}\n");
		}
	}
	
}

int main() {
	CreateGraph();
	DFS_M();
	BFS_M();	
	
	return 0;
} 
