#pragma once
#include<iostream>
#define MAXSIZE 1000
#include <string>
#include <stdlib.h>
using namespace std;
enum Status { SUCCESS, FAIL, OVER_FLOW, UNDER_FLOW, LH, EH, RH };
template<typename ElemType>
class Stack
{
private:
	ElemType* elems;
	int top;
	int maxsize;
public:
	Stack(int maxsize = MAXSIZE);
	~Stack();
	Status Pop(ElemType& e);
	Status Push(const ElemType& e);
	bool IsEmpty();
	bool IsFull();
};




template<typename ElemType>
Stack<ElemType>::Stack(int maxsize)
{
	this->maxsize = maxsize;
	top = -1;
	elems = new ElemType[maxsize];
}
template<typename ElemType>
Stack<ElemType>::~Stack()
{
	delete[] elems;
}
template<typename ElemType>
Status Stack<ElemType>::Pop(ElemType& e)
{
	if (IsEmpty())
		return UNDER_FLOW;
	e = elems[top--];
	return SUCCESS;
}
template<typename ElemType>
Status Stack<ElemType>::Push(const ElemType& e)
{
	if (IsFull())
		return OVER_FLOW;
	elems[++top] = e;
	return SUCCESS;
}
template<typename ElemType>
bool Stack<ElemType>::IsEmpty()
{
	if (top == -1)
		return true;
	else return false;
}
template<typename ElemType>
bool Stack<ElemType>::IsFull()
{
	if (top == maxsize - 1)
		return true;
	else return false;
}