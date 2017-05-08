#include <iostream>
#include <string>

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

void AmOfNodes(Node* root, int &n) {
	if (!root) return;
	n++;
	AmOfNodes(root->right, n);
	AmOfNodes(root->left, n);
}

void TreeToArr(Node *root, int *a, int &i) {
	if (root->left) {
		TreeToArr(root->left, a, i);
	}
	if (root) {
		a[i] = root->key;
		i++;
	}
	if (root->right) {
		TreeToArr(root->right, a, i);
	}
}

void Remake(Node *&root, int *a, int l, int r) {
	if (l == r) {
		root = NULL;
		return;
	}
	int m = (l + r) / 2;
	root = new Node(a[m]);
	Remake(root->left, a, l, m);
	Remake(root->right, a, m + 1, r);
}

int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int n, k;
	cin >> n >> k;
	Node* root = new Node(k);
	for (int i = 1; i < n; i++) {
		cin >> k;
		root = Insert(root, k);
	}
	PrintTree(root, 0);
	int m = 0;
	//AmOfNodes(root, n);
	int a[100] = { 0 };
	TreeToArr(root, a, m);
	cout << endl;
	for (int i = 0; i < m; i++) {
		cout << a[i] << " ";
	}
	Remake(root, a, 0, n);
	cout << endl;
	PrintTree(root, 0);
	return 0;
}