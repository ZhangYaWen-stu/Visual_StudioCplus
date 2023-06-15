#pragma once
#include <iostream>
#include <cstring>
using namespace std;

enum Status{EMPTY};

class String
{
private:
	char* elems;
	int length;
public:
	String(const char* temp="");
	String(String& temp);
	String(const String& temp);
	~String();
	int GetLength();
	char* GetElems();
	void Write();
	static String FindSub(String temp1, String temp2);
	String operator=(String temp);
	friend istream& operator>>(istream& in, String &temp);
	friend ostream& operator<<(ostream& out, String temp);
	static String Fsub(String& M, String& s);
	static String FsubK(String& M, String& s);
	String operator=(char* temp);
	int Pot(String &s);
	int KPot(String& s);
protected:
	void Getpot(int *&a,String s);
	void GetPot(int*& a, String s);
};

String String::operator=(char* temp)
{
	if(elems!=NULL)
	{
		delete[]elems;
		elems = new char[strlen(temp) + 1];
		strcpy(elems, temp);
		length = strlen(temp);
	}
	return *this;
}


String::String(const char* temp)
{
	elems = new char[strlen(temp)+1];
	strcpy(elems, temp);
	length = int(strlen(temp));
}

String::String(String& temp)
{
	elems = new char[temp.length+1];
	strcpy(elems, temp.elems);
	length = temp.length;
}

String::~String()
{
	delete[]elems;
}

int String::GetLength()
{
	return length;
}

char* String::GetElems()
{
	return elems;
}

String String::FindSub(String temp1, String temp2)
{
	if (temp1.length == 0 || temp2.length == 0)
		throw EMPTY;
	char* str1, *str2;
	int** a;
	int maxsize = 0;
	char* result;
	int flag = 0;
	str1 = new char[temp1.length + 1];
	str2 = new char[temp2.length + 1];
	strcpy(str1, temp1.elems);
	strcpy(str2, temp2.elems);
	a = new int* [temp1.length+1];
	for (int i = 0; i <= temp1.length; i++)
	{
		a[i] = new int[temp2.length+1];
		memset(a[i], 0, (temp2.length+1)* sizeof(int));
	}
	for (int i = 1; i <= temp1.length; i++)
	{
		for (int j = 1; j <= temp2.length; j++)
		{
			if (str1[i - 1] == str2[j - 1])
				a[i][j] = a[i - 1][j - 1] + 1;
			else a[i][j] = 0;
			if (a[i][j] > maxsize)
			{
				maxsize = a[i][j];
				flag = i ;
			}
		}
	}
	flag = flag - maxsize;
	result = new char[maxsize + 1];
	str1[flag + maxsize] = '\0';
	strcpy(result, str1 + flag);
	delete[]str1;
	delete[]str2;
	for (int i = 0; i <= temp1.length; i++)
	{
		delete[]a[i];
	}
	delete[]a;
	String Result(result);
	delete[]result;
	return Result;
}

void String::Write()
{
	cout << elems << endl;
}

String String::operator=(String temp)
{
	if (this!=&temp)
	{
		delete[]elems;
		elems = new char[temp.length + 1];
		strcpy(elems, temp.elems);
		length = temp.length;
	}
	return *this;
}
String::String(const String& temp)
{
	elems = new char[temp.length + 1];
	strcpy(elems, temp.elems);
	length = temp.length;
}

istream& operator>>(istream& in, String& temp)
{
	char str[128];
	in.getline(str, 128);
	if (temp.length>0)
		delete[]temp.elems;
	temp.elems = new char[strlen(str) + 1];
	strcpy(temp.elems, str);
	temp.length = int(strlen(str));
	return in;
}

ostream& operator<<(ostream& out, String temp)
{
	out << temp.elems << endl;
	return out;
}
String String::Fsub(String &M, String &s)
{
	if (M.Pot(s) != -1)
		return s;
	else {
		if (s.length == 1)
			return String("");
		char* str1 = new char[s.length];
		char* str2 = new char[s.length];
		strncpy(str1, s.elems, s.length - 1);
		*(str1 + s.length - 1) = '\0';
		strncpy(str2, s.elems+1, s.length - 1);
		*(str2 + s.length - 1) = '\0';
		String Str1(str1);
		delete[]str1;
		String Str2(str2);
		delete[]str2;
		String Re1 = Fsub(M, Str1);
		String Re2 = Fsub(M, Str2);
		if (Re1.length > Re2.length)
			return Re1;
		else return Re2;
	}
}
void String::Getpot(int *&a, String s)
{
	a = new int[s.length];
	int j=1, k=-1;
	char* str = new char[s.length + 1];
	strcpy(str, s.elems);
	a[0] = -1;
	while (j < s.length)
	{
		if (k == -1 || str[j-1] == str[k])
			a[j++] = ++k;
		else k = a[k];
	}
	delete[]str;
}
int String::Pot(String& s)
{
	int* f=NULL;
	GetPot(f, s);
	int i = 0, j = 0;
	char* strM = new char[strlen(elems) + 1];
	char* strs = new char[s.length + 1];
	strcpy(strM, elems);
	strcpy(strs, s.elems);
	while (i < s.length && length - j >= s.length - i)
	{
		if (i == -1 || strs[i] == strM[j])
		{
			i++; j++;
		}
		else i = f[i];
	}
	if (i != s.length)
		return -1;
	return j - i;
}

int String::KPot(String& s)
{
	int* f = NULL;
	Getpot(f, s);
	int i = 0, j = 0;
	int mlen = 0;
	char* strM = new char[strlen(elems) + 1];
	char* strs = new char[s.length + 1];
	strcpy(strM, elems);
	strcpy(strs, s.elems);
	while (i < s.length && length - j >= s.length - i)
	{
		if (i == -1 || strs[i] == strM[j])
		{
			i++; j++;
			if (i > mlen)
				mlen = i;
		}
		else i = f[i];
	}
	return mlen;
}

void String::GetPot(int*& a, String s)
{
	a = new int[s.length];
	char* str = new char[s.length + 1];
	strcpy(str, s.elems);
	int* f;
	int j = 0;
	int k;
	Getpot(f, s);
	a[0] = -1;
	for (j = 0; j < s.length; j++)
	{
		k = f[j];
		while (k!=-1&&str[j]==str[k])
			k = f[k];
		a[j] = k;
	}
}
String String::FsubK(String& M, String& s)
{
	int mlen = 0, flag = -1, j;
	char* str1 = new char[s.length + 1];
	strcpy(str1, s.elems);
	String Str1(str1);
	for (int i = 0; i < s.length; i++)
	{
		j = M.KPot(Str1);
		if (j > mlen)
		{
			mlen = j;
			flag = i;
		}
		delete[]str1;
		str1 = new char[Str1.length];
		strcpy(str1, Str1.elems + 1);
		Str1=str1;
	}
	if (flag == -1)
		return String("");
	char* str2 = new char[mlen + 1];
	strncpy(str2, s.elems + flag, mlen);
	str2[mlen] = '\0';
	String Str2(str2);
	delete[]str2;
	delete[]str1;
	return Str2;
}