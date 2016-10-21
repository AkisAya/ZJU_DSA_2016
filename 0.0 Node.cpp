#include <cstdio>
#include <cstdlib>

struct Node {
	int data;
	int data2;
	Node* Next;
};

typedef int ElementType;
typedef struct Code * PtrToNode;
struct Code {
    ElementType Data;
    PtrToNode   Next;
};

typedef PtrToNode List;

void Print(List L) {
	if (!L) 
	printf("NULL\n");
	int flag = 0;
	while(L) {
		if (!flag) {
			flag = 1;
		} else {
			printf(" ");
		}
		printf("%d", L->Data);
		L = L->Next;
	}
}

int main() {
//	Node *front = (Node*)malloc(sizeof(struct Node));
//	Node* rear;
//	Print(rear);
	List node;
	Print(node);
//	printf("%d", sizeof(struct Node));
//	if (!rear) {
//		printf("Null");
//	} else {
//		printf("Not Null");
//	}
	return 0;
}
