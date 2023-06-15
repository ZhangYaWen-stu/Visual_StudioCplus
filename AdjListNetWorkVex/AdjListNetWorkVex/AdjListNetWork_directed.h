#pragma once
#include "Assist.h"
template<class WeightType>
struct AdjListNetWorkArc
{
	int adjVex;
	AdjListNetWorkArc<WeightType>* nextarc;
	WeightType weight;
	AdjListNetWorkArc(int adjVex, WeightType weight, AdjListNetWorkArc<WeightType>* nextarc = NULL);
};
template<class WeightType>
AdjListNetWorkArc<WeightType>::AdjListNetWorkArc(int adjVex, WeightType weight, AdjListNetWorkArc<WeightType>* nextarc)
{
	this->adjVex = adjVex;
	this->weight = weight;
	this->nextarc = nextarc;
}
template<class ElemType,class WeightType>
struct AdjListNetWorkVex
{
	ElemType data;
	AdjListNetWorkArc<WeightType>* firstarc;
	AdjListNetWorkVex();
	AdjListNetWorkVex(ElemType data, AdjListNetWorkArc<WeightType>* firstarc = NULL);
	~AdjListNetWorkVex();
};
template<class ElemType, class WeightType>
AdjListNetWorkVex<ElemType, WeightType>::AdjListNetWorkVex()
{
	firstarc = NULL;
}
template<class ElemType, class WeightType>
AdjListNetWorkVex<ElemType, WeightType>::AdjListNetWorkVex(ElemType data, AdjListNetWorkArc<WeightType>* firstarc)
{
	this->data = data;
	this->firstarc = firstarc;
}
template<class ElemType, class WeightType>
AdjListNetWorkVex<ElemType, WeightType>::~AdjListNetWorkVex()
{
	AdjListNetWorkArc<WeightType>* p;
	while (firstarc != NULL)
	{
		p = firstarc;
		firstarc = firstarc->nextarc;
		delete p;
	}
}


template<class ElemType, class WeightType>
class AdjListNetWork
{
private:
	int arcNum, vexNum, vexMaxNum;
	mutable Status* tag;
	AdjListNetWorkVex<ElemType, WeightType>* vexTable;
	WeightType infinity;
public:
	AdjListNetWork(ElemType es[], int vexNum, int vexMaxNum = MaxSize, WeightType infinity = (WeightType)INFINIT);
	AdjListNetWork(int vexMaxNum = MaxSize, WeightType infinity = (WeightType)INFINIT);
	~AdjListNetWork();
	bool IsEmpty();
	int FirstAdjVex(int v1);
	int NextAdjVex(int v1, int v2);
	void SetTag(int v1, Status tags);
	Status GetTag(int v1);
	bool DFSearch(int v1, int v2);
	bool BFSearch(int v1, int v2);
	void Test();
	Status TopoSort();

protected:
	bool DFS(int v1, int v2);
	Status TopoSortHelp(int v,stack<ElemType>& sort);
};
template<class ElemType, class WeightType>
AdjListNetWork<ElemType, WeightType>::AdjListNetWork(ElemType es[], int vexNum, int vexMaxNum, WeightType infinity)
{
	if (vexNum<0 || vexMaxNum <= 0 || vexNum>vexMaxNum)
		throw Error("vexNum or vexMaxNum error.");
	this->vexNum = vexNum;
	arcNum = 0;
	this->vexMaxNum = vexMaxNum;
	this->infinity = infinity;
	tag = new Status[vexMaxNum];
	vexTable = new AdjListNetWorkVex<ElemType, WeightType>[vexMaxNum];
	for (int i = 0; i < vexNum; i++)
	{
		tag[i] = UNVISITED;
		vexTable[i].data = es[i];
	}
}
template<class ElemType, class WeightType>
AdjListNetWork<ElemType, WeightType>::AdjListNetWork(int vexMaxNum, WeightType infinity)
{
	if (vexMaxNum <= 0)
		throw Error("vexMaxNum error.");
	this->vexMaxNum = vexMaxNum;
	this->infinity = infinity;
	arcNum = 0;
	vexNum = 0;
	tag = new Status[vexMaxNum];
	vexTable = new AdjListNetWorkVex<ElemType, WeightType>[vexMaxNum];
}
template<class ElemType, class WeightType>
AdjListNetWork<ElemType, WeightType>::~AdjListNetWork()
{
	delete[] tag;
	delete[] vexTable;
}
template<class ElemType, class WeightType>
bool AdjListNetWork<ElemType, WeightType>::IsEmpty()
{
	if (vexNum == 0)
		return true;
	return false;
}
template<class ElemType, class WeightType>
int AdjListNetWork<ElemType, WeightType>::FirstAdjVex(int v1)
{
	if (v1 < 0 || v1 >= vexNum)
		throw Error("Subscript error.");
	if (vexTable[v1].firstarc == NULL)
		return -1;
	return vexTable[v1].firstarc->adjVex;
}
template<class ElemType, class WeightType>
int AdjListNetWork<ElemType, WeightType>::NextAdjVex(int v1, int v2)
{
	if (v1 < 0 || v1 >= vexNum || v2 < 0 || v2 >= vexNum || v1 == v2)
		throw Error("Subscript error.");
	for (AdjListNetWorkArc<WeightType>* tmp = vexTable[v1].firstarc; tmp != NULL; tmp = tmp->nextarc)
		if (tmp->nextarc != NULL && tmp->adjVex == v2)
			return tmp->nextarc->adjVex;
	return -1;
}
template<class ElemType, class WeightType>
void AdjListNetWork<ElemType, WeightType>::SetTag(int v1, Status tags)
{
	if (v1 < 0 || v1 >= vexNum)
		throw Error("Subscript error.");
	tag[v1] = tags;
}
template<class ElemType, class WeightType>
Status AdjListNetWork<ElemType, WeightType>::GetTag(int v1)
{
	if (v1 < 0 || v1 >= vexMaxNum)
		throw Error("Subscript error.");
	return tag[v1];
}
template<class ElemType, class WeightType>
bool AdjListNetWork<ElemType, WeightType>::DFSearch(int v1, int v2)
{
	if (v1 < 0 || v1 >= vexNum || v2 < 0 || v2 >= vexNum || v1 == v2)
		throw Error("Subscript error.");
	for (int i = 0; i < vexNum; i++)
		tag[i] = UNVISITED;
	tag[v1] = VISITED;
	for (int i = FirstAdjVex(v1); i != -1; i = NextAdjVex(v1, i))
		if (tag[i] == UNVISITED && DFS(i, v2))
			return true;
	return false;
}
template<class ElemType, class WeightType>
bool AdjListNetWork<ElemType, WeightType>::DFS(int v1, int v2)
{
	if (v1 == v2)
		return true;
	tag[v1] = VISITED;
	for (int i = FirstAdjVex(v1); i != -1; i = NextAdjVex(v1, i))
		if (tag[i] == UNVISITED && DFS(i, v2))
			return true;
	return false;
}
void AdjListNetWork<int,int>::Test()
{
	AdjListNetWorkArc<int>* tmp;
	arcNum = 11;
	vexNum = 7;
	vexTable[0].data = 0;
	vexTable[0].firstarc = new AdjListNetWorkArc<int>(1, 8);
	tmp = vexTable[0].firstarc;
	tmp->nextarc = new AdjListNetWorkArc<int>(4, 5);
	tmp->nextarc->nextarc = new AdjListNetWorkArc<int>(3, 4);
	vexTable[1].data = 1;
	vexTable[1].firstarc = new AdjListNetWorkArc<int>(2, 3);
	vexTable[2].data = 2;
	vexTable[2].firstarc = new AdjListNetWorkArc<int>(6, 6);
	vexTable[3].data = 3;
	vexTable[3].firstarc = new AdjListNetWorkArc<int>(4, 3);
	vexTable[4].data = 4;
	vexTable[4].firstarc = new AdjListNetWorkArc<int>(1, 2);
	tmp = vexTable[4].firstarc;
	tmp->nextarc = new AdjListNetWorkArc<int>(2, 7);
	tmp->nextarc->nextarc = new AdjListNetWorkArc<int>(5, 2);
	vexTable[5].data = 5;
	vexTable[5].firstarc = new AdjListNetWorkArc<int>(2, 3);
	tmp = vexTable[5].firstarc;
	tmp->nextarc = new AdjListNetWorkArc<int>(6, 9);
	vexTable[6].data = 6;
}
template<class ElemType, class WeightType>
bool AdjListNetWork<ElemType, WeightType>::BFSearch(int v1, int v2)
{
	if (v1 < 0 || v1 >= vexNum || v2 < 0 || v2 >= vexNum || v1 == v2)
		throw Error("Subscript error.");
	for (int i = 0; i < vexNum; i++)
		tag[i] = UNVISITED;
	queue<int>  vex;
	vex.push(v1);
	tag[v1] = VISITED;
	while (!vex.empty())
	{
		int tmp=vex.front();
		vex.pop();
		for (int temp = FirstAdjVex(tmp); temp != -1; temp = NextAdjVex(tmp, temp))
			if (tag[temp]==UNVISITED)
			{
				tag[temp] = VISITED;
				if (temp == v2)
					return true;
				vex.push(temp);
			}
	}
	return false;
}
template<class ElemType, class WeightType>
Status AdjListNetWork<ElemType, WeightType>::TopoSort()
{
	if (vexNum == 0)
		return EMPTY;
	for (int i = 0; i < vexNum; i++)
		tag[i] = UNVISITED;
	stack<ElemType> sort;
	for (int i = 0; i < vexNum; i++)
		if (TopoSortHelp(i, sort) == LOOPS)
			return LOOPS;
	while (!sort.empty())
	{
		cout << sort.top() << endl;
		sort.pop();
	}
	return SUCCESS;
}
template<class ElemType, class WeightType>
Status AdjListNetWork<ElemType, WeightType>::TopoSortHelp(int v, stack<ElemType>& sort)
{
	if (tag[v] == UNVISITED)
	{
		tag[v] = VISITING;
		for (int i = FirstAdjVex(v); i != -1; i = NextAdjVex(v, i))
			if (tag[i] == VISITING || (tag[i] == UNVISITED && (TopoSortHelp(i, sort) == LOOPS)))
				return LOOPS;
		sort.push(vexTable[v].data);
		tag[v] = VISITED;
	}
	return SUCCESS;
}
