#pragma hdrstop

#include "BinaryTree.h"

void PrintNode(Node *root, TMemo *Memo)
{
    UnicodeString s = root->key;
    UnicodeString s1 = root->data;
    UnicodeString s2 = "(";
    UnicodeString s3 = ")";
    Memo->Lines->Add(s + s2 + s1 + s3);
}

//вставка узла
Node* BinaryTree::_Insert(Node* root, int k, UnicodeString s)
{
    if (root == NULL)
        return new Node(k, s);
    if (k > root->key)
        root->right = _Insert(root->right, k, s);
    else
        root->left = _Insert(root->left, k, s);
    return root;
}

//нумерация узлов дерева
void BinaryTree::_SetNumbers(Node* p, int &i)
{
    if (!p)
        return;
    p->number = i;
    i++;
    if (p->right)
        _SetNumbers(p->right, i);
    if (p->left)
        _SetNumbers(p->left, i);
}

//вывод дерева в TreeView
void BinaryTree::_Show(Node* p, TTreeView *TreeView)
{
    if(!p)
        return;
    if (!p->number)
        TreeView->Items->AddObject(NULL, p->key, p);
    if (p->right) {
        TreeView->Items->AddChildObject(TreeView->Items->Item[p->number],
            p->right->key, p->right);
        _Show(p->right, TreeView);
    }
    if (p->left) {
        TreeView->Items->AddChildObject(TreeView->Items->Item[p->number],
            p->left->key, p->left);
        _Show(p->left, TreeView);
    }
}

//прямой обход
void BinaryTree::_Path1(Node *root, TMemo *Memo)
{
    if(root) {
        PrintNode(root, Memo);
    }
    if(root->left)
        _Path1(root->left, Memo);
    if(root->right)
        _Path1(root->right, Memo);
}

//обратный обход
void BinaryTree::_Path2(Node *root, TMemo *Memo)
{
    if(root->left)
        _Path2(root->left, Memo);
    if(root->right)
        _Path2(root->right, Memo);
    if(root) {
        PrintNode(root, Memo);
    }
}

//обход в порядке возрастания ключа
void BinaryTree::_Path3(Node *root, TMemo *Memo)
{
    if(root->left)
        _Path3(root->left, Memo);
    if(root) {
        PrintNode(root, Memo);
    }
    if(root->right)
        _Path3(root->right, Memo);
}

//поиск уззла с ключом k
void BinaryTree::_Find(UnicodeString &s, Node *root, int k)
{
    if (!root)
        return;
    if (k > root->key)
        _Find(s, root->right, k);
    else if (k < root->key)
        _Find(s, root->left, k);
    else {
        s = root->data;
        return;
    }
}

//поиск узла с минимальным ключом в левой ветке улза root
Node* BinaryTree::FindMin(Node* root)
{
    if (root->left)
        return FindMin(root->left);
    else
        return root;
}

//удаление узла с минимальным ключом из ветки с началом в root
Node* BinaryTree::RemoveMin(Node* root)
{
    if (!root->left)
        return root->right;
    root->left = RemoveMin(root->left);
    return root;
}

//удаление узла дерева
Node* BinaryTree::_Remove(Node* root, int k)
{
    if (!root)
        return root;
    else if (k > root->key)
        root->right = _Remove(root->right, k);
    else if (k < root->key)
        root->left = _Remove(root->left, k);
    else {
        Node* l = root->left;
        Node* r = root->right;
        delete root;
        if (!r)
            return l;
        Node* min = FindMin(r);
        min->right = RemoveMin(r);
        min->left = l;
        return min;
    }
    return root;
}

//поиск узла с ключом, ближайшим к k
void BinaryTree::FindNearestNode(Node* root, Node* &res, int &minDelta, int k)
{
    if (!root)
        return;
    else if (root) {
        if (abs(root->key - k) < minDelta) {
            minDelta = abs(root->key - k);
            res = root;
        }
    }
    if (root->right)
        FindNearestNode(root->right, res, minDelta, k);
    if (root->left)
        FindNearestNode(root->left, res, minDelta, k);
}

//еще один поиск узла с ключом, ближайшим к k (уменьшаем количество параметров)
Node* BinaryTree::_FindNear(Node* root, int k)
{
    int minDelta = 100000;
    Node* res;
    FindNearestNode(root, res, minDelta, k);
    return res;
}

//вынесение дерева в массив(по возрастанию)
void BinaryTree::TreeToArr(Node *root, int *tmpArray, int &i, UnicodeString* AllData)
{
    if (!root)
        return;
    if (root->left)
        TreeToArr(root->left, tmpArray, i, AllData);
    if (root) {
        AllData[i] = root->data;
        tmpArray[i] = root->key;
        i++;
    }
    if (root->right)
        TreeToArr(root->right, tmpArray, i, AllData);
}

//балансировка дерева
void BinaryTree::_Balance(Node *&root, int *tmpArray, int left, int right, UnicodeString* AllData)
{
    if (left == right) {
        root = NULL;
        return;
    }
    int mid = (left + right) / 2;
    root = new Node(tmpArray[mid], AllData[mid]);
    _Balance(root->left, tmpArray, left, mid, AllData);
    _Balance(root->right, tmpArray, mid + 1, right, AllData);
}

#pragma package(smart_init)
