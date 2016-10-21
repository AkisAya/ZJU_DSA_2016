#include <stdio.h>

#define Set int
int N;
void InitSet(Set *S) {
	for (int i = 0; i < N; i++) {
		S[i]= -1;
	}
}

// compress the path
int FindRoot(Set *S, int index) {
	if (S[index] < 0) {
		return index;
	} else {
		S[index] = FindRoot(S, S[index]);	
		return S[index];
//		return S[index] = FindRoot(S, S[index]);		
	}
}

void Check(Set *S, int a, int b) {
	int root1 = FindRoot(S, a-1);
	int root2 = FindRoot(S, b-1);
	if (root1 == root2) 
		printf("yes\n");
	else 
		printf("no\n");
}

void Union(Set *S, int a, int b) {
	int root1, root2;
	root1 = FindRoot(S, a-1);
	root2 = FindRoot(S, b-1);
	
	if(root1 != root2) {
		if (S[root1] <= S[root2]) {
			S[root1] += S[root2];
			S[root2] = root1;
		} else {
			S[root2] += S[root1];
			S[root1] = root2;
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
		if (S[i] < 0)
			cnt++;
	}
	if (cnt == 1)
		printf("The network is connected.");
	else
		printf("There are %d components.", cnt);	
	return 0;
}
