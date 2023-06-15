#include"string.h"
String::String(const char* temp)
{
	str = new char[strlen(temp) + 1];
	strcpy(str, temp);
	size = int(strlen(temp));
}

String::String(const String& temp)
{
	str = new char[strlen(temp.str) + 1];
	strcpy(str, temp.str);
	size = temp.size;
}

String::~String()
{
	if (str != NULL)
		delete[]str;
	str = NULL;
}

String& String::operator=(const String& temp)
{
	delete[]str;
	str = new char[strlen(temp.str) + 1];
	strcpy(str, temp.str);
	size = temp.size;
	return *this;
}

String& String::operator=(const char* temp)
{
	delete[]str;
	str = new char[strlen(temp) + 1];
	strcpy(str, temp);
	size = int(strlen(temp));
	return *this;
}

char& String::operator[](int i)
{
	if (i<0 || i>=strlen(str))
		throw execption(i);
	else {
		char* head = str;
		int l=0;
		for (; l < i; l++)
			head++;
		return *head;
	}
}

String String::operator+(const String& str2)
{
	String temp;
	delete[]temp.str;
	temp.str = new char[strlen(str) + strlen(str2.str) + 1];
	strcpy(temp.str, str);
	strcat(temp.str, str2.str);
	temp.size = int(strlen(temp.str));
	return temp;
}
String String::operator+(const char* str1)
{
	String temp;
	delete[]temp.str;
	temp.str = new char[strlen(str) + strlen(str1) + 1];
	strcpy(temp.str, str);
	strcat(temp.str, str1);
	temp.size = int(strlen(temp.str));
	return temp;
}

bool String::operator==(const String& temp)
{
	if (strcmp(str, temp.str) == 0)
		return true;
	else return false;
}

bool String::operator==(const char* temp)
{
	if (strcmp(str, temp) == 0)
		return true;
	else return false;
}

bool String::operator!=(const String& temp)
{
	if (strcmp(str, temp.str) != 0)
		return true;
	else return false;
}

bool String::operator!=(char* temp)
{
	if (strcmp(str, temp) != 0)
		return true;
	else return false;
}

bool String::operator>(const String& temp)
{
	if (strcmp(str, temp.str) > 0)
		return true;
	else return false;
}

bool String::operator>(const char* temp)
{
	if (strcmp(str, temp) > 0)
		return true;
	else return false;
}
bool String::operator<(const String& temp)
{
	if (strcmp(str, temp.str) < 0)
		return true;
	else return false;
}
bool String::operator<(const char* temp)
{
	if (strcmp(str, temp) < 0)
		return true;
	else return false;
}
bool String::operator>=(const String& temp)
{
	if (strcmp(str, temp.str) >= 0)
		return true;
	else return false;
}
bool String::operator>=(const char* temp)
{
	if (strcmp(str, temp) >= 0)
		return true;
	else return false;
}
bool String::operator<=(const String& temp)
{
	if (strcmp(str, temp.str) <= 0)
		return true;
	else return false;
}
bool String::operator<=(const char* temp)
{
	if (strcmp(str, temp) <= 0)
		return true;
	else return false;
}

void String::operator+=(const String& temp)
{
	*this = *this + temp;
	size += temp.size;
}

void String::operator+=(const char* temp)
{
	*this = *this + temp;
	size += int(strlen(temp));
}

istream& operator>>(istream& in, String& temp)
{
	char str1[128];
	in.getline(str1, 128);
	delete[]temp.str;
	temp.str = new char[strlen(str1) + 1];
	strcpy(temp.str, str1);
	temp.size = int(strlen(temp.str));
	return in;
}

ostream& operator<<(ostream& out, const String& temp)
{
	out << temp.str;
	return out;
}

bool String::empty()
{
	if (size == 0)
		return true;
	else return false;
}
void String::swap(String& temp)
{
	char* str1;
	int k;
	str1 = str;
	k = size;
	size = temp.size;
	temp.size = k;
	str = new char[strlen(temp.str) + 1];
	strcpy(str, temp.str);
	delete[]temp.str;
	temp.str = new char[strlen(str1) + 1];
	strcpy(temp.str, str1);
	delete[]str1;	
}

char* String::c_str() const
{
	return str;
}

int String::Size()
{
	return size;
}
void String::insert(const char* str1,int pos)
{
	int i=0;
	char* head = str;
	char* temp1, *temp2;
	if (pos<0 || pos>strlen(head))
		throw execption("---输入下标超出界限---");
	temp1 = new char[pos+1];
	temp2 = new char[size - pos+1];
	str = new char[strlen(str1) + strlen(head) + 1];
	for (i = 0; i < pos; i++)
	{
		*(temp1 + i) = *(head + i);
	}
	*(temp1 + i) = '\0';
	for (i = pos; i < size; i++)
	{
		*(temp2 + i-pos) = *(head + i);
	}
	*(temp2 + i-pos) = '\0';
	strcpy(str, temp1);
	strcat(str, str1);
	strcat(str, temp2);
	size = int(strlen(str));
	delete[]temp1;
	delete[]temp2;
	delete[]head;
}

void String::insert(String& temp, int pos)
{
	int i = 0;
	char* head = str;
	char* temp1, * temp2;
	if (pos<0 || pos>strlen(head))
		throw execption("---输入下标超出界限---");
	temp1 = new char[pos + 1];
	temp2 = new char[size - pos + 1];
	str = new char[strlen(temp.str) + strlen(head) + 1];
	for (i = 0; i < pos; i++)
	{
		*(temp1 + i) = *(head + i);
	}
	*(temp1 + i) = '\0';
	for (i = pos; i < size; i++)
	{
		*(temp2 + i - pos) = *(head + i);
	}
	*(temp2 + i - pos) = '\0';
	strcpy(str, temp1);
	strcat(str, temp.str);
	strcat(str, temp2);
	size = int(strlen(str));
	delete[]temp1;
	delete[]temp2;
	delete[]head;
}

void String::Reverse()
{
	char* head, * end, temp;
	if (size == 0)
		throw execption("---String为空，无法反转---");
	head = str; end = str + size - 1;
	for (; head < end; head++, end--)
	{
		temp = *head;
		*head = *end;
		*end = temp;
	}
}
int String::Compare(String& temp)
{
	if (*this > temp)
		return 1;
	else if (*this < temp)
		return -1;
	else if (*this == temp)
		return 0;
	throw execption("---进行比较数据异常---");
}

int String::Compare(const char* temp)
{
	if (*this > temp)
		return 1;
	else if (*this < temp)
		return -1;
	else if (*this == temp)
		return 0;
	throw execption("---进行比较数据异常---");
}

int String::Find(const char* temp)
{
	char* head = str;
	int i=0, l=0;
	if (int(strlen(temp))==0)
		throw execption("---进行查找字符串异常---");
	for (i = 0; i < size; i++)
	{
		for (l = 0; l<int(strlen(temp))&&(*(head+i+l)==*(temp+l)); l++);
		if (l == int(strlen(temp)))
			return i;
	}
	throw execption("---进行查找字符串不存在---");
}
int String::Find(String& temp)
{
	int i,l;
	char* head = str;
	if (*temp.str == '\0')
		throw execption("---进行查找字符串异常---");
	for (i = 0; i < size; i++)
	{
		for (l = 0; l<int(strlen(temp.str)) && (*(head + i + l) == *(temp.str + l)); l++);
		if (l == int(strlen(temp.str)))
			return i;
	}
	throw execption("---进行查找字符串不存在---");
}
void String::Append(const char* temp)
{
	char* head = str;
	str = new char[strlen(temp) + size + 1];
	strcpy(str, head);
	strcat(str, temp);
	size = int(strlen(str));
	delete[]head;
}

void String::erase(int pos, int end)
{
	if (end >= size||pos<0||end<=pos)
		throw execption("---输入下标超出界限---");
	char* temp1, * temp2,*head=str;
	int i = 0;
	if (end == 0)
		end = size;
	temp1 = new char[pos + 1];
	temp2 = new char[size - end+1];
	for (i = 0; i < pos; i++)
	{
		*(temp1 + i) = *(head + i);
	}
	*(temp1 + i) = '\0';
	for (i = 0; i < end-pos; i++)
	{
		*(temp2 + i) = *(head + i+end);
	}
	*(temp2 + i) = '\0';
	delete[]head;
	size = size - (end - pos);
	str = new char[size + 1];
	strcpy(str, temp1);
	strcat(str, temp2);
}

void String::Condense(bool flag)
{
	char* head = str;
	char* temp;
	int i, end=size-1,l=0;
	for (i=0; *(head+i) == ' '; i++);
	temp = new char[size + 1];
	for (; *(head + end) == ' '; end--);
	if (flag)
	{
		for (; i <= end; i++)
			if (*(head + i) != ' ')
			{
				*(temp + l) = *(head + i); 
				l++;
			}
		*(temp + l) = '\0';
	}
	else
	{
		for (; i <= end; i++)
		{
			*(temp + l) = *(head + i);
			l++;
		}
		*(temp + l) = '\0';
	}
	str = new char[strlen(temp)+1];
	strcpy(str, temp);
	size = int(strlen(str));
	delete[]head;
	delete[]temp;
}

void String::clear()
{
	delete[]str;
	str = new char;
	*str = '\0';
}
