#pragma once
#include <iostream>
using namespace std;
#include<fstream>
#include<string>
//class Train
//{
//private:
//	int a;
//public:
//	void play() const;
//	Train(int s = 0) :a(s) {}
//	void t(Train& l);
//	virtual void o()
//	{
//		cout << "TRAIN" << endl;
//	}
//	/*virtual void v() = 0;*/
//};

//class B:public Train
//{
//public:
//	void o()
//	{
//		cout << "B" << endl;
//	}
//};
//
//class C :public B
//{
//public:
//	void o()
//	{
//		cout << "C" << endl;
//	}
//};
//
//class derived :public Train
//{
//public:
//	derived(int a=3) :Train(a){}
//};

//class base1
//{
//public:
//	base1()
//	{
//		cout << "base1" << endl;
//	}
//};
//class base2
//{
//public:
//	base2()
//	{
//		cout << "base2" << endl;
//	}
//};
//class a :public base1, virtual public base2
//{
//public:
//	a()
//	{
//		cout << "a" << endl;
//	}
//};
//
//class b :public base1, virtual public base2
//{
//public:
//	b()
//	{
//		cout << "b" << endl;
//	}
//};
//class d
//{
//public:
//	d()
//	{
//		cout << "d" << endl;
//	}
//};
//
//class c :public a, virtual public b
//{
//private:
//	d l;
//public:
//	c()
//	{
//		cout << "c" << endl;
//	}
//};

//class temp
//{
//public:
//	temp()
//	{
//		cout << "Constructing" << endl;
//	}
//	temp(temp& temp1)
//	{
//		cout << "copy" << endl;
//	}
//	~temp()
//	{
//		cout << "Disconstructing" << endl;
//	}
//	temp app()
//	{
//		temp temp1;
//		return temp1;
//	}
//};


//class Train
//{
//private:
//	int a, b;
//public:
//	Train(int a1 = 0, int b1 = 0)
//	{
//		a = a1;
//		b = b1;
//	}
//	void show()
//	{
//		cout << a << " " << b << endl;
//	}
//};

//class a
//{
//public:
//	void show() const
//	{
//		int i = 0;
//		cout << "wqeq" << endl;
//	}
//};
//class base1
//{
//private:
//	int i;
//public:
//	base1(int a)
//	{
//		i = a;
//	}
//};
//class base2:virtual public base1
//{
//private:
//	int o;
//public:
//	base2(int a,int b):base1(a),o(b){}
//};
//class base3 :virtual public base1
//{
//private:
//	int p;
//public:
//	base3(int a, int b) :base1(a), p(b) {}
//};
//class base4 :public base2, public base3
//{
//public:
//	base4(int a, int b, int c) :base2(a, b), base3(a, c),base1(a) {}
//
//};

//class Train
//{
//private:
//	char* data;
//public:
//	Train(const char* temp=NULL)
//	{
//		if (temp == NULL)
//		{
//			data = NULL;
//			return;
//		}
//		int n = int(strlen(temp) + 1);
//		data = new char[n];
//		strcpy(data, temp);
//	}
//	~Train()
//	{
//		if(data!=NULL)
//			delete[]data;
//	}
//	Train(Train& temp)
//	{
//		if (data)
//			delete[]data;
//		data = NULL;
//		if (temp.data == NULL)
//			return;
//		data = new char[strlen(temp.data) + 1];
//		strcpy(data, temp.data);
//	}
//	Train& operator=(Train& temp)
//	{
//		if (data)
//			delete[]data;
//		data = NULL;
//		if (temp.data == NULL)
//			return *this;
//		data = new char[strlen(temp.data) + 1];
//		strcpy(data, temp.data);
//		return *this;
//	}
//	void test(Train& temp)
//	{
//		*this = temp;
//	}
//	void show()
//	{
//		cout << data << endl;
//	}
//};