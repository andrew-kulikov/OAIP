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
    void TreeToArr(Node *root, int *tmpArray, int &i, UnicodeString* AllData);
    void _Balance(Node *&root, int *tmpArray, int left, int right, UnicodeString* AllData);
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
        int tmpArray[100];
        UnicodeString AllData[100];
        int amountOfNodes = 0;
        TreeToArr(root, tmpArray, amountOfNodes, AllData);
        _Balance(root, tmpArray, 0, amountOfNodes, AllData);
    }
};
