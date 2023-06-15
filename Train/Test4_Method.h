#pragma once
#include <iostream>
using namespace std;
template<class TYPE> struct Node
{
	TYPE data;
	Node<TYPE>* next;
	Node();
	Node(TYPE a,Node<TYPE>* Next=NULL)
};
template <class TYPE> class LinkList
{
private:
	Node(TYPE)* head;
	int length;
public:
	LinkList();
	LinkList(TYPE v[], int n);

};