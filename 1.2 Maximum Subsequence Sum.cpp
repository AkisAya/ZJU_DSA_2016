#include <cstdio>

int main() {
	int length;
	scanf("%d", &length);
	int a[length];
	for (int i = 0; i < length; i++) {
		scanf("%d", &a[i]);
	}
	
	int currentSum = 0, maxSum = -1;
	int first = a[0], last, temp = a[0];
	bool isSquenceChanged = false;
	bool isAllnegative = true; 	
	for (int i = 0; i < length; i++) {
		currentSum += a[i];
		if (isSquenceChanged) {
			temp = a[i];
			isSquenceChanged = false;
		}		
		if (currentSum > maxSum) {
			maxSum = currentSum;
			last = a[i];
			first = temp;
		}
		
		if (currentSum < 0) {
			currentSum = 0;
			isSquenceChanged = true;
		}		
		if (a[i] >= 0) isAllnegative = false;		
	}
	if (isAllnegative) {
		maxSum = 0;
		first = a[0];
		last = a[length -1];
	}
	printf("%d %d %d", maxSum, first, last);
}



