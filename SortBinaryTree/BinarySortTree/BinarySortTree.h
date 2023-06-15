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
class BinarySortTree
{
protected:
	BinTreeNode<ElemType>* root;
	BinTreeNode<ElemType>* CopyTree(BinTreeNode<ElemType>* t);
	void Destroy(BinTreeNode<ElemType>* &r);
	void PreOrder(BinTreeNode<ElemType>* r, void(*Visit)(const ElemType&))const;
	void InOrder(BinTreeNode<ElemType>* r, void(*Visit)(const ElemType&))const;
	void PostOrder(BinTreeNode<ElemType>* r, void(*Visit)(const ElemType&))const;
	int Height(const BinTreeNode<ElemType>* r)const;
	int NodeCount(const BinTreeNode<ElemType>* r)const;
	BinTreeNode<ElemType>* Parent(BinTreeNode<ElemType>* r, const BinTreeNode<ElemType>* p)const;
	BinTreeNode<ElemType>* Find(BinTreeNode<ElemType> *&troot, ElemType& e);
	void Delete(BinTreeNode<ElemType>*& troot);
	void Findx(BinTreeNode<ElemType>* troot, ElemType e);
	/*#############################################################################################################*/
	
public:
	BinarySortTree();
	BinarySortTree(const ElemType& r);
	~BinarySortTree();
	BinTreeNode<ElemType>* GetRoot()const;
	bool IsEmpty()const;
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
	int Height()const;
	void ClearTree();
	BinarySortTree(const BinarySortTree<ElemType>& e);
	BinarySortTree(BinTreeNode<ElemType>* r);
	BinarySortTree<ElemType>& operator=(const BinarySortTree<ElemType>& e);
	BinTreeNode<ElemType>* Find(ElemType e);
	Status InsertNode(ElemType e);
	Status DelNode(ElemType e);
	void Findx(ElemType e);
	/*#############################################################################*/
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
BinTreeNode<ElemType>* BinarySortTree<ElemType>::CopyTree(BinTreeNode<ElemType>* t)
{
	BinTreeNode<ElemType>* e = NULL;
	if (t != NULL)
	{
		e = new BinTreeNode<ElemType>(t->data, NULL, NULL, t->balance);
		e->leftchild = CopyTree(t->leftchild);
		e->rightchild = CopyTree(t->rightchild);
	}
	return e;
}
template<typename ElemType>
void BinarySortTree<ElemType>::Destroy(BinTreeNode<ElemType>*& r)
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
void BinarySortTree<ElemType>::PreOrder(BinTreeNode<ElemType>* r, void(*Visit)(const ElemType&))const
{
	if (r != NULL)
	{
		Visit(r->data);
		PreOrder(r->leftchild, Visit);
		PreOrder(r->rightchild, Visit);
	}
}
template<typename ElemType>
void BinarySortTree<ElemType>::InOrder(BinTreeNode<ElemType>* r, void(*Visit)(const ElemType&))const
{
	if (r != NULL)
	{
		InOrder(r->leftchild, Visit);
		Visit(r->data);
		InOrder(r->rightchild, Visit);
	}
}
template<typename ElemType>
void BinarySortTree<ElemType>::PostOrder(BinTreeNode<ElemType>* r, void(*Visit)(const ElemType&))const
{
	if (r != NULL)
	{
		InOrder(r->leftchild, Visit);
		InOrder(r->rightchild, Visit);
		Visit(r->data);
	}
}
template<typename ElemType>
int BinarySortTree<ElemType>::Height(const BinTreeNode<ElemType>* r)const
{
	if (r == NULL)
		return 0;
	if (Height(r->leftchild) > Height(r->rightchild))
		return Height(r->leftchild) + 1;
	else return Height(r->rightchild) + 1;
}
template<typename ElemType>
int BinarySortTree<ElemType>::NodeCount(const BinTreeNode<ElemType>* r)const
{
	if (r == NULL)
		return 0;
	return NodeCount(r->leftchild) + NodeCount(r->rightchild) + 1;
}
template<typename ElemType>
BinTreeNode<ElemType>* BinarySortTree<ElemType>::Parent(BinTreeNode<ElemType>* r, const BinTreeNode<ElemType>* p)const
{
	if (r != NULL && p != NULL)
	{
		if (r->leftchild == p || r->rightchild == p)
			return r;
		if (r->data > p->data)
			return Parent(r->leftchild, p);
		else return Parent(root->rightchild, p);
	}
	return NULL;
}
template<typename ElemType>
BinarySortTree<ElemType>::BinarySortTree()
{
	root = NULL;
}
template<typename ElemType>
BinarySortTree<ElemType>::BinarySortTree(const ElemType& r)
{
	root = new BinTreeNode<ElemType>(r);
}
template<typename ElemType>
BinarySortTree<ElemType>::~BinarySortTree()
{
	Destroy(root);
}
template<typename ElemType>
BinTreeNode<ElemType>* BinarySortTree<ElemType>::GetRoot()const
{
	return root;
}
template<typename ElemType>
bool BinarySortTree<ElemType>::IsEmpty()const
{
	if (root == NULL)
		return true;
	else return false;
}

template<typename ElemType>
void BinarySortTree<ElemType>::InOrder(void(*Visit)(const ElemType&))const
{
	InOrder(root, Visit);
}
template<typename ElemType>
void BinarySortTree<ElemType>::PreOrder(void(*Visit)(const ElemType&))const
{
	PreOrder(root, Visit);
}
template<typename ElemType>
void BinarySortTree<ElemType>::PostOrder(void(*Visit)(const ElemType&))const
{
	PostOrder(root, Visit);
}
template<typename ElemType>
int BinarySortTree<ElemType>::NodeCount()const
{
	return NodeCount(root);
}
template<typename ElemType>
BinTreeNode<ElemType>* BinarySortTree<ElemType>::LeftChild(const BinTreeNode<ElemType>* p)const
{
	if (p == NULL)
		throw FAIL;
	return p->leftchild;
}
template<typename ElemType>
BinTreeNode<ElemType>* BinarySortTree<ElemType>::RightChild(const BinTreeNode<ElemType>* p)const
{
	if (p == NULL)
		throw FAIL;
	return p->rightchild;
}
template<typename ElemType>
BinTreeNode<ElemType>* BinarySortTree<ElemType>::LeftSibling(const BinTreeNode<ElemType>* p)const
{
	BinTreeNode<ElemType>* tmp = Parent(p);
	if (tmp == NULL)
		throw FAIL;
	if (tmp->leftchild == p)
		return tmp->rightchild;
	return tmp->leftchild;
}
template<typename ElemType>
BinTreeNode<ElemType>* BinarySortTree<ElemType>::RightSibling(const BinTreeNode<ElemType>* p)const
{
	BinTreeNode<ElemType>* tmp = Parent(p);
	if (tmp == NULL)
		throw FAIL;
	if (tmp->rightchild == p)
		return tmp->leftchild;
	return tmp->rightchild;
}
template<typename ElemType>
BinTreeNode<ElemType>* BinarySortTree<ElemType>::Parent(const BinTreeNode<ElemType>* p)const
{
	return Parent(root, p);
}

template<typename ElemType>
int BinarySortTree<ElemType>::Height()const
{
	return Height(root);
}
template<typename ElemType>
BinarySortTree<ElemType>::BinarySortTree(const BinarySortTree<ElemType>& e)
{
	root = CopyTree(e.root);
}
template<typename ElemType>
BinarySortTree<ElemType>::BinarySortTree(BinTreeNode<ElemType>* r)
{
	root = new BinTreeNode<ElemType>(r->data, r->leftchild, r->rightchild, r->balance);
}
template<typename ElemType>
BinarySortTree<ElemType>& BinarySortTree<ElemType>::operator=(const BinarySortTree<ElemType>& e)
{
	Destroy(root);
	root = CopyTree(e.root);
}
template<typename ElemType>
void BinarySortTree<ElemType>::ClearTree()
{
	if (root == NULL)
		return;
	Destroy(root->leftchild);
	Destroy(root->rightchild);
	delete[]root;
	root = NULL;
}
template<typename ElemType>
BinTreeNode<ElemType>* BinarySortTree<ElemType>::Find(ElemType e)
{
	BinTreeNode<ElemType>* tmp;
	return Find(tmp, e);
}
template<typename ElemType>
BinTreeNode<ElemType>* BinarySortTree<ElemType>::Find(BinTreeNode<ElemType>*& troot, ElemType& e)
{
	troot = NULL;
	BinTreeNode<ElemType>* p = root;
	while (p != NULL && p->data != e)
	{
		troot = p;
		if (e > p->data)
			p = p->rightchild;	
		else 
			p = p->leftchild;
	}
	return p;
}
template<typename ElemType>
Status BinarySortTree<ElemType>::InsertNode(ElemType e)
{
	BinTreeNode<ElemType>* tmp;
	if (Find(tmp, e) == NULL)
	{
		if (tmp == NULL)
			root = new BinTreeNode<ElemType>(e);
		else if (e > tmp->data)
			tmp->rightchild = new BinTreeNode<ElemType>(e);
		else tmp->leftchild = new BinTreeNode<ElemType>(e);
		return SUCCESS;
	}
	return FAIL;
}
template<typename ElemType>
Status BinarySortTree<ElemType>::DelNode(ElemType e)
{
	BinTreeNode<ElemType>* p, * troot;
	if ((p = Find(troot, e)) == NULL)
		return FAIL;
	if (p == root)
		Delete(root);
	else if (troot->leftchild == p)
		Delete(troot->leftchild);
	else Delete(troot->rightchild);
	return SUCCESS;
}
template<typename ElemType>
void BinarySortTree<ElemType>::Delete(BinTreeNode<ElemType>*& troot)
{
	BinTreeNode<ElemType>* p, * cur;
	if (troot->leftchild == NULL && troot->rightchild == NULL)
	{
		delete troot;
		troot = NULL;
	}
	else if (troot->leftchild == NULL)
	{
		p = troot;
		troot = p->rightchild;
		delete p;
	}
	else if (troot->rightchild == NULL)
	{
		p = troot;
		troot = p->leftchild;
		delete p;
	}
	else {
		p = troot->leftchild;
		cur = troot;
		while (p->rightchild!=NULL)
		{
			cur = p;
			p = p->rightchild;
		}
		troot->data = p->data;
		if (cur->leftchild == p)
			Delete(cur->leftchild);
		else Delete(cur->rightchild);
	}
}
template<typename ElemType>
void BinarySortTree<ElemType>::Findx(ElemType e)
{
	Findx(root, e);
}
template<typename ElemType>
void BinarySortTree<ElemType>::Findx(BinTreeNode<ElemType>* troot, ElemType e)
{
	if (troot != NULL)
	{
		if (e <= troot->data)
		{
			Findx(troot->rightchild, e);
			cout << troot->data << endl;
			Findx(troot->leftchild, e);
		}
		else {
			Findx(troot->rightchild, e);
		}
	}
}

/*###########################################################################################*/
