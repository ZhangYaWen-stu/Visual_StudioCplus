#pragma once
#include<iostream>
#include<cstring>
#include<conio.h>
using namespace std;
class String
{
	friend istream& operator>>(istream& in, String& temp);
	friend ostream& operator<<(ostream& out,const String& temp);
private:
	int size;
	char* str;
public:
	String(const char* temp="");
	String(const String& temp);
	~String();
	String& operator=(const String& temp);
	String& operator=(const char* temp);
	char& operator[](int i);
	String operator+(const String& str2);
	String operator+(const char* str1);
	bool operator==(const String& temp);
	bool operator==(const char* temp);
	bool operator!=(const String& temp);
	bool operator!=(char* temp);
	bool operator>(const String& temp);
	bool operator>(const char* temp);
	bool operator<(const String& temp);
	bool operator<(const char* temp);
	bool operator>=(const String& temp);
	bool operator>=(const char* temp);
	bool operator<=(const String& temp);
	bool operator<=(const char* temp);
	void operator+=(const String& temp);
	void operator+=(const char* temp);
	bool empty();
	void swap(String& temp);
	char* c_str() const;
	int Size();
	void insert(const char* str1,int pos=0);
	void insert(String& str1, int pos = 0);
	void Reverse();
	int Compare(String& temp);
	int Compare(const char *temp);
	int Find(const char* temp);
	int Find(String& temp);
	void Append(const char* temp);
	void clear();
	void erase(int pos,int end=0);
	void Condense(bool flag = false);
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