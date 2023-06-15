#pragma once
#include <iostream>
#include <string>
#include<iomanip>
#include <conio.h>
#include <sstream>
using namespace std;
class Student
{
private:
	double calculus, english, pe, physics, programming, score;
	string name, id,password;
public:
	Student(double a = 0, double b = 0, double c = 0, double d = 0, double e = 0, string g = "", string h = "",string p="000");
	friend istream& operator>> (istream& in,Student &stu);
	friend ostream& operator<< (ostream& out,Student &stu);
	friend bool operator!=(Student& stu1,Student& stu2);
	void Set(string x, int n);
	void Set(double x, int n);
	bool VerifyPassword();
	void SetPassword();
	bool operator>(Student stu);
	bool operator<(Student stu);
	void transform(double& n);
	void Show();
	void Score();
	string GetPassword()
	{
		return password;
	}
};
int Key(const char* a);
int Pos(const char ch, const char* str);
int Retry();

