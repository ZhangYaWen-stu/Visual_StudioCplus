#pragma once
#include<iostream>
using namespace std;
template<typename ElemType>
struct LinkNode
{
	ElemType data;
	LinkNode<ElemType>* nextsibling;
	LinkNode<ElemType>* firstchild;
	LinkNode(ElemType tdata = 0, LinkNode<ElemType>* tnextsibling = NULL, LinkNode<ElemType>* tfirstchild = NULL);
};

template<typename ElemType>
LinkNode<ElemType>::LinkNode(ElemType tdata, LinkNode<ElemType>* tnextsibling, LinkNode<ElemType>* tfirstchild)
{
	data = tdata;
	nextsibling = tnextsibling;
	firstchild = tfirstchild;
}

template<typename ElemType>
class LinkTree
{
private:
	LinkNode<ElemType>* root;
public:
	LinkTree(LinkNode<ElemType>* troot = NULL);
	~LinkTree();
	void CreateTree();
	void Test();
	void Clear();
	int GetHeight();
	int GetDegree();
	int GetLeafNode();
protected:
	void CreateTree(LinkNode<ElemType>*& troot, ElemType data);
	void Clear(LinkNode<ElemType> *&troot);
	int GetHeight(LinkNode<ElemType>* troot);
	int GetDegree(LinkNode<ElemType>* troot);
	int GetLeafNode(LinkNode<ElemType>* troot);
};
template<typename ElemType>
LinkTree<ElemType>::LinkTree(LinkNode<ElemType>* troot)
{
	root = troot;
}
template<typename ElemType>
int LinkTree<ElemType>::GetHeight()
{
	return GetHeight(root);
}
template<typename ElemType>
void LinkTree<ElemType>::Clear(LinkNode<ElemType> *&troot)
{
	if (troot != NULL)
	{
		Clear(troot->firstchild);
		Clear(troot->nextsibling);
		delete troot;
		troot = NULL;
	}
}
template<typename ElemType>
void LinkTree<ElemType>::Clear()
{
	Clear(root);
}
template<typename ElemType>
LinkTree<ElemType>::~LinkTree()
{
	Clear();
}
template<typename ElemType>
int LinkTree<ElemType>::GetHeight(LinkNode<ElemType>* troot)
{
	if (troot == NULL)
		return 0;
	int Heightchild = 0, Heightsibling = 0;
	Heightchild = GetHeight(troot->firstchild)+1;
	Heightsibling = GetHeight(troot->nextsibling);
	if (Heightchild > Heightsibling)
		return Heightchild;
	else return Heightsibling;
}
template<typename ElemType>
int LinkTree<ElemType>::GetDegree()
{
	return GetDegree(root);
}
template<typename ElemType>
int LinkTree<ElemType>::GetDegree(LinkNode<ElemType>* troot)
{
	if (troot==NULL)
		return 0;
	int TempDegree = 0, DegreeChild = 0, DegreeSibling = 0;
	LinkNode<ElemType>* tmp = troot->firstchild;
	while (tmp != NULL)
	{
		TempDegree++;
		tmp = tmp->nextsibling;
	}
	DegreeChild = GetDegree(troot->firstchild);
	DegreeSibling = GetDegree(troot->nextsibling);
	if (TempDegree < DegreeChild)
		TempDegree = DegreeChild;
	if (TempDegree < DegreeSibling)
		TempDegree = DegreeSibling;
	return TempDegree;
}
template<typename ElemType>
int LinkTree<ElemType>::GetLeafNode()
{
	return GetLeafNode(root);
}
template<typename ElemType>
int LinkTree<ElemType>::GetLeafNode(LinkNode<ElemType>* troot)
{
	if (troot == NULL)
		return 0;
	if (troot->firstchild == NULL)
		return GetLeafNode(troot->nextsibling) + 1;
	else return GetLeafNode(troot->firstchild) + GetLeafNode(troot->nextsibling);
}
void LinkTree<char>::Test()
{
	if (root != NULL)
		Clear();
	root = new LinkNode<char>('A');
	LinkNode<char>* cur = root;
	cur->firstchild = new LinkNode<char>('B');
	cur = cur->firstchild;
	cur->nextsibling = new LinkNode<char>('C');
	cur = cur->nextsibling;
	cur->nextsibling = new LinkNode<char>('D');
	cur->firstchild = new LinkNode<char>('E');
	cur = cur->firstchild;
	cur->nextsibling = new LinkNode<char>('F');
	cur = cur->nextsibling;
	cur->firstchild = new LinkNode<char>('G');
}
void LinkTree<char>::CreateTree(LinkNode<char>*& troot, char data)
{
	if (data != '#')
	{
		troot = new LinkNode<char>(data);
		cout << "请输入孩子结点的值（#为空）：";
		cin >> data;
		CreateTree(troot->firstchild, data);
		cout << "请输入兄弟结点的值（#为空）：";
		cin >> data;
		CreateTree(troot->nextsibling, data);
	}
}
void LinkTree<char>::CreateTree()
{
	if (root != NULL)
		Clear();
	char data;
	cout << "请输入根结点的值（#为空）：";
	cin >> data;
	if (data != '#')
		root = new LinkNode<char>(data);
	cout << "请输入孩子结点的值（#为空）：";
	cin >> data;
	if (data != '#')
		CreateTree(root->firstchild, data);
}