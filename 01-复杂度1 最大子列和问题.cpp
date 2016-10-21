# include <cstdio>

int main() {
	int length;
	scanf("%d", &length);
	int a[length];
	for (int i = 0; i < length; i++) {
		scanf("%d", &a[i]);
	}
	
	int currentSum = 0, maxSum = 0;
	for (int i = 0; i < length; i++) {
		currentSum += a[i];
		if (currentSum > maxSum) {
			maxSum = currentSum;
		}
		if (currentSum < 0) {
			currentSum = 0;
		}
	}
	printf("%d", maxSum);
} 
