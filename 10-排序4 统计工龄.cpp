#include<stdio.h>
#define MAX 51

int main() {
	
	int n;
	scanf("%d", &n);
	int a[n];
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	
	int b[MAX];
	for(int i = 0; i < MAX; i++)
		b[i] = 0;
	
	for(int i = 0; i < n; i++) {
		b[a[i]]++;
	}
	
	for(int i = 0; i < MAX; i++) {
		if(b[i] != 0) {
			printf("%d:%d\n", i, b[i]);
		}
	}
	
	return 0;
}
