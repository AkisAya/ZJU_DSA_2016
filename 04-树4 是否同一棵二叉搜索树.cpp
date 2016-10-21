#include <stdio.h>
#define MaxNum 10

int getArrayLength(int* array) {
	int i = 0;
	for (; i < MaxNum; i++) {
		if (array[i] == -1) break;
	}
	return i; 
}

void buildTree(int T[], int N) {
	for (int i = 0; i < N; i++) {
		scanf("%d", &T[i]);
	}
}

void Reset(int T[]) {
	for (int i = 0; i < MaxNum; i++) {
		T[i] = -1;
	}
}

void cutToNewTree(int T[], int L[], int R[]) {
	int N = getArrayLength(T);
	int Lcnt = 0, Rcnt = 0;
	for (int i = 1; i < N; i++) {
		if (T[i] > T[0]) R[Rcnt++] = T[i];
		else L[Lcnt++] = T[i];	
	}
}

bool judge(int T1[], int T2[]) {
	int length = getArrayLength(T1);
	if (length == 0) return true;
	else {
		if (T1[0] != T2[0]) return false;
		else if (length > 1) {
			int L1[MaxNum], R1[MaxNum], L2[MaxNum], R2[MaxNum];
			Reset(L1);
			Reset(L2);
			Reset(R1);
			Reset(R2);
			cutToNewTree(T1, L1, R1);
			cutToNewTree(T2, L2, R2);
			
			if (!judge(L1, L2)) return false;
			if (!judge(R1, R2)) return false;
		}
	}
	
	return true;
}


int main() {
	int N,L;
	int T1[MaxNum], T2[MaxNum];
	Reset(T1);
	Reset(T2); 
	scanf("%d", &N);
	while(N) {
		scanf("%d", &L);
		buildTree(T1, N);
		for (int i = 0; i < L; i++) {
			buildTree(T2, N);
			if (judge(T1, T2)) printf("Yes\n");
			else printf("No\n");
			
			
		}
		scanf("%d", &N);
	}
	
	return 0;
} 
