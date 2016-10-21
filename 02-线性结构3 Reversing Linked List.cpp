#include <cstdio>

typedef struct Node* List;
struct Node {
	int address;
	int data;
	int nextAddress;
	List link;
};

List reverseLinklist(List head, int K, int N);
void attach(int *a, List *ptr);
void Print(List list);

int main() {
	int N, K, headAddress;
	List head, rear;
	head = new Node;
	head->link = NULL;
	rear = head;
	scanf("%d %d %d", &headAddress, &N, &K);
	int a[N][3];
	
	for (int i = 0; i < N; i++) {
		scanf("%d %d %d", &a[i][0], &a[i][1], &a[i][2]);
		if (a[i][0] == headAddress) {
			attach(a[i], &rear);
		}
		
		if (rear->nextAddress == a[i][0]) {
			attach(a[i], &rear);
		}
	}
	
	while (rear->nextAddress != -1) {	
		for (int i = 0; i < N; i++) {
			if (rear->nextAddress == a[i][0]) {
				attach(a[i], &rear);
			} else if (rear->nextAddress == -1) {
				break;
			}
		}
	}
	
//	Print(head->link);

	List newList = new Node;
	newList->link = NULL;
	List subHead = newList;
	
	List tmp;
	
	while (head->link != NULL) {
		
		for (int i = 0; i < K; i++) {
			if (head->link == NULL) break;
			tmp = subHead->link;
			subHead->link = head->link;
			head->link = head->link->link;
			subHead->link->link = tmp;
		}
		
		// find new subhead
		while (subHead->link != NULL) {
			subHead = subHead->link;
		}
		
	}
	
	delete head;
	Print(newList->link);
	
	return 0;
} 

void attach(int *a, List *ptr) {
	List node = new Node;
	node->address = a[0];
	node->data = a[1];
	node->nextAddress = a[2];
	node->link = NULL;
	(*ptr)->link = node;
	(*ptr) = node;
}

void Print(List list) {
	while (list) {
		
		if (list->nextAddress != -1)
		printf("%05d %d %05d\n", list->address, list->data, list->nextAddress);
		else 
		printf("%05d %d %d", list->address, list->data, list->nextAddress);
		
		list = list->link;
	}
}

List reverseLinklist(List head, int K, int N) {
	
}








