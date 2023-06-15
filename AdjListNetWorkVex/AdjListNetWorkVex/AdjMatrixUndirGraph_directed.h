#pragma once
#include"Assist.h"
template<class ElemType, class WeightType>
class AdjMatrixUndirGraph
{
private:
	WeightType infinite;
	int vexNum, arcNum, vexMaxNum;
	ElemType* vertexes;
	WeightType** arcs;
	mutable Status* tag;
public:
	AdjMatrixUndirGraph(int vexMaxNum = MaxSize, WeightType infinite = (WeightType)INFINIT);
	~AdjMatrixUndirGraph();
	int FirstAdjVex(int v)const;
	int NextAdjVex(int v1, int v2)const;
	int SpecificRoadNum(int v1, int v2, int length);
	Status InsertVex(ElemType e);
	Status InsertArc(int v1, int v2, WeightType weight);
	int GetWeight(int v1, int v2);
	void Test();
	void LongestPath();
	void LongestPathTopo();
protected:
	int SpecificRoadNumHelp(int v1, int v2,int length, int length_cur);
};
template<class ElemType, class WeightType>
AdjMatrixUndirGraph<ElemType, WeightType>::AdjMatrixUndirGraph(int vexMaxNum, WeightType infinite)
{
	if (vexMaxNum <= 0)
		throw Error("VexMaxNum Error.");
	this->vexMaxNum = vexMaxNum;
	this->infinite = infinite;
	vertexes = new ElemType[vexMaxNum];
	vexNum = 0;
	arcNum = 0;
	tag = new Status[vexMaxNum];
	arcs = new WeightType* [vexMaxNum];
	for (int i = 0; i < vexMaxNum; i++)
	{
		arcs[i] = new WeightType[vexMaxNum];
		for (int j = 0; j < vexMaxNum; j++)
			if (i == j)
				arcs[i][j] = 0;
			else arcs[i][j] = infinite;
	}
}
template<class ElemType, class WeightType>
AdjMatrixUndirGraph<ElemType, WeightType>::~AdjMatrixUndirGraph()
{
	delete[]tag;
	for (int i = 0; i < vexMaxNum; i++)
		delete[] arcs[i];
	delete[]vertexes;
}
template<class ElemType, class WeightType>
Status AdjMatrixUndirGraph<ElemType, WeightType>::InsertVex(ElemType e)
{
	if (vexNum == vexMaxNum)
		return FAIL;
	vertexes[vexNum++] = e;
	return SUCCESS;
}
template<class ElemType, class WeightType>
Status AdjMatrixUndirGraph<ElemType, WeightType>::InsertArc(int v1, int v2, WeightType weight)
{
	if (v1 < 0 || v1 >= vexNum || v2 < 0 || v2 >= vexNum || v1 == v2|| arcs[v1][v2] != infinite)
		return FAIL;
	arcs[v1][v2] = weight;
	arcNum++;
	return SUCCESS;
}
template<class ElemType, class WeightType>
int  AdjMatrixUndirGraph<ElemType, WeightType>::FirstAdjVex(int v)const
{
	if (v < 0 || v >= vexNum)
		throw Error("Subscript Error.");
	for (int i = 0; i < vexNum; i++)
		if (arcs[v][i] != infinite && arcs[v][i] != 0)
			return i;
	return -1;
}
template<class ElemType, class WeightType>
int  AdjMatrixUndirGraph<ElemType, WeightType>::NextAdjVex(int v1, int v2)const
{
	if (v1 < 0 || v1 >= vexNum || v2 < 0 || v2 >= vexNum || v1 == v2)
		throw Error("Subscript Error.");
	for (int i = v2 + 1; i < vexNum; i++)
		if (arcs[v1][i] != infinite && arcs[v1][i] != 0)
			return i;
	return -1;
}
void AdjMatrixUndirGraph<int, int>::Test()
{
	for (int i = 0; i < 7; i++)
	{
		vertexes[i] = i;
		tag[i] = UNVISITED;
	}
	vexNum = 7;
	InsertArc(0, 1, 8);
	InsertArc(0, 3, 4);
	InsertArc(0, 4, 5);
	InsertArc(1, 2, 3);
	InsertArc(2, 6, 6);
	InsertArc(3, 4, 1);
	InsertArc(4, 1, 2);
	InsertArc(4, 2, 7);
	InsertArc(4, 5, 2);
	InsertArc(5, 2, 3);
	InsertArc(5, 6, 9);
}
template<class ElemType, class WeightType>
int AdjMatrixUndirGraph<ElemType, WeightType>::SpecificRoadNum(int v1, int v2, int length)
{
	if (v1 < 0 || v1 >= vexNum || v2 < 0 || v2 >= vexNum || v1 == v2)
		throw Error("Subscript error.");
	if (length == 0)
		throw Error("Length Error.");
	for (int i = 0; i < vexNum; i++)
		tag[i] = UNVISITED;
	tag[v1] = VISITED;
	int count = 0;
	for (int i = FirstAdjVex(v1); i != -1; i = NextAdjVex(v1, i))
		count += SpecificRoadNumHelp(i, v2, length, GetWeight(v1, i));
	return count;
}
template<class ElemType, class WeightType>
int AdjMatrixUndirGraph<ElemType, WeightType>::SpecificRoadNumHelp(int v1, int v2, int length, int length_cur)
{
	if (v1 == v2 && length_cur == length)
		return 1;
	if (v1 == v2)
		return 0;
	int count = 0;
	tag[v1] = VISITED;
	for (int i = FirstAdjVex(v1); i != -1; i = NextAdjVex(v1, i))
		if (tag[i] == UNVISITED)
			count += SpecificRoadNumHelp(i, v2, length, length_cur + GetWeight(v1, i));	
	tag[v1] = UNVISITED;
	return count;
}
template<class ElemType, class WeightType>
int AdjMatrixUndirGraph<ElemType, WeightType>::GetWeight(int v1, int v2)
{
	if (v1 < 0 || v1 >= vexNum || v2 < 0 || v2 >= vexNum || v1 == v2)
		throw Error("Subscript error.");
	return arcs[v1][v2];
}
template<class ElemType, class WeightType>
void AdjMatrixUndirGraph<ElemType, WeightType>::LongestPath()
{
	if (vexNum == 0 || arcNum == 0)
		throw Error("VexNum Or ArcNum Error.");
	WeightType** longest = new WeightType * [vexNum];
	int** path = new int* [vexNum];
	int longest_a = 0, longest_b = 0;
	WeightType longest_tmp = -infinite;
	for (int i = 0; i < vexNum; i++)
	{
		longest[i] = new WeightType[vexNum];
		path[i] = new int[vexNum];
		for (int j = 0; j < vexNum; j++)
		{
			longest[i][j] = arcs[i][j];
			if (longest[i][j] != infinite && longest[i][j] > longest_tmp)
			{
				longest_tmp = longest[i][j];
				longest_a = i;
				longest_b = j;
			}	
			path[i][j] = (i != j) ? i : -1;
		}
	}
	for (int k = 0; k < vexNum; k++)
		for (int i = 0; i < vexNum; i++)
			for (int j = 0; j < vexNum; j++)
				if (longest[i][k] != infinite && longest[k][j] != infinite && (longest[i][j] == infinite || longest[i][j] < longest[i][k] + longest[k][j]))
				{
					longest[i][j] = longest[i][k] + longest[k][j];
					path[i][j] = path[k][j];
					if (longest[i][j] > longest_tmp)
					{
						longest_tmp = longest[i][j];
						longest_a = i;
						longest_b = j;
					}
				}
	stack<ElemType> l;
	l.push(longest_b);
	longest_b = path[longest_a][longest_b];
	while (longest_b != longest_a)
	{
		l.push(longest_b);
		longest_b = path[longest_a][longest_b];
	}
	l.push(longest_a);
	cout << "图中的最长路径为:" << endl;
	while (!l.empty())
	{
		cout << l.top() << endl;
		l.pop();
	}
	cout << "长度为:" << longest_tmp << endl;
}
template<class ElemType, class WeightType>
void AdjMatrixUndirGraph<ElemType, WeightType>::LongestPathTopo()
{
	int *ve = new int[vexNum];
	int *vl = new int[vexNum];

}
