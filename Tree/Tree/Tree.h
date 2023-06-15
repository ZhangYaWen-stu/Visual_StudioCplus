#pragma once
#include "Stack_Queue.h"
template<typename ElemType>
struct BinTreeNode
{
	ElemType data;
	BinTreeNode<ElemType>* leftchild;
	BinTreeNode<ElemType>* rightchild;
	BinTreeNode();
	BinTreeNode(const ElemType& e, BinTreeNode<ElemType>* leftchild = NULL, BinTreeNode<ElemType>* rightchild = NULL);
};

template<typename ElemType>
class BinaryTree
{
protected:
	bool IsBinarySortTree(BinTreeNode<ElemType>* troot);
	BinTreeNode<ElemType>* root;
	BinTreeNode<ElemType>* CopyTree(BinTreeNode<ElemType>* t);
	void Destroy(BinTreeNode<ElemType>* &r);
	void PreOrder(BinTreeNode<ElemType>* r, void(*Visit)(const ElemType&))const;
	void InOrder(BinTreeNode<ElemType>* r, void(*Visit)(const ElemType&))const;
	void PostOrder(BinTreeNode<ElemType>* r, void(*Visit)(const ElemType&))const;
	int Height(const BinTreeNode<ElemType>* r)const;
	int NodeCount(const BinTreeNode<ElemType>* r)const;
	BinTreeNode<ElemType>* Parent(BinTreeNode<ElemType>* r, const BinTreeNode<ElemType>* p)const;
	/*#############################################################################################################*/
	int LeafNode(BinTreeNode<ElemType>* r);
	void CreateBinaryTree(BinTreeNode<ElemType>* &e,ElemType p);
	BinTreeNode<ElemType>* GetMaxBalTree(BinTreeNode<ElemType>* troot);
	BinTreeNode<ElemType>* GetMinBalTree(BinTreeNode<ElemType>* troot);
public:
	BinaryTree();
	BinaryTree(const ElemType& r);
	~BinaryTree();
	BinTreeNode<ElemType>* GetRoot()const;
	bool IsEmpty()const;
	Status GetElem(BinTreeNode<ElemType>* p, ElemType& e)const;
	Status SetElem(BinTreeNode<ElemType>* p, ElemType e);
	void InOrder(void(*Visit)(const ElemType&))const;
	void PreOrder(void(*Visit)(const ElemType&))const;
	void PostOrder(void(*Visit)(const ElemType&))const;
	//void LevelOrder(void(*Visit)(const ElemType& e))const;
	int NodeCount()const;
	BinTreeNode<ElemType>* LeftChild(const BinTreeNode<ElemType>* p)const;
	BinTreeNode<ElemType>* RightChild(const BinTreeNode<ElemType>* p)const;
	BinTreeNode<ElemType>* LeftSibling(const BinTreeNode<ElemType>* p)const;
	BinTreeNode<ElemType>* RightSibling(const BinTreeNode<ElemType>* p)const;
	BinTreeNode<ElemType>* Parent(const BinTreeNode<ElemType>* p)const;
	void InsertLeftChild(BinTreeNode<ElemType>* p, ElemType e);
	void InsertRightChild(BinTreeNode<ElemType>* p, ElemType e);
	void DeleteLeftChild(BinTreeNode<ElemType>* p);
	void DeleteRightChild(BinTreeNode<ElemType>* p);
	int Height()const;
	void ClearTree();
	BinaryTree(const BinaryTree<ElemType>& e);
	BinaryTree(BinTreeNode<ElemType>* r);
	BinaryTree<ElemType>& operator=(const BinaryTree<ElemType>& e);
	/*#############################################################################*/
	void CreateBinaryTree();
	bool IsBinarySortTree();
	//void NoRecCreateBinaryTree();
	void InOrderNonRec(void(*Visit)(const ElemType& e))const;
	int LeafNode();
	void TestTreeChar();
	void TestTreeInt();
};



template<typename ElemType>
BinTreeNode<ElemType>::BinTreeNode()
{
	leftchild = rightchild = NULL;
}
template<typename ElemType>
BinTreeNode<ElemType>::BinTreeNode(const ElemType& e, BinTreeNode<ElemType>* leftchild, BinTreeNode<ElemType>* rightchild)
{
	data = e;
	this->leftchild = leftchild;
	this->rightchild = rightchild;
}
/*################################################################################################################################*/

template<typename ElemType>
BinTreeNode<ElemType>* BinaryTree<ElemType>::CopyTree(BinTreeNode<ElemType>* t)
{
	BinTreeNode<ElemType>* e = NULL;
	if (t != NULL)
	{
		e = new BinTreeNode<ElemType>(t->data);
		e->leftchild = CopyTree(t->leftchild);
		e->rightchild = CopyTree(t->rightchild);
	}
	return e;
}
template<typename ElemType>
void BinaryTree<ElemType>::Destroy(BinTreeNode<ElemType>*& r)
{
	if (r != NULL)
	{
		Destroy(r->leftchild);
		Destroy(r->rightchild);
		delete r;
		r = NULL;
	}
}
template<typename ElemType>
void BinaryTree<ElemType>::PreOrder(BinTreeNode<ElemType>* r, void(*Visit)(const ElemType&))const
{
	if (r != NULL)
	{
		Visit(r->data);
		PreOrder(r->leftchild, Visit);
		PreOrder(r->rightchild, Visit);
	}
}
template<typename ElemType>
void BinaryTree<ElemType>::InOrder(BinTreeNode<ElemType>* r, void(*Visit)(const ElemType&))const
{
	if (r != NULL)
	{
		InOrder(r->leftchild, Visit);
		Visit(r->data);
		InOrder(r->rightchild, Visit);
	}
}
template<typename ElemType>
void BinaryTree<ElemType>::PostOrder(BinTreeNode<ElemType>* r, void(*Visit)(const ElemType&))const
{
	if (r != NULL)
	{
		InOrder(r->leftchild, Visit);
		InOrder(r->rightchild, Visit);
		Visit(r->data);
	}
}
template<typename ElemType>
int BinaryTree<ElemType>::Height(const BinTreeNode<ElemType>* r)const
{
	if (r == NULL)
		return 0;
	if (Height(r->leftchild) > Height(r->rightchild))
		return Height(r->leftchild) + 1;
	else return Height(r->rightchild) + 1;
}
template<typename ElemType>
int BinaryTree<ElemType>::NodeCount(const BinTreeNode<ElemType>* r)const
{
	if (r == NULL)
		return 0;
	return NodeCount(r->leftchild) + NodeCount(r->rightchild) + 1;
}
template<typename ElemType>
BinTreeNode<ElemType>* BinaryTree<ElemType>::Parent(BinTreeNode<ElemType>* r, const BinTreeNode<ElemType>* p)const
{
	if (r != NULL || r == p)
	{
		if (r->leftchild == p || r->rightchild == p)
		{
			return r;
		}
		if (Parent(r->leftchild, p) != NULL)
			return Parent(r->leftchild, p);
		else return Parent(r->rightchild, p);
	}
	else return NULL;
}
template<typename ElemType>
BinaryTree<ElemType>::BinaryTree()
{
	root = NULL;
}
template<typename ElemType>
BinaryTree<ElemType>::BinaryTree(const ElemType& r)
{
	root = new BinTreeNode<ElemType>(r);
}
template<typename ElemType>
BinaryTree<ElemType>::~BinaryTree()
{
	Destroy(root);
}
template<typename ElemType>
BinTreeNode<ElemType>* BinaryTree<ElemType>::GetRoot()const
{
	return root;
}
template<typename ElemType>
bool BinaryTree<ElemType>::IsEmpty()const
{
	if (root == NULL)
		return true;
	else return false;
}
template<typename ElemType>
Status BinaryTree<ElemType>::GetElem(BinTreeNode<ElemType>* p, ElemType& e)const
{
	if (p == NULL)
		return FAIL;
	e = p->data;
	return SUCCESS;
}
template<typename ElemType>
Status BinaryTree<ElemType>::SetElem(BinTreeNode<ElemType>* p, ElemType e)
{
	if (p == NULL)
		return FAIL;
	p->data = e;
	return SUCCESS;
}
template<typename ElemType>
void BinaryTree<ElemType>::InOrder(void(*Visit)(const ElemType&))const
{
	InOrder(root, Visit);
}
template<typename ElemType>
void BinaryTree<ElemType>::PreOrder(void(*Visit)(const ElemType&))const
{
	PreOrder(root, Visit);
}
template<typename ElemType>
void BinaryTree<ElemType>::PostOrder(void(*Visit)(const ElemType&))const
{
	PostOrder(root, Visit);
}
template<typename ElemType>
int BinaryTree<ElemType>::NodeCount()const
{
	return NodeCount(root);
}
template<typename ElemType>
BinTreeNode<ElemType>* BinaryTree<ElemType>::LeftChild(const BinTreeNode<ElemType>* p)const
{
	if (p == NULL)
		throw FAIL;
	return p->leftchild;
}
template<typename ElemType>
BinTreeNode<ElemType>* BinaryTree<ElemType>::RightChild(const BinTreeNode<ElemType>* p)const
{
	if (p == NULL)
		throw FAIL;
	return p->rightchild;
}
template<typename ElemType>
BinTreeNode<ElemType>* BinaryTree<ElemType>::LeftSibling(const BinTreeNode<ElemType>* p)const
{
	BinTreeNode<ElemType>* tmp = Parent(p);
	if (tmp == NULL)
		throw FAIL;
	if (tmp->leftchild == p)
		return tmp->rightchild;
	return tmp->leftchild;
}
template<typename ElemType>
BinTreeNode<ElemType>* BinaryTree<ElemType>::RightSibling(const BinTreeNode<ElemType>* p)const
{
	BinTreeNode<ElemType>* tmp = Parent(p);
	if (tmp == NULL)
		throw FAIL;
	if (tmp->rightchild == p)
		return tmp->leftchild;
	return tmp->rightchild;
}
template<typename ElemType>
BinTreeNode<ElemType>* BinaryTree<ElemType>::Parent(const BinTreeNode<ElemType>* p)const
{
	return Parent(root, p);
}
template<typename ElemType>
void BinaryTree<ElemType>::InsertLeftChild(BinTreeNode<ElemType>* p, ElemType e)
{
	BinTreeNode<ElemType> *tmp=new BinTreeNode<ElemType>(e);
	tmp->leftchild = p->leftchild;
	p->leftchild = tmp;
}
template<typename ElemType>
void BinaryTree<ElemType>::InsertRightChild(BinTreeNode<ElemType>* p, ElemType e)
{
	BinTreeNode<ElemType> *tmp=new BinTreeNode<ElemType>(e);
	tmp->rightchild = p->rightchild;
	p->rightchild = tmp;
}
template<typename ElemType>
void BinaryTree<ElemType>::DeleteLeftChild(BinTreeNode<ElemType>* p)
{
	Destroy(p->leftchild);
}
template<typename ElemType>
void BinaryTree<ElemType>::DeleteRightChild(BinTreeNode<ElemType>* p)
{
	Destroy(p->rightchild);
}
template<typename ElemType>
int BinaryTree<ElemType>::Height()const
{
	return Height(root);
}
template<typename ElemType>
BinaryTree<ElemType>::BinaryTree(const BinaryTree<ElemType>& e)
{
	root = CopyTree(e.root);
}
template<typename ElemType>
BinaryTree<ElemType>::BinaryTree(BinTreeNode<ElemType>* r)
{
	root = new BinTreeNode<ElemType>(r->data, r->leftchild, r->rightchild);
}
template<typename ElemType>
BinaryTree<ElemType>& BinaryTree<ElemType>::operator=(const BinaryTree<ElemType>& e)
{
	Destroy(root);
	root = CopyTree(e.root);
}
template<typename ElemType>
void BinaryTree<ElemType>::ClearTree()
{
	if (root == NULL)
		return;
	Destroy(root->leftchild);
	Destroy(root->rightchild);
	delete[]root;
	root = NULL;
}
/*###########################################################################################*/
template<typename ElemType>
void BinaryTree<ElemType>::CreateBinaryTree(BinTreeNode<ElemType>*& e, ElemType p)
{
	if (p != '#')
	{
		e = new BinTreeNode<ElemType>(p);
		cout << "请输入左节点：";
		cin >> p;
		CreateBinaryTree(e->leftchild,p);
		cout << "请输入右节点：";
		cin >> p;
		CreateBinaryTree(e->rightchild,p);
	}
}
template<typename ElemType>
void BinaryTree<ElemType>::CreateBinaryTree()
{
	char tmp;
	ClearTree();
	cout << "请输入根节点:";
	cin >> tmp;
	CreateBinaryTree(root, tmp);
}

void BinaryTree<char>::TestTreeChar()
{
	if (root != NULL)
		Destroy(root);
	root = new BinTreeNode<char>('A');
	BinTreeNode<char>* tmp;
	tmp = root;
	tmp->leftchild = new BinTreeNode<char>('B');
	tmp->rightchild = new BinTreeNode<char>('C');
	tmp = tmp->leftchild;
	tmp->leftchild = new BinTreeNode<char>('D');
	tmp->rightchild = new BinTreeNode<char>('E');
	tmp = tmp->rightchild;
	tmp->leftchild = new BinTreeNode<char>('H');
	tmp = tmp->leftchild;
	tmp->rightchild = new BinTreeNode<char>('I');
	tmp = root->rightchild;
	tmp->rightchild = new BinTreeNode<char>('G');
	tmp->leftchild = new BinTreeNode<char>('F');
	tmp = tmp->leftchild;
	tmp->leftchild = new BinTreeNode<char>('J');
	tmp->rightchild = new BinTreeNode<char>('K');
}

void BinaryTree<int>::TestTreeInt()
{
	if (root != NULL)
		Destroy(root);
	root = new BinTreeNode<int>(39);
	root->leftchild = new BinTreeNode<int>(11);
	root->leftchild->leftchild = new BinTreeNode<int>(8);
	root->leftchild->rightchild = new BinTreeNode<int>(23);
	root->leftchild->rightchild->rightchild = new BinTreeNode<int>(44);
	root->rightchild = new BinTreeNode<int>(68);
	root->rightchild->leftchild = new BinTreeNode<int>(46);
	root->rightchild->rightchild = new BinTreeNode<int>(75);
	root->rightchild->rightchild->rightchild = new BinTreeNode<int>(86);
	root->rightchild->rightchild->leftchild = new BinTreeNode<int>(71);
}

template<typename ElemType>
void BinaryTree<ElemType>::InOrderNonRec(void(*Visit)(const ElemType& e))const
{
	int maxsize = NodeCount();
	if (maxsize == 0)
		return;
	Stack<BinTreeNode<ElemType>*> tmp(maxsize);
	BinTreeNode<ElemType>* p = root->leftchild;
	tmp.Push(root);
	while (!(tmp.IsEmpty() && p == NULL))
	{
		if (p!=NULL)
		{
			tmp.Push(p);
			p = p->leftchild;
		}
		else {
			tmp.Pop(p);
			Visit(p->data);
			p = p->rightchild;
		}
	}
}

template<typename ElemType>
int BinaryTree<ElemType>::LeafNode(BinTreeNode<ElemType>* r)
{
	if (r == NULL)
		return 0;
	if (r->leftchild == NULL && r->rightchild == NULL)
		return 1;
	return LeafNode(r->leftchild) + LeafNode(r->rightchild);
}
template<typename ElemType>
int BinaryTree<ElemType>::LeafNode()
{
	return LeafNode(root);
}

bool BinaryTree<int>::IsBinarySortTree()
{
	if (root == NULL)
		return true;
	return IsBinarySortTree(root);
}

template<>
bool BinaryTree<int>::IsBinarySortTree(BinTreeNode<int>* troot)
{
	if (troot == NULL)
		return true;
	if (IsBinarySortTree(troot->leftchild) && IsBinarySortTree(troot->rightchild))
	{
		BinTreeNode<int>* max = GetMaxBalTree(troot->leftchild);
		BinTreeNode<int>* min = GetMinBalTree(troot->rightchild);
		if (((max != NULL) && (troot->data < max->data)) || ((min != NULL) && (min->data < troot->data)))
			return false;
		return true;
	}
	return false;
}
template<>
BinTreeNode<int>* BinaryTree<int>::GetMaxBalTree(BinTreeNode<int>* troot)
{
	if (troot == NULL)
		return NULL;
	for (; troot->rightchild != NULL; troot = troot->rightchild);
	return troot;
}
template<>
BinTreeNode<int>* BinaryTree<int>::GetMinBalTree(BinTreeNode<int>* troot)
{
	if (troot == NULL)
		return NULL;
	for (; troot->leftchild != NULL; troot = troot->leftchild);
	return troot;
}