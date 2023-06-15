#pragma once
#include "Assist.h"
template<class WeightType>
struct AdjListNetWorkArc
{
	int adjVex;
	WeightType weight;
	AdjListNetWorkArc<WeightType>* nextarc;
	AdjListNetWorkArc(int adjVex, WeightType weight, AdjListNetWorkArc<WeightType>* nextarc = NULL);
};
template<class WeightType>
AdjListNetWorkArc<WeightType>::AdjListNetWorkArc(int adjVex, WeightType weight, AdjListNetWorkArc<WeightType>* nextarc)
{
	this->adjVex = adjVex;
	this->weight = weight;
	this->nextarc = nextarc;
}



template<class ElemType, class WeightType>
struct AdjListNetWorkVex
{
	ElemType data;
	AdjListNetWorkArc<WeightType>* firstarc;
	AdjListNetWorkVex();
	AdjListNetWorkVex(ElemType data, AdjListNetWorkArc<WeightType>* firstarc=NULL);
	~AdjListNetWorkVex();
};
template<class ElemType, class WeightType>
AdjListNetWorkVex<ElemType,WeightType>::AdjListNetWorkVex()
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
	WeightType infinity;
	int vexNum, vexMaxNum, arcNum;
	mutable Status* tag;
	AdjListNetWorkVex<ElemType, WeightType>* vexTable;
public:
	AdjListNetWork(ElemType es[], int vertexNum, int vertexMaxNum = MaxSize, WeightType infinit = (WeightType)INFINIT);
	AdjListNetWork(int vertexMaxNum = MaxSize, WeightType infinit = (WeightType)INFINIT);
	~AdjListNetWork();
	void Clear();
	bool IsEmpty();
	int GetOrder(ElemType e)const;
	Status GetElem(int p, ElemType& e)const;
	Status SetElem(int p, ElemType e);
	WeightType GetInfinity()const;
	int GetVexNum()const;
	int GetArcNum()const;
	int FirstAdjVex(int v1)const;
	int NextAdjVex(int v1, int v2)const;
	Status InsertVex(ElemType e);
	Status InsertArc(int v1, int v2, WeightType weight);
	Status DeleteVex(ElemType e);
	Status DeleteArc(int v1, int v2);
	WeightType GetWeight(int v1, int v2);
	Status SetWeight(int v1, int v2,WeightType t);
	Status GetTag(int v);
	void SetTag(int v, Status s);
	AdjListNetWork(const AdjListNetWork<ElemType, WeightType>& copy);
	AdjListNetWork<ElemType, WeightType>& operator=(const AdjListNetWork<ElemType, WeightType>& copy);
	//void Display();
	bool IsExist(int v1, int v2)const;
	bool SpecificRoad(int v1, int v2,int length);
	bool IsTree()const;
	void Test();
protected:
	bool SpecificRoadHelp(int v1, int v2, int length, int length_cur);
	int Count(int v1);
};

template<class ElemType, class WeightType>
AdjListNetWork<ElemType, WeightType>::AdjListNetWork(ElemType es[], int vertexNum, int vertexMaxNum, WeightType infinit)
{
	if (vertexNum < 0 || vertexMaxNum <= 0 || vertexNum>vertexMaxNum)
		throw Error("VexNum or VexMaxNum error.");
	vexNum = vertexNum;
	vexMaxNum = vertexMaxNum;
	vexTable = new AdjListNetWorkVex<ElemType, WeightType>[vertexMaxNum];
	tag = new Status[vertexMaxNum];
	for (int i = 0; i < vertexNum; i++)
	{
		vexTable[i].data = es[i];
		tag[i] = UNVISITED;
	}
	infinity = infinit;
	arcNum = 0;
}
template<class ElemType, class WeightType>
AdjListNetWork<ElemType, WeightType>::AdjListNetWork(int vertexMaxNum, WeightType infinit)
{
	if (vertexMaxNum <= 0)
		throw Error("VexMaxNum error.");
	vexNum = 0;
	vexMaxNum = vertexMaxNum;
	vexTable = new AdjListNetWorkVex<ElemType, WeightType>[vertexMaxNum];
	tag = new Status[vertexMaxNum];
	infinity = infinit;
	arcNum = 0;
}
template<class ElemType, class WeightType>
AdjListNetWork<ElemType, WeightType>::~AdjListNetWork()
{
	delete[] vexTable;
	delete[] tag;
}
template<class ElemType, class WeightType>
void AdjListNetWork<ElemType, WeightType>::Clear()
{
	AdjListNetWorkArc<WeightType>* tmp;
	for (int i = 0; i < vexNum; i++)
	{
		while (vexTable[i].firstarc != NULL)
		{
			tmp = vexTable[i].firstarc;
			vexTable[i].firstarc = vexTable[i].firstarc->nextarc;
			delete tmp;
		}
	}
	vexNum = 0;
	arcNum = 0;
}
template<class ElemType, class WeightType>
bool AdjListNetWork<ElemType, WeightType>::IsEmpty()
{
	if (vexNum == 0)
		return true;
	else return false;
}
template<class ElemType, class WeightType>
int AdjListNetWork<ElemType, WeightType>::GetOrder(ElemType e)const
{
	for (int i = 0; i < vexNum; i++)
		if (vexTable[i].data == e)
			return i;
	return -1;
}
template<class ElemType, class WeightType>
Status AdjListNetWork<ElemType, WeightType>::GetElem(int p, ElemType& e)const
{
	if (p < 0 || p >= vexNum)
		return FAIL;
	e = vexTable[p].data;
	return SUCCESS;
}
template<class ElemType, class WeightType>
Status AdjListNetWork<ElemType, WeightType>::SetElem(int p, ElemType e)
{
	if (p < 0 || p >= vexNum)
		return FAIL;
	vexTable[p].data = e;
	return SUCCESS;
}
template<class ElemType, class WeightType>
WeightType AdjListNetWork<ElemType, WeightType>::GetInfinity()const
{
	return infinity;
}
template<class ElemType, class WeightType>
int AdjListNetWork<ElemType, WeightType>::GetVexNum()const
{
	return vexNum;
}
template<class ElemType, class WeightType>
int AdjListNetWork<ElemType, WeightType>::GetArcNum()const
{
	return arcNum;
}
template<class ElemType, class WeightType>
int AdjListNetWork<ElemType, WeightType>::FirstAdjVex(int v1)const
{
	if (v1 < 0 || v1 >= vexNum)
		throw Error("Subscript Error.");
	if (vexTable[v1].firstarc != NULL)
		return vexTable[v1].firstarc->adjVex;
	return -1;
}
template<class ElemType, class WeightType>
int AdjListNetWork<ElemType, WeightType>::NextAdjVex(int v1, int v2)const
{
	if (v1 < 0 || v1 >= vexNum || v2 < 0 || v2 >= vexNum || v1 == v2)
		throw Error("Subscript Error.");
	AdjListNetWorkArc<WeightType>* tmp=vexTable[v1].firstarc;
	while (tmp != NULL && tmp->adjVex != v2)
		tmp = tmp->nextarc;
	if (tmp == NULL || tmp->nextarc == NULL)
		return -1;
	else return tmp->nextarc->adjVex;
}
template<class ElemType, class WeightType>
Status AdjListNetWork<ElemType, WeightType>::InsertVex(ElemType e)
{
	if (vexNum >= vexMaxNum)
		return FAIL;
	vexTable[vexNum].data = e;
	tag[vexNum++] = UNVISITED;
	return SUCCESS;
}
template<class ElemType, class WeightType>
bool AdjListNetWork<ElemType, WeightType>::IsExist(int v1,int v2)const
{
	if (v1 < 0 || v1 >= vexNum || v2 < 0 || v2 >= vexNum || v1 == v2)
		throw Error("Subscript Error.");
	for (AdjListNetWorkArc<WeightType>* tmp = vexTable[v1].firstarc; tmp != NULL; tmp = tmp->nextarc)
		if (tmp->adjVex == v2)
			return true;
	return false;
}
template<class ElemType, class WeightType>
Status AdjListNetWork<ElemType, WeightType>::InsertArc(int v1, int v2, WeightType weight)
{
	if (v1 < 0 || v1 >= vexNum || v2 < 0 || v2 >= vexNum || v1 == v2)
		return FAIL;
	if (IsExist(v1, v2))
		return FAIL;
	vexTable[v1].firstarc = new AdjListNetWorkArc<WeightType>(v2, weight, vexTable[v1].firstarc);
	vexTable[v2].firstarc = new AdjListNetWorkArc<WeightType>(v1, weight, vexTable[v2].firstarc);
	arcNum++;
	return SUCCESS;
}
template<class ElemType, class WeightType>
Status AdjListNetWork<ElemType, WeightType>::DeleteVex(ElemType e)
{
	int Del,temp;
	for (Del = 0; Del < vexNum && vexTable[Del].data != e; Del++);
	if (Del == vexNum)
		return FAIL;
	AdjListNetWorkArc<WeightType>* tmp, * cur;
	while (vexTable[Del].firstarc != NULL)
	{
		temp = vexTable[Del].firstarc->adjVex;
		if (vexTable[temp].firstarc->adjVex == Del)
		{
			cur = vexTable[temp].firstarc;
			vexTable[temp].firstarc = cur->nextarc;
			delete cur;
		}
		else {
			for (tmp = vexTable[temp].firstarc; tmp->nextarc != NULL && tmp->nextarc->adjVex != Del; tmp = tmp->nextarc);
			cur = tmp->nextarc;
			tmp->nextarc = cur->nextarc;
			delete cur;
		}
		tmp = vexTable[Del].firstarc;
		vexTable[Del].firstarc = vexTable[Del].firstarc->nextarc;
		arcNum--;
		delete tmp;
	}
	vexNum--;
	if (Del < vexNum)
	{
		vexTable[Del].firstarc = vexTable[vexNum].firstarc;
		vexTable[vexNum] = NULL;
		for (cur = vexTable[Del].firstarc; cur != NULL; cur = cur->nextarc)
		{
			for (tmp = vexTable[cur->adjVex].firstarc; tmp->adjVex != vexNum; tmp = tmp->nextarc);
			tmp->adjVex = Del;
		}
	}
	return SUCCESS;
}
template<class ElemType, class WeightType>
Status AdjListNetWork<ElemType, WeightType>::DeleteArc(int v1, int v2)
{
	AdjListNetWorkArc<WeightType>* cur, * tmp;
	if (v1 < 0 || v1 >= vexNum || v2 < 0 || v2 >= vexNum || v1 == v2)
		return FAIL;
	if (!IsExist(v1, v2))
		return FAIL;
	if (vexTable[v1].firstarc->adjVex == v2)
	{
		cur = vexTable[v1].firstarc;
		vexTable[v1].firstarc = cur->nextarc;
		delete cur;
	}
	else {
		for (cur = vexTable[v1].firstarc; cur->nextarc != NULL && cur->nextarc->adjVex != v2; cur = cur->nextarc);
		tmp = cur->nextarc;
		cur->nextarc = tmp->nextarc;
		delete tmp;
	}
	if (vexTable[v2].firstarc->adjVex == v1)
	{
		cur = vexTable[v2].firstarc;
		vexTable[v2].firstarc = cur->nextarc;
		delete cur;
	}
	else {
		for (cur = vexTable[v2].firstarc; cur->nextarc != NULL && cur->nextarc->adjVex != v1; cur = cur->nextarc);
		tmp = cur->nextarc;
		cur->nextarc = tmp->nextarc;
		delete tmp;
	}
	arcNum--;
	return SUCCESS;
}
template<class ElemType, class WeightType>
WeightType AdjListNetWork<ElemType, WeightType>::GetWeight(int v1, int v2)
{
	if (v1 < 0 || v1 >= vexNum || v2 < 0 || v2 >= vexNum || v1 == v2)
		return FAIL;
	for (AdjListNetWorkArc<WeightType>* cur = vexTable[v1].firstarc; cur != NULL; cur = cur->nextarc)
		if (cur->adjVex == v2)
			return cur->weight;
	return infinity;
}
template<class ElemType, class WeightType>
Status AdjListNetWork<ElemType, WeightType>::SetWeight(int v1, int v2, WeightType t)
{
	AdjListNetWorkArc<WeightType>* cur;
	if (v1 < 0 || v1 >= vexNum || v2 < 0 || v2 >= vexNum || v1 == v2)
		return FAIL;
	if (!IsExist(v1, v2))
		return FAIL;
	for (cur = vexTable[v1].firstarc; cur->adjVex != v2; cur = cur->nextarc);
	cur->weight = t;
	for (cur = vexTable[v2].firstarc; cur->adjVex != v1; cur = cur->nextarc);
	cur->weight = t;
	return SUCCESS;
}
template<class ElemType, class WeightType>
Status AdjListNetWork<ElemType, WeightType>::GetTag(int v)
{
	if (v < 0 || v >= vexNum )
		return FAIL;
	return tag[v];
}
template<class ElemType, class WeightType>
void AdjListNetWork<ElemType, WeightType>::SetTag(int v,Status s)
{
	if (v < 0 || v >= vexNum)
		throw Error("Subscript Error.");
	tag[v] = s;
}
template<class ElemType, class WeightType>
AdjListNetWork<ElemType, WeightType>::AdjListNetWork(const AdjListNetWork<ElemType, WeightType>& copy)
{
	vexNum = copy.vexNum;
	vexMaxNum = copy.vexMaxNum;
	arcNum = copy.arcNum;
	infinity = copy.infinity;
	vexTable = new AdjListNetWorkVex<ElemType, WeightType>[vexMaxNum];
	tag = new Status[vexMaxNum];
	AdjListNetWorkArc<WeightType>* tmp, * cur;
	for (int i = 0; i < vexNum; i++)
	{
		vexTable[i].data = copy.vexTable[i].data;
		tag[i] = copy.tag[i];
		cur = copy.vexTable[i].firstarc;
		if (cur != NULL)
		{
			vexTable[i].firstarc = new AdjListNetWorkArc<WeightType>(cur->adjVex, cur->weight);
			cur = cur->nextarc;
		}
		tmp = vexTable[i].firstarc;
		while (cur != NULL)
		{
			tmp->nextarc = new AdjListNetWorkArc<WeightType>(cur->adjVex, cur->nextarc);
			tmp = tmp->nextarc;
			cur = cur->nextarc;
		}
	}
}
template<class ElemType, class WeightType>
AdjListNetWork<ElemType, WeightType>& AdjListNetWork<ElemType, WeightType>::operator=(const AdjListNetWork<ElemType, WeightType>& copy)
{
	if (vexTable != NULL)
	{
		delete[] vexTable;
		delete[] tag;
	}
	vexNum = copy.vexNum;
	vexMaxNum = copy.vexMaxNum;
	arcNum = copy.arcNum;
	infinity = copy.infinity;
	vexTable = new AdjListNetWorkVex<ElemType, WeightType>[vexMaxNum];
	tag = new Status[vexMaxNum];
	AdjListNetWorkArc<WeightType>* tmp, * cur;
	for (int i = 0; i < vexNum; i++)
	{
		vexTable[i].data = copy.vexTable[i].data;
		tag[i] = copy.tag[i];
		cur = copy.vexTable[i].firstarc;
		if (cur != NULL)
		{
			vexTable[i].firstarc = new AdjListNetWorkArc<WeightType>(cur->adjVex, cur->weight);
			cur = cur->nextarc;
		}
		tmp = vexTable[i].firstarc;
		while (cur != NULL)
		{
			tmp->nextarc = new AdjListNetWorkArc<WeightType>(cur->adjVex, cur->nextarc);
			tmp = tmp->nextarc;
			cur = cur->nextarc;
		}
	}
	return this;
}
template<class ElemType, class WeightType>
bool AdjListNetWork<ElemType, WeightType>::SpecificRoad(int v1, int v2,int length)
{
	if (v1 < 0 || v1 >= vexNum || v2 < 0 || v2 >= vexNum || v1 == v2)
		throw Error("Subscript error.");
	if (length == 0)
		throw Error("Length Error.");
	for (int i = 0; i < vexNum; i++)
		tag[i] = UNVISITED;
	tag[v1] = VISITED;
	for (int i = FirstAdjVex(v1); i != -1; i = NextAdjVex(v1, i))
	{
		if (SpecificRoadHelp(i, v2, length, GetWeight(v1, i)))
			return true;
	}
	return false;
}
template<class ElemType, class WeightType>
bool AdjListNetWork<ElemType, WeightType>::SpecificRoadHelp(int v1, int v2, int length, int length_cur)
{
	if (v1 == v2 && length_cur == length)
		return true;
	if (v1 == v2)
		return false;
	tag[v1] = VISITED;
	for (int i = FirstAdjVex(v1); i != -1; i = NextAdjVex(v1, i))
		if (tag[i] == UNVISITED&& SpecificRoadHelp(i, v2, length, length_cur + GetWeight(v1, i)))
				return true;
	tag[v1] = UNVISITED;
	return false;
}
void AdjListNetWork<char, int>::Test()
{
	InsertVex('A');
	InsertVex('B');
	InsertVex('C');
	InsertVex('D');
	InsertVex('E');
	InsertVex('F');
	InsertArc(0, 1, 12);
	InsertArc(0, 2, 3);
	InsertArc(0, 4, 9);
	InsertArc(0, 5, 10);
	InsertArc(1, 4, 6);
	InsertArc(1, 3, 2);
	InsertArc(3, 4, 4);
	InsertArc(3, 5, 7);
	InsertArc(3, 2, 2);
	InsertArc(5, 2, 6);
	InsertArc(5, 4, 4);
}
template<class ElemType, class WeightType>
int AdjListNetWork<ElemType, WeightType>::Count(int v1)
{
	if (v1 < 0 || v1 >= vexNum)
		throw Error("Subscript error.");
	for (int i = 0; i < vexNum; i++)
		tag[i] = UNVISITED;
	queue<int>  vex;
	int count = 0;
	vex.push(v1);
	tag[v1] = VISITED;
	while (!vex.empty())
	{
		int tmp = vex.front();
		vex.pop();
		count++;
		for (int temp = FirstAdjVex(tmp); temp != -1; temp = NextAdjVex(tmp, temp))
			if (tag[temp] == UNVISITED)
			{
				tag[temp] = VISITED;
				vex.push(temp);
			}
	}
	return count;
}
template<class ElemType, class WeightType>
bool AdjListNetWork<ElemType, WeightType>::IsTree()const
{
	if (arcNum == vexNum - 1 && Count(0) == vexNum);
		return true;
	return false;
}
