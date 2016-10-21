#include <cstdio>

#define MaxSize 10
#define ElementType char
#define Node int
#define Null -1

struct TreeNode {
	ElementType element;
	Node left;
	Node right;
};

TreeNode T1[MaxSize], T2[MaxSize];

Node BuildTree(TreeNode T[]);
bool Isomophic(Node R1, Node R2);

int main () {
	
	int R1, R2;
	R1 = BuildTree(T1);
	R2 = BuildTree(T2);
	
	if (Isomophic(R1, R2)) printf("Yes\n");
	else printf("No\n");	
	return 0;
} 


Node BuildTree(TreeNode T[]) {
	int Num; // node number
	scanf("%d\n", &Num);
	char cl, cr;
	int check[Num];
	if (Num) {
		
	    for (int i = 0; i < Num; i++) check[i] = 0;
	    
		for (int i = 0; i < Num; i++) {
		
			scanf("%c %c %c\n", &T[i].element, &cl, &cr);
		
			if (cl != '-') {
				T[i].left = cl - '0';
				check[T[i].left] = 1;
			} else {
				T[i].left = Null;
			}
		
			if (cr != '-') {
				T[i].right = cr - '0';
				check[T[i].right] = 1;
			} else {
				T[i].right = Null;
			}
		}
	
		int position = 0;
		for (; position < Num; position++) {
			if (!check[position]) break;
		}
		return position;
	}
	return -1;
}


bool Isomophic(Node R1, Node R2) {
	
	if (R1 == Null && R2 == Null) return 1;
	
	if ((R1 == Null && R2 != Null) || (R1 != Null && R2 == Null)) return 0;
	
	if (T1[R1].element != T2[R2].element) return 0;
	
	if (T1[R1].left == Null && T2[R2].left == Null) return Isomophic(T1[R1].right, T2[R2].right);
	
	if ((T1[R1].left != Null && T2[R2].left != Null) && T1[T1[R1].left].element == T2[T2[R2].left].element) 
		return (Isomophic(T1[R1].left, T2[R2].left) && Isomophic(T1[R1].right, T2[R2].right));
	else
		return (Isomophic(T1[R1].left, T2[R2].right) && Isomophic(T1[R1].right, T2[R2].left)); 
	
} 




