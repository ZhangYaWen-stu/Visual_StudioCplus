#pragma once
#include "Assistance.h"
#define MAX_SIZE 1000


template<class ElemType>
class SharedStack
{
protected:
	int topA;
	int topB;
	int maxsize;
	ElemType* elems;
public:
	SharedStack(int max=MAX_SIZE);
	~SharedStack();
	Status push(ElemType e,int Num);
	Status pop(ElemType& e,int Num);
	bool IsEmpty(int Num);
	void output();
	void Clear();
	bool StackFull();
};

template<class ElemType>
SharedStack<ElemType>::SharedStack(int max)
{
	maxsize = max;
	topA = -1;
	topB = maxsize;
	elems = new ElemType[maxsize];
}

template<class ElemType>
SharedStack<ElemType>::~SharedStack()
{
	delete[] elems;
}

template<class ElemType>
Status SharedStack<ElemType>::push(ElemType e, int Num)
{
	if (Num != 1 && Num != 2)
		return PARAMETER_ERROR;
	if (topA + 1 == topB)
		return OVER_FLOW;
	if (Num == 1)
		elems[++topA] = e;
	else elems[--topB] = e;
	return SUCCESS;
}

template<class ElemType>
Status SharedStack<ElemType>::pop(ElemType& e,int Num)
{
	if (Num != 1 && Num != 2)
		return PARAMETER_ERROR;
	if (Num == 1 && topA == -1 || Num == 2 && topB == maxsize)
		return UNDER_FLOW;
	if (Num == 1)
		e = elems[topA--];
	else e = elems[topB++];
	return SUCCESS;
}

template<class ElemType>
bool SharedStack<ElemType>::IsEmpty(int Num)
{
	if (Num != 1 && Num != 2)
		throw PARAMETER_ERROR;
	if (Num == 1 && topA == -1 || Num == 2 && topB == maxsize)
		return true;
	else return false;
}

template<class ElemType>
void SharedStack<ElemType>::output()
{
	cout << "TopA:[ ";
	for (int i = 0; i <= topA; i++)
		cout << elems[i] << " ";
	cout << "]" << endl;
	cout << "TopB:[ ";
	for (int i = maxsize-1; i >= topB; i--)
		cout << elems[i] << " ";
	cout << "]" << endl;
}

template<class ElemType>
void SharedStack<ElemType>::Clear()
{
	topA = -1;
	topB = maxsize;
}

template<class ElemType>
bool SharedStack<ElemType>::StackFull()
{
	if (topA + 1 == topB)
		return true;
	else return false;
}