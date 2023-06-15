#pragma once
#include<iostream>
#include<string>
using namespace std;
template <typename T>
class Vector
{
public:
	template<typename T>
	friend ostream& operator<<(ostream& out, Vector<T> v);
	Vector(int dimension = 0);
	~Vector();
	int Dim;
	T* Data;
	int type();
	int Dimension(T* temp);
};
template<typename T>
int Vector<T>::type()
{
	string str(typeid(string).name());
	string c(typeid(char).name());
	string flag(typeid(T).name());
	if (flag == c)
		return 1;
	else if (flag == str)
		return 2;
	else return 0;
}
template<typename T>
int Vector<T>::Dimension(T* temp)
{
	return sizeof(temp) / sizeof(T);
}
template<typename T>
Vector<T>::~Vector()
{
	delete[]Data;
	Data = NULL;
}
template<typename T>
Vector<T>::Vector(int dimension)
{
	Dim = dimension;
	if (!dimension)
		Data = NULL;
	else if(type()!=2)
	{
		Data = new T[dimension];
		for (int i = 0; i < dimension; i++)
			*(Data + i) = 0;
	}
	else
	{
		Data = new T[dimension];
	}
}

template<typename T>
ostream& operator<<(ostream& out, Vector<T> v)
{
	int i;
	out << "[";
	for (i = 0; i < v.Dim - 1; i++)
		out <<*(v.Data+i) << ",";
	if (i == v.Dim - 1)
		out << *(v.Data + i);
	out << "]";
	return out;
}