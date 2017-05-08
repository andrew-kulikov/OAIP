#include "stdafx.h"
#include <iostream>

using namespace std;

typedef struct _Node {
	int key;
	int height;
	_Node* left;
	_Node* right;
	_Node(int k) {
		key = k;
		left = right = 0;
		height = 1;
	}
} Node;

int Height(Node *p) {
	return p ? p->height : 0;
}

int BFactor(Node *p) {
	return Height(p->right) - Height(p->left);
}

void FixHeight(Node* p) {
	int hl = Height(p->left);
	int hr = Height(p->right);
	p->height = (hl > hr ? hl : hr) + 1;
}

Node* RotateRight(Node* p) {
	Node* q = p->left;
	p->left = q->right;
	q->right = p;
	FixHeight(p);
	FixHeight(q);
	return q;
}

Node* RotatLeft(Node* q) {
	Node* p = q->right;
	q->right = p->left;
	p->left = q;
	FixHeight(q);
	FixHeight(p);
	return p;
}

Node* RotateLeft(Node* q) {
	Node* p = q->right;
	q->right = p->left;
	p->left = q;
	FixHeight(q);
	FixHeight(p);
	return p;
}

Node* Balance(Node* p) {
	FixHeight(p);
	if (BFactor(p) == 2)
	{
		if (BFactor(p->right) < 0)
			p->right = RotateRight(p->right);
		return RotateLeft(p);
	}
	if (BFactor(p) == -2)
	{
		if (BFactor(p->left) > 0)
			p->left = RotateLeft(p->left);
		return RotateRight(p);
	}
	return p;
}

Node* InsertB(Node* p, int k) {
	if (!p) {
		return new Node(k);
	}
	if (k > p->key) {
		p->right = InsertB(p->right, k);
	}
	else {
		p->left = InsertB(p->left, k);
	}
	return Balance(p);
}

Node* Insert(Node* p, int k) {
	if (p == NULL) {
		return new Node(k);
	}
	if (k > p->key) {
		p->right = Insert(p->right, k);
	}
	else {
		p->left = Insert(p->left, k);
	}
	return p;
}

void BalanceAll(Node* root) {	
	if (root->right) {
		BalanceAll(root->right);
	}
	root = Balance(root);
	if (root->left) {
		BalanceAll(root->left);
	}
	root = Balance(root);
}

void PrintTree(Node* root, int level) {
	if (root->right != NULL) {
		PrintTree(root->right, level + 1);
	}
	for (int i = 0; i < level; i++) {
		cout << "-----";
	}
	cout << root->key << endl;
	if (root->left != NULL) {
		PrintTree(root->left, level + 1);
	}
}

int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int n, k;
	cin >> n >> k;
	Node* root = new Node(k);
	for (int i = 1; i < n; i++) {
		cin >> k;
		root = InsertB(root, k);
	}
	PrintTree(root, 0);
	return 0;
}