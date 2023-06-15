#include<iostream>
#include<cstring>
#include <conio.h>
using namespace std;
#ifndef MYSTRING_H
#define MYSTRING_H

class MyString
{
    friend ostream& operator<<(ostream& out, MyString& ob);//��Ԫ��������<<����Ԫ����
    friend istream& operator>>(istream& in, MyString& ob);//��Ԫ��������>>����Ԫ����
private:
    char* str;
    int size;//�ַ�������
public:
    MyString();//�޲ι���
    MyString(const char* str);//�вι��캯��
    MyString(const MyString& ob);//��������
    ~MyString();//��������
    MyString& operator =(const MyString& ob);//��ֵ���� ��Ա��������= ʵ���ֵ ob1=ob2;
    int Size();//�����ַ�������
    char& operator[](int i);//��Ա��������[]
    MyString& operator+(const MyString& ob);//��Ա��������+ ʵ��ob1+ob2
    MyString& operator+(const char* str);//��Ա��������+ ʵ��ob1+"abc"
    bool operator==(const MyString& ob);//��Ա��������== �ж�ob1==ob2
    bool operator==(const char* str);//��Ա��������== �ж�ob1=="abc"
    bool operator!=(const MyString& ob);//��Ա��������!= �ж�ob1!=ob2
    bool operator!=(const char* str);//��Ա��������!= �ж�ob1!="abc"
};
ostream& operator<<(ostream& out, MyString& ob);//��Ԫ��������<<
istream& operator>>(istream& in, MyString& ob);//��Ԫ��������>>
#endif // MYSTRING_H
