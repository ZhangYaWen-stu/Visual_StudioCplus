#pragma once
#include "Stack_QueueB.h"
template<typename ElemType>
struct BinTreeNode
{
	ElemType data;
	Status balance;
	int lsize;
	BinTreeNode<ElemType>* leftchild;
	BinTreeNode<ElemType>* rightchild;
	BinTreeNode();
	BinTreeNode(const ElemType& e, BinTreeNode<ElemType>* leftchild = NULL, BinTreeNode<ElemType>* rightchild = NULL, Status balance = EH, int lsize = 1);
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
	BinTreeNode<ElemType>* Find(BinTreeNode<ElemType>*& proot, BinTreeNode<ElemType>*& troot, BinTreeNode<ElemType>*& iroot, ElemType& e);
	void Delete(BinTreeNode<ElemType>*& troot);
	void Rotate_RR(BinTreeNode<ElemType>*& troot);
	void Rotate_RL(BinTreeNode<ElemType>*& troot);
	void Rotate_LL(BinTreeNode<ElemType>*& troot);
	void Rotate_LR(BinTreeNode<ElemType>*& troot);
	void AdjustBal_Ins(BinTreeNode<ElemType>* troot, ElemType e);
	void AdjustBal_Del(BinTreeNode<ElemType>* par, ElemType e);
	int AdjustLsize(BinTreeNode<ElemType>* troot);
	BinTreeNode<ElemType>* Findk(BinTreeNode<ElemType>* troot, ElemType e);
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
	int HeightBal()const;
	BinTreeNode<ElemType>* Findk(ElemType e);
	/*#############################################################################*/
};



template<typename ElemType>
BinTreeNode<ElemType>::BinTreeNode()
{
	leftchild = rightchild = NULL;
}
template<typename ElemType>
BinTreeNode<ElemType>::BinTreeNode(const ElemType& e, BinTreeNode<ElemType>* leftchild, BinTreeNode<ElemType>* rightchild, Status balance, int lsize)
{
	data = e;
	this->lsize = lsize;
	this->balance = balance;
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
		e = new BinTreeNode<ElemType>(t->data, NULL, NULL, t->balance, t->lsize);
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
	return Find(tmp, tmp, tmp, e);
}
template<typename ElemType>
BinTreeNode<ElemType>* BinarySortTree<ElemType>::Find(BinTreeNode<ElemType>*& broot, BinTreeNode<ElemType>*& troot, BinTreeNode<ElemType>*& iroot, ElemType& e)
{
	broot = iroot = troot = NULL;
	BinTreeNode<ElemType>* p = root;
	while (p != NULL && p->data != e)
	{
		if (p->balance != EH)
		{
			troot = iroot;
			broot = p;
		}
		iroot = p;
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
	BinTreeNode<ElemType>* broot, * troot, * iroot;
	if (Find(broot, troot, iroot, e) == NULL)
	{
		if (iroot == NULL)
			root = new BinTreeNode<ElemType>(e);
		else if (broot == NULL)
		{
			AdjustBal_Ins(root, e);
			if (e > root->data)
				root->balance = RH;
			else root->balance = LH;
			if (iroot->balance == RH)
				iroot->rightchild = new BinTreeNode<ElemType>(e);
			else iroot->leftchild = new BinTreeNode<ElemType>(e);
		}
		else
		{
			AdjustBal_Ins(broot, e);
			if (iroot->balance == RH)
				iroot->rightchild = new BinTreeNode<ElemType>(e);
			else iroot->rightchild = new BinTreeNode<ElemType>(e);
			if (((broot->balance == RH) && (e < broot->data)) || ((broot->balance == LH) && (e > broot->data)))
				broot->balance = EH;
			else if (broot->balance == RH)
			{
				if (troot == NULL)
				{
					if (broot->rightchild->balance != LH)
						Rotate_RR(root);
					else Rotate_RL(root);
				}
				else {
					if (troot->leftchild == broot)
					{
						if (broot->rightchild->balance != LH)
							Rotate_RR(troot->leftchild);
						else Rotate_RL(troot->leftchild);
					}
					else {
						if (broot->rightchild->balance != LH)
							Rotate_RR(troot->leftchild);
						else Rotate_RL(troot->leftchild);
					}
				}
			}
			else {
				if (troot == NULL)
				{
					if (broot->rightchild->balance != RH)
						Rotate_LL(root);
					else Rotate_LR(root);
				}
				else {
					if (troot->leftchild == broot)
					{
						if (broot->rightchild->balance != LH)
							Rotate_LL(troot->leftchild);
						else Rotate_LR(troot->leftchild);
					}
					else {
						if (broot->rightchild->balance != LH)
							Rotate_LL(troot->leftchild);
						else Rotate_LR(troot->leftchild);
					}
				}
			}
		}
		return SUCCESS;
	}
	AdjustLsize(root);
	return FAIL;
}
template<typename ElemType>
Status BinarySortTree<ElemType>::DelNode(ElemType e)
{
	BinTreeNode<ElemType>* p, * troot, * broot, * iroot;
	if ((p = Find(broot, troot, iroot, e)) == NULL)
		return FAIL;
	if (p == root)
		Delete(root);
	if (iroot->leftchild == p)
		Delete(iroot->leftchild);
	else Delete(iroot->rightchild);
	AdjustLsize(root);
	return SUCCESS;
}
template<typename ElemType>
void BinarySortTree<ElemType>::Delete(BinTreeNode<ElemType>*& troot)
{
	BinTreeNode<ElemType>* p, * cur, * par;
	ElemType elem;
	if (troot->leftchild == NULL && troot->rightchild == NULL)
	{
		par = Parent(troot);
		elem = troot->data;
		delete troot;
		troot = NULL;
		AdjustBal_Del(par, elem);
	}
	else if (troot->leftchild == NULL)
	{
		par = Parent(troot);
		elem = troot->data;
		p = troot;
		troot = p->rightchild;
		delete p;
		AdjustBal_Del(par, elem);
	}
	else if (troot->rightchild == NULL)
	{
		par = Parent(troot);
		elem = troot->data;
		p = troot;
		troot = p->leftchild;
		delete p;
		AdjustBal_Del(par, elem);
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
void BinarySortTree<ElemType>::Rotate_RR(BinTreeNode<ElemType>*& troot)
{
	BinTreeNode<ElemType>* bal2 = troot, * bal1 = troot->rightchild;
	troot = bal1;
	bal2->rightchild = bal1->leftchild;
	bal1->leftchild = bal2;
	if (bal1->balance == EH)
		bal1->balance = LH;
	else bal1->balance = bal2->balance = EH;
}
template<typename ElemType>
void BinarySortTree<ElemType>::Rotate_RL(BinTreeNode<ElemType>*& troot)
{
	BinTreeNode<ElemType>* bal2 = troot, * bal1 = troot->rightchild, * bal0 = troot->rightchild->leftchild;
	troot = bal0;
	bal2->rightchild = bal0->leftchild;
	bal1->leftchild = bal0->rightchild;
	bal0->leftchild = bal2;
	bal0->rightchild = bal1;
	if (bal0->balance == EH)
		bal1->balance = bal2->balance = EH;
	else if (bal0->balance == RH)
	{
		bal0->balance = EH;
		bal1->balance = EH;
		bal2->balance = LH;
	}
	else {
		bal0->balance = EH;
		bal1->balance = RH;
		bal2->balance = EH;
	}
}
template<typename ElemType>
void BinarySortTree<ElemType>::Rotate_LL(BinTreeNode<ElemType>*& troot)
{
	BinTreeNode<ElemType>* bal2 = troot, * bal1 = troot->leftchild;
	troot = bal1;
	bal2->leftchild = bal1->rightchild;
	bal1->rightchild = bal2;
	if (bal1->balance == EH)
		bal1->balance = RH;
	else bal1->balance = bal2->balance = EH;
}
template<typename ElemType>
void BinarySortTree<ElemType>::Rotate_LR(BinTreeNode<ElemType>*& troot)
{
	BinTreeNode<ElemType>* bal2 = troot, * bal1 = troot->leftchild, * bal0 = troot->leftchild->rightchild;
	troot = bal0;
	bal1->rightchild = bal0->leftchild;
	bal2->leftchild = bal0->rightchild;
	bal0->leftchild = bal1;
	bal0->rightchild = bal2;
	if (bal0->balance == EH)
		bal2->balance = bal1->balance = EH;
	else if (bal0->balance = LH)
	{
		bal0->balance = EH;
		bal1->balance = EH;
		bal2->balance = RH;
	}
	else {
		bal0->balance = EH;
		bal1->balance = LH;
		bal2->balance = EH;
	}
}
template<typename ElemType>
void BinarySortTree<ElemType>::AdjustBal_Ins(BinTreeNode<ElemType>* troot, ElemType e)
{
	BinTreeNode<ElemType>* cur = (e > troot->data) ? troot->rightchild : troot->leftchild;
	while (cur != NULL)
	{
		if (e > cur->data)
		{
			cur->balance = RH;
			cur = cur->rightchild;
		}
		else 
		{
			cur->balance = LH;
			cur = cur->leftchild;
		}
	}
}
template<typename ElemType>
void BinarySortTree<ElemType>::AdjustBal_Del(BinTreeNode<ElemType>* par, ElemType e)
{
	BinTreeNode<ElemType>* parent = Parent(par);
	ElemType elem = par->data;
	if (par != NULL)
	{
		if (((par->balance == RH) && (e > par->data)) || ((par->balance == LH) && (e < par->balance)))
		{
			par->balance = EH;
			AdjustBal_Del(parent, elem);
		}
		else if (par->balance == RH)
		{
			if (parent == NULL)
			{
				if (par->rightchild->balance != LH)
					Rotate_RR(root);
				else Rotate_RL(root);
			}
			else {
				if (par->data > parent->data)
				{
					if (par->rightchild->balance != LH)
						Rotate_RR(parent->rightchild);
					else Rotate_RL(parent->rightchild);
				}
			}
			AdjustBal_Del(parent, elem);
		}
		else if (par->balance == LH)
		{
			if (parent == NULL)
			{
				if (par->leftchild->balance != RH)
					Rotate_LL(root);
				else Rotate_LR(root);
			}
			else {
				if (par->data < parent->data)
				{
					if (par->leftchild->balance != RH)
						Rotate_LL(parent->leftchild);
					else Rotate_LR(parent->leftchild);
				}
			}
			AdjustBal_Del(parent, elem);
		}
	}
}
template<typename ElemType>
int BinarySortTree<ElemType>::HeightBal()const
{
	BinTreeNode<ElemType>* cur = root;
	int height = 0;
	while (cur != NULL)
	{
		height++;
		if (cur->balance != LH)
			cur = cur->rightchild;
		else cur = cur->leftchild;
	}
	return height;
}
template<typename ElemType>
int BinarySortTree<ElemType>::AdjustLsize(BinTreeNode<ElemType>* troot)
{
	if (troot == NULL)
		return 0;
	else {
		troot->lsize = AdjustLsize(troot->leftchild) + 1;
		AdjustLsize(troot->rightchild);
	}
}
template<typename ElemType>
BinTreeNode<ElemType>* BinarySortTree<ElemType>::Findk(ElemType e)
{
	if (e <= 0)
		return NULL;
	return Findk(root, e);
}
template<typename ElemType>
BinTreeNode<ElemType>* BinarySortTree<ElemType>::Findk(BinTreeNode<ElemType>* troot, ElemType e)
{
	if (troot == NULL)
		return NULL;
	else if (e == troot->lsize)
		return troot;
	else if (e > troot->lsize)
		return Findk(troot->rightchild, e - troot->lsize);
	else return Findk(troot->leftchild, e);
}
/*###########################################################################################*/
