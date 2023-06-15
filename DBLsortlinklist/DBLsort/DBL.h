#pragma once
#include<iostream>
using namespace std;
enum Status { FAIL, SUCCESS };

template<typename ElemType>
struct Node
{
	ElemType data;
	Node<ElemType>* next;
	Node<ElemType>* prior;
	Node();
	Node(ElemType e, Node<ElemType>* n = NULL, Node<ElemType>* p = NULL);
};
template<typename ElemType>
Node<ElemType>::Node()
{
	next = prior = NULL;
}
template<typename ElemType>
Node<ElemType>::Node(ElemType e, Node<ElemType>* n, Node<ElemType>* p)
{
	data = e;
	next = n;
	prior = p;
}

template<typename ElemType>
class LinkList
{
private:
	Node<ElemType>* head;
public:
	LinkList();
	~LinkList();
	void Append(ElemType e);
	void QuickSort();
	template<typename ElemType>
	friend ostream& operator<<(ostream& out, const LinkList<ElemType>& e);
protected:
	Node<ElemType>* Delete(Node<ElemType>* e);
	void QuickSort(Node<ElemType>* start, Node<ElemType>* end);
	void Append(Node<ElemType>* thead, Node<ElemType>* e);
};
template<typename ElemType>
LinkList<ElemType>::LinkList()
{
	head = new Node<ElemType>();
}
template<typename ElemType>
LinkList<ElemType>::~LinkList()
{
	Node<ElemType>* cur;
	while (head != NULL)
	{
		cur = head;
		head = head->next;
		delete cur;
	}
}
template<typename ElemType>
void LinkList<ElemType>::Append(ElemType e)
{
	head->next = new Node<ElemType>(e, head->next, head);
	if (head->next->next != NULL)
		head->next->next->prior = head->next;
}
template<typename ElemType>
Node<ElemType>* LinkList<ElemType>::Delete(Node<ElemType>* e)
{
	if (e != NULL)
	{
		if (e->next != NULL)
			e->next->prior = e->prior;
		e->prior->next = e->next;
		return e;
	}
	return NULL;
}
template<typename ElemType>
ostream& operator<<(ostream& out, const LinkList<ElemType>& e)
{
	for (Node<ElemType>* i = e.head->next; i != NULL; i = i->next)
		out << i->data << " ";
	return out;
}
template<typename ElemType>
void LinkList<ElemType>::Append(Node<ElemType>* thead, Node<ElemType>* e)
{
	e->next = thead->next;
	if (thead->next != NULL)
		thead->next->prior = e;
	e->prior = thead;
	thead->next = e;
}
template<typename ElemType>
void LinkList<ElemType>::QuickSort()
{
	QuickSort(head, NULL);
}
template<typename ElemType>
void LinkList<ElemType>::QuickSort(Node<ElemType>* start, Node<ElemType>* end)
{
	if (start->next == end)
		return;
	Node<ElemType>* datum = start->next, * pcur = start->next;
	for (Node<ElemType>* i = datum->next; i != end; i = i->next)
	{
		if (i->data < datum->data)
		{
			Node<ElemType>* tmp;
			tmp = Delete(i);
			Append(start, tmp);
			i = pcur;
		}
		pcur = i;
	}
	for (Node<ElemType>* i = head->next; i != NULL; i = i->next)
		cout << i->data <<" ";
	cout << endl;
	QuickSort(start, datum);
	QuickSort(datum, end);
}

