#include <cstdio>
#include <queue>
using namespace std;

#define MaxNum 10
#define Node int
#define Null -1

struct TreeNode {
	Node Left;
	Node Right;
};

TreeNode T[MaxNum];

Node BuildTree(TreeNode T[]);
void PrintLeaves(Node headNode);
bool isLeaf(Node node);

int main () {
	Node headNode;
	headNode = BuildTree(T);
	PrintLeaves(headNode);
	return 0;
}

Node BuildTree(TreeNode T[]) {
	int N;
	scanf("%d\n", &N);
	int check[N];
	Node head = -1;
	if (N) {
		for (int i = 0; i < N; i++) check[i] = 0;		
		char cl, cr;		
		for (int i = 0; i < N; i++) {
			scanf("%c %c\n", &cl, &cr);
			if (cl != '-') {
				T[i].Left = cl - '0';
				check[T[i].Left] = 1;
			} else {
				T[i].Left = Null;
			}			
			if (cr != '-') {
				T[i].Right = cr - '0';
				check[T[i].Right] = 1;
			} else {
				T[i].Right = Null;
			}
		}
		
		for (int i = 0; i < N; i++) {
			if (!check[i]) {
				head = i;
				break;
			}
		}
	}
	return head;
}

bool isLeaf(Node node) {
	if (T[node].Left == Null && T[node].Right == Null)
	return true;
	else 
	return false;
}

bool isFirstLeaf = true;
void PrintLeaves(Node headNode) {
	if (headNode == Null) return;
	
    queue<int> intque;
    Node node;
	intque.push(headNode);
	while (!intque.empty()) {
		node = intque.front();
		intque.pop();
		
		if (isLeaf(node)) {
			if (isFirstLeaf) {
			printf("%d", node);
			isFirstLeaf = false;	
			} else {
				printf(" %d", node);
			}	
		}
		
		if (T[node].Left != Null) intque.push(T[node].Left);
		if (T[node].Right != Null) intque.push(T[node].Right);
	}		
	
}
