#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

struct Node {
	int data;
	Node *left;
	Node *right;
	Node(int d):data(d), left(NULL), right(NULL) {}
};
typedef Node* Tree;

Tree buildTree();

bool isFirstData = true;
void postOrderTraversal(Tree T) {
	if (T) {
		postOrderTraversal(T->left);
		postOrderTraversal(T->right);
		if (isFirstData) {
			cout << T->data;
			isFirstData = false;
		} else {
			cout << " " << T->data;
		}
	}
}

int main () {
	Tree newTree;
	newTree = buildTree();
	postOrderTraversal(newTree);
	return 0;
}

Tree buildTree() {
	int N, data;
	cin >> N;
	string op;
	Node *root = NULL, *parent = NULL; 
	stack<Node*> st;
	int flag = 0; // jugde if it turns to left or right subtree
	for (int i = 1; i <= 2*N; i++) {
		Node* newNode;
		cin >> op;
		if (op == "Push") {
			cin >> data;
			newNode = new Node(data);
			if (i == 1) {
				root = newNode;
			}
			
			st.push(newNode);
			
			if (parent) {
				if (flag == 0) {
					parent->left = newNode;
				} else {
					parent->right = newNode;
				}
			}
			flag = 0;
			parent = newNode;
		} else {
			parent = st.top();
			st.pop();
			flag = 1;
		}
	}
	
	return root;
}
