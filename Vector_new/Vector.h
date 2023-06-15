#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<cstring>
#include<conio.h>
#include<stdlib.h>
using namespace std;
template <typename T>
class Vector
{
public:
	template<typename T>
	friend ostream& operator<<(ostream& out,Vector<T> v);
	Vector(int dimension = 0);
	Vector(T* temp,int d);
	Vector(Vector<T>& temp);
	~Vector();
	void push_back(const T& x);
	void pop_back();
	void clear();
	T& at(int pos);
	T& front();
	T& back();
	T* begin();
	T* end();
	bool empty()const;
	int GetDim();
	void swap(Vector<T>& temp);
	void erase(int head, int end);
	void assign(int n, T x);
	void reverse();
	Vector<T> resize(int dimension, int d=0,T* temp=NULL);
	void insert(int pos, T temp);


	T operator[](int index);
	Vector<T> operator=(const Vector<T> &temp);
	bool operator!=(Vector<T> temp);
	bool operator==(Vector<T> temp);
	Vector<T> operator+(const Vector<T> &temp);
	Vector<T> operator-(const Vector<T> &temp);
	T operator*(Vector<T> temp);
	
private:
	int Dim;
	T* Data;
	int type();
};

class execption
{
public: int i;
	  char* msg;
public:
	execption(int temp)
	{
		i = temp;
		msg = new char[1];
		*msg = '\0';
	}
	execption(const char* temp)
	{
		msg = new char[strlen(temp) + 1];
		strcpy(msg, temp);
		i = 0;
	}
};