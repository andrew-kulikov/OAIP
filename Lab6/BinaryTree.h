#include "vcl.h"

//��������� ���� ������
typedef struct _Node {
	int key;
    int number;
	int height;
    UnicodeString data;
	_Node* left;
	_Node* right;
	_Node(int k, UnicodeString s) {
        data = s;
		key = k;
		left = right = 0;
		height = 1;
	}
} Node;

class BinaryTree {
private:
    Node* root;
    Node* _Insert(Node* root, int k, UnicodeString s);
    void _SetNumbers(Node* p, int &i);
    void _Show(Node* p, TTreeView *TreeView);
    void _Path1(Node *root, TMemo *Memo);
    void _Path2(Node *root, TMemo *Memo);
    void _Path3(Node *root, TMemo *Memo);
    void _Find(UnicodeString &s, Node *root, int k);
    Node* FindMin(Node* root);
    Node* RemoveMin(Node* root);
    Node* _Remove(Node* root, int k);
    void FindNearestNode(Node* root, Node* &res, int &minDelta, int k);
    Node* _FindNear(Node* root, int k);
    void TreeToArr(Node *root, int *a, int &i, UnicodeString* s);
    void _Balance(Node *&root, int *a, int l, int r, UnicodeString* s);
public:
	//�����������
    SearchTree() {
        root = NULL;
    }
    //���������� ������ ������
    Node* GetRoot() {
        return root;
    }
    //������� ���� � ������
    void Insert(int k, UnicodeString s) {
        root = _Insert(root, k, s);
    }
    //����� ������ � TreeView
    void Show(TTreeView *TreeView) {
         TreeView->Items->Clear();
         int i = 0;
        _SetNumbers(root, i);
        _Show(root, TreeView);
    }
    //������ ����� ������
    void Path1(TMemo *Memo) {
        Memo->Lines->Clear();
        _Path1(root, Memo);
    }
    //�������� ����� ������
    void Path2(TMemo *Memo) {
        Memo->Lines->Clear();
        _Path2(root, Memo);
    }
    //����� ������ � ������� ����������� �����
    void Path3(TMemo *Memo) {
        Memo->Lines->Clear();
        _Path3(root, Memo);
    }
    //����� �������� �� �����
    void Find(UnicodeString &s, int k) {
        _Find(s, root, k);
    }
    //�������� ���� ������
    void Remove(int k) {
        root = _Remove(root, k);
    }
    //����� �������� � ������, ��������� � k
    Node* FindNear(int k) {
        return _FindNear(root, k);
    }
    //������������ ������
    void Balance() {
        int a[100];
        UnicodeString s[100];
        int n = 0;
        TreeToArr(root, a, n, s);
        _Balance(root, a, 0, n, s);
    }
};
