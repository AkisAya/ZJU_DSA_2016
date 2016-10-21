#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Read(); 
void Print( List L ); 

List Merge( List L1, List L2 );

int main()
{
    List L1, L2, L;
    L1 = Read();
    L2 = Read();
    L = Merge(L1, L2);
    Print(L);
    Print(L1);
    Print(L2);
    return 0;
}

// my code here; 
List Read() {
	List front, rear, temp;
	front = (List) malloc(sizeof(struct Node));
	front->Next = NULL;
	rear = front;
	int length;
	scanf("%d", &length);
	int num;
	while(length--) {
		scanf("%d", &num);
		List P = (List) malloc(sizeof(struct Node));
		P->Data = num;
		P->Next = NULL;
		rear->Next = P;
		rear = P;
	}
	temp = front;
	front = front->Next;
	free(temp);
	return front;
}

void Print(List L) {
	if (!L) 
	printf("NULL");
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
	printf("\n");
}

int Compare(int e1, int e2) {
	if (e1 < e2) {
		return 1;
	} else if (e1 > e2) {
		return -1;
	} else {
		return 0;
	}
}

List Merge(List L1, List L2) {
	List front, rear, temp;
	front = (List) malloc(sizeof(struct Node));
	rear = front;
	while (L1 && L2) {
		switch (Compare(L1->Data, L2->Data)) {
			case 1:
				rear->Next = L1;
				rear = L1;
				L1 = L1->Next;
				break;
			case -1:
				rear->Next = L2;
				rear = L2; 
				L2 = L2->Next;
				break;
			case 0:
				rear->Next = L1;
				rear = L1;
				L1 = L1->Next;
				rear->Next = L2;
				rear = L2; 
				L2 = L2->Next;
				break;
		}
	}
	for (; L1; L1 = L1->Next) {
		rear->Next = L1;
		rear = L1;
	}
	for (; L2; L2 = L2->Next) {
		rear->Next = L2;
		rear = L2;
	}
	
	temp = front;
	front = front->Next;
	free(temp);
	return front;
}





