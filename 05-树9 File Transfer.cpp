#include <stdio.h>

struct Set {
	int data;
	int parent;
};

int N;
void InitSet(Set *S) {
	for (int i = 0; i < N; i++) {
		S[i].data = i + 1;
		S[i].parent = -1;
	}
}

int FindRoot(Set * S, int x) {
	int index = x-1;
	if (index >= N) return -10001;
//	for (; S[index].parent >= 0; index = S[index].parent);
	while (S[index].parent >= 0) {
		index = S[index].parent;
	}
	return index; 
} 

void Check(Set *S, int a, int b) {
	int root1 = FindRoot(S, a);
	int root2 = FindRoot(S, b);
	if (root1 == root2) 
		printf("yes\n");
	else 
		printf("no\n");
}

void Union(Set *S, int a, int b) {
	int root1, root2;
	root1 = FindRoot(S, a);
	root2 = FindRoot(S, b);
	
	if(root1 != root2) {
		if (S[root1].parent <= S[root2].parent) {
			S[root1].parent += S[root2].parent;
			S[root2].parent = root1;
		} else {
			S[root2].parent += S[root1].parent;
			S[root1].parent = root2;
		}
	}
}

int main() {
	scanf("%d\n", &N);
	Set S[N];
	InitSet(S);	
	char op;
	int a, b;
	scanf("%c", &op);
	while (op != 'S') {
		scanf(" %d %d\n",  &a, &b);
		if (op == 'C') {
			Check(S, a, b);
		} else { // op == 'I'
			Union(S, a, b);
		}
		scanf("%c", &op);
	}
	
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		if (S[i].parent < 0)
			cnt++;
	}
	if (cnt == 1)
		printf("The network is connected.");
	else
		printf("There are %d components.", cnt);	
	return 0;
}
