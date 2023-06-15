#include"mystring.h"
int Pause(const char* prompt = "按任意键继续……")
{
	cout << prompt;
	return getch();
}
void test1()  //1 --- 字符串对象构造、析构、赋值相关的函数
{
	MyString s1("SHU");		//构造函数
	cout << s1 << endl;
	MyString s2;	//无参构造
	s2 = s1;	//赋值函数
	cout << s2 << endl;
	
}
void test2()  //2 --- 重载运算符：<<、>>、+、=、==、!=、[]
{
	MyString s1("hello");
	cout << "s1 = " << s1 << endl;		//运算符<<重载
	MyString s2;
	cout << "请输入s2:";
	cin >> s2 ;		//运算符>>重载
	cout << s2;
	MyString s3;
	s3 = s1 + s2;	//运算符=,+重载
	cout << s3 << endl;
	cout << "s1[1] = " << s1[1] << endl;
	cout << "s1[7] = " << endl;
	cout << s1[7] << endl;

	if (s1 == s2)	//运算符==重载
		cout << "s1与s2相等" << endl;
	else
		cout << "s1与s2不相等" << endl;
	if (s1 != s2)	//运算符!=重载
		cout << "s1与s2不相等" << endl;
	else
		cout << "s1与s2相等" << endl;
	
}