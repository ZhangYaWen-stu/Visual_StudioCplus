#pragma once
#include <iostream>
using namespace std;
enum Status { FAIL, SUCCESS };
template<typename ElemType>
struct Node
{
	ElemType elems;
	Node<ElemType>* nextnode;
	Node(ElemType e, Node<ElemType>* next = NULL);
};
template<typename ElemType>
Node<ElemType>::Node(ElemType e, Node<ElemType>* next)
{
	elems = e;
	nextnode = next;
}

template<typename ElemType>
class HashTable
{
private:
	Node<ElemType>** elems;
	int length;
protected:
	int HashFunction(ElemType e);
	Node<ElemType>* Find(Node<ElemType>*& pnode, ElemType e);
public:
	HashTable(ElemType* elem = NULL, int n = 0, int len = 0);
	~HashTable();
	void Clear();
	Node<ElemType>* Find(ElemType e);
	Status InsertNode(ElemType e);
	Status DeleteNode(ElemType e);
	void CreateHashTable(ElemType* elem, int n, int len);
};
template<typename ElemType>
HashTable<ElemType>::HashTable(ElemType* elem, int n, int len)
{
	length = 0;
	elems = NULL;
	CreateHashTable(elem, n, len);
}
template<typename ElemType>
HashTable<ElemType>::~HashTable()
{
	Clear();
}
template<typename ElemType>
void HashTable<ElemType>::Clear()
{
	for (int i = 0; i < length; i++)
	{
		Node<ElemType>* cur, * del;
		cur = elems[i];
		while (cur != NULL)
		{
			del = cur;
			cur = cur->nextnode;
			delete del;
		}
	}
	if (length != 0)
		delete[] elems;
	elems = NULL;
	length = 0;
}
template<typename ElemType>
Node<ElemType>* HashTable<ElemType>::Find(Node<ElemType>*& pnode, ElemType e)
{
	if (length == 0)
		throw FAIL;
	Node<ElemType>* cur;
	pnode = NULL;
	int pos = HashFunction(e);
	cur = elems[pos];
	while (cur != NULL && cur->elems != e)
	{
		pnode = cur;
		cur = cur->nextnode;
	}	
	return cur;
}
template<typename ElemType>
Node<ElemType>* HashTable<ElemType>::Find(ElemType e)
{
	Node<ElemType>* tmp;
	return Find(tmp, e);
}
template<typename ElemType>
Status HashTable<ElemType>::InsertNode(ElemType e)
{
	if (Find(e) == NULL)
	{
		int pos = HashFunction(e);
		Node<ElemType>* ins = new Node<ElemType>(e, elems[pos]);
		elems[pos] = ins;
		return SUCCESS;
	}
	return FAIL;
}
template<typename ElemType>
Status HashTable<ElemType>::DeleteNode(ElemType e)
{
	Node<ElemType>* pnode, * del;
	if ((del = Find(pnode, e)) != NULL)
	{
		int pos = HashFunction(e);
		if (pnode == NULL)
		{
			elems[pos] = elems[pos]->nextnode;
			delete del;
		}
		else {
			pnode->nextnode = del->nextnode;
			delete del;
		}
		return SUCCESS;
	}
	return FAIL;
}
template<>
int HashTable<int>::HashFunction(int e)
{
	return (e % length >= 0) ? (e % length) : (e % length + length);
}
template<typename ElemType>
void HashTable<ElemType>::CreateHashTable(ElemType* elem, int n, int len)
{
	Clear();
	if (n < 0 || len < 0 || (n != 0 && len == 0))
		throw FAIL;
	length = len;
	if (n == 0)
		return;
	elems = new Node<ElemType>*[length];
	for (int i = 0; i < length; i++)
		elems[i] = NULL;
	for (int i = 0; i < n; i++)
		InsertNode(elem[i]);
}
