#include<iostream>
#include<cstring>
#include <conio.h>
using namespace std;
#ifndef MYSTRING_H
#define MYSTRING_H

class MyString
{
    friend ostream& operator<<(ostream& out, MyString& ob);//友元函数重载<<的友元声明
    friend istream& operator>>(istream& in, MyString& ob);//友元函数重载>>的友元声明
private:
    char* str;
    int size;//字符串长度
public:
    MyString();//无参构造
    MyString(const char* str);//有参构造函数
    MyString(const MyString& ob);//拷贝构造
    ~MyString();//析构函数
    MyString& operator =(const MyString& ob);//赋值函数 成员函数重载= 实现深赋值 ob1=ob2;
    int Size();//返回字符串长度
    char& operator[](int i);//成员函数重载[]
    MyString& operator+(const MyString& ob);//成员函数重载+ 实现ob1+ob2
    MyString& operator+(const char* str);//成员函数重载+ 实现ob1+"abc"
    bool operator==(const MyString& ob);//成员函数重载== 判断ob1==ob2
    bool operator==(const char* str);//成员函数重载== 判断ob1=="abc"
    bool operator!=(const MyString& ob);//成员函数重载!= 判断ob1!=ob2
    bool operator!=(const char* str);//成员函数重载!= 判断ob1!="abc"
};
ostream& operator<<(ostream& out, MyString& ob);//友元函数重载<<
istream& operator>>(istream& in, MyString& ob);//友元函数重载>>
#endif // MYSTRING_H
