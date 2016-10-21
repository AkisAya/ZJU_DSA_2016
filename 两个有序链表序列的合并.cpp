#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node * PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};

typedef PtrToNode List;

List Read();
void Print( List L ); 

List Merge( List L1, List L2 );
void Attach(int data, List *PtrRear);

int Compare(int e1, int e2) {
	if (e1 < e2) {
		return 1;
	} else if (e1 > e2) {
		return -1;
	} else {
		return 0;
	}
}

int main()
{
    List L1 = NULL, L2 = NULL, L = NULL;
    L1 = Read();
    L2 = Read();
    L = Merge(L1, L2);
    Print(L);
    L1 = NULL;
    L2 = NULL;
    Print(L1);
    Print(L2);
    return 0;
}

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
		Attach(num, &rear);
	}
	temp = front;
	front = front->Next;
	free(temp);
	return front;
}

List Merge(List L1, List L2) {
	List front, rear, temp;
	front = (List) malloc(sizeof(struct Node));
	rear = front;
	while (L1 && L2) {
		switch (Compare(L1->Data, L2->Data)) {
			case 1:
				Attach(L1->Data, &rear);
				L1 = L1->Next;
				break;
			case -1:
				Attach(L2->Data, &rear);
				L2 = L2->Next;
				break;
			case 0:
				Attach(L2->Data, &rear);
				Attach(L1->Data, &rear);
				L1 = L1->Next;
				L2 = L2->Next;
				break;
		}
	}
	for (; L1; L1 = L1->Next) Attach(L1->Data, &rear);
	for (; L2; L2 = L2->Next) Attach(L2->Data, &rear);
	
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

void Attach(int data, List *PtrRear) {
	List P;
	P = (List) malloc(sizeof(struct Node));
	P->Data = data;
	P->Next = NULL;
	(*PtrRear)->Next = P;
	*PtrRear = P; 
}




