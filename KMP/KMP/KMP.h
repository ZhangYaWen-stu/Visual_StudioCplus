#pragma once
#include<iostream>
#include <cstring>
using namespace std;
class String
{
private:
	char* elems;
	int length;
public:
	String(const char* temp="");
	String(String &temp);
	~String();
	int KMP(String pat,int pos=0);
	int GetLength();
	char* GetElems()const;
};
String::String(const char* temp)
{
	elems = new char[strlen(temp)+1];
	strcpy(elems, temp);
	length = int(strlen(elems));
}

String::String(String& temp)
{
	elems = new char[temp.length + 1];
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

char* String::GetElems()const
{
	return elems;
}
void GetFailure(String pat,int *f)
{
	f[0] = -1;
	if (pat.GetLength() <= 1)
		return;
	f[1] = 0;
	char* temp;
	temp = new char[pat.GetLength() + 1];
	strcpy(temp, pat.GetElems());
	for (int i = 2; i < pat.GetLength(); i++)
	{
		int k = i-1;
		while (true)
		{
			if (k==-1||temp[i-1]==temp[f[k]])
			{
				f[i]=k++;
				break;
			}
			else
			{
				k = f[k];
			}
		}
	}
	delete[]temp;
}

void GetFailure_NEW(String pat, int* f_new)
{
	int* f = new int[pat.GetLength()];
	GetFailure(pat, f);
	f_new[0] = -1;
	for (int i = 1; i < pat.GetLength(); i++)
	{
		int k = i;
		while (true)
		{
			if (k == -1 || pat.GetElems()[i] != pat.GetElems()[f[k]])
			{
				f_new[i] = k; break;
			}
			else k = f[k];
		}
	}
	delete[]f;
}

int String::KMP(String pat, int pos)
{
	int* f = new int[pat.GetLength()];
	GetFailure_NEW(pat, f);
	int i = pos, j = 0;
	while (GetLength() - i >= pat.GetLength() - j&& j != pat.GetLength())
	{
		if (j==-1||pat.elems[j] == elems[i])
		{
			i++;
			j++;
		}
		else {
			j = f[j];
		}
	}
	delete[]f;
	if (j == pat.GetLength())
		return i - j;
	else
		return -1;
}
