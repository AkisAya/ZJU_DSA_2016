#include <cstdio>
#include <cstdlib>

typedef struct PolyNode* Polynomial; 
struct PolyNode {
	int coef;
	int expon;
	Polynomial link;
};

Polynomial ReadPoly();
Polynomial Mult(Polynomial P1, Polynomial P2);
Polynomial Add(Polynomial P1, Polynomial P2);
void Print(Polynomial P);

int main() {
	
	Polynomial p1 = ReadPoly();
	Polynomial p2 = ReadPoly();
	Print(Mult(p1, p2));
	Print(Add(p1, p2));
	
	return 0;
}
void Attach(int c, int e, Polynomial *pRear) {
	Polynomial P;
	P = new PolyNode;
	P->coef = c;
	P->expon = e;
	P->link = NULL;
	(*pRear)->link = P;
	*pRear = P;
}

Polynomial ReadPoly() {
	Polynomial P, rear, tmp;
	int c, e, N;
	
	scanf("%d", &N);
	P = new PolyNode;
	P->link = NULL;
	rear = P;
	while(N--) {
		scanf("%d %d", &c, &e);
		Attach(c, e, &rear);
	}
	tmp = P;
	P = P->link;
	delete tmp;
	return P;
}

void Print(Polynomial P) {
	int flag = 0;
	if (!P) {
		printf("0 0\n");
		return;
	}
	
	while (P) {
		if (!flag) {
			flag = 1;
		} else {
			printf(" ");
		}
		
		printf("%d %d", P->coef, P->expon);
		P = P->link;
	}
	printf("\n");
}

Polynomial Add(Polynomial P1, Polynomial P2) {
	Polynomial P, rear, tmp;

	P = new PolyNode;
	P->link = NULL;
	rear = P;
	while(P1 && P2) {
		if (P1->expon == P2->expon) {
			int c = P1->coef + P2->coef;
			if (c != 0) {
				Attach(c, P1->expon, &rear);
			}
			P1 = P1->link;
			P2 = P2->link;
		} else if (P1->expon > P2->expon) {
			Attach(P1->coef, P1->expon, &rear);
			P1 = P1->link;
		} else {
			Attach(P2->coef, P2->expon, &rear);
			P2 = P2->link;
		}
	}
	
	for(; P1; P1 = P1->link) Attach(P1->coef, P1->expon, &rear);
	for(; P2; P2 = P2->link) Attach(P2->coef, P2->expon, &rear);
	
	tmp = P;
	P = P->link;
	delete tmp;
	return P;
}

Polynomial Mult(Polynomial P1, Polynomial P2) {
	Polynomial P, rear, tmp, t1, t2;
	int c, e;
	
	if (!P1 || !P2) return NULL;
	t1 = P1;
	t2 = P2;
	
	P = new PolyNode;
	P->link = NULL;
	rear = P;
	
	while (t2) {
		Attach(t1->coef * t2->coef, t1->expon + t2->expon, &rear);
		t2 = t2->link;
	}
	t1 = t1->link;
	while (t1) {
		t2 = P2;
		rear = P;
		while (t2) {
			e = t1->expon + t2->expon;
			c = t1->coef * t2->coef;
			while (rear->link && rear->link->expon > e) rear = rear->link;
			if (rear->link && rear->link->expon == e) {
				if (rear->link->coef + c) rear->link->coef += c;
				else {
					tmp = rear->link;
					rear->link = tmp->link;
					delete tmp;
				}
			} else {
				tmp = new PolyNode;
				tmp->coef = c;
				tmp->expon = e;
				tmp->link = rear->link;
				rear->link = tmp;
				rear = rear->link;
			}
			t2 = t2->link;
		}
		t1 = t1->link;
	}
	tmp = P;
	P = P->link;
	delete tmp;
	return P;
}











