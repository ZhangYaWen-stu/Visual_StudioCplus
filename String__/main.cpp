#include "String__.h"
int main()
{
	String a, b, c;
	cout << "请输入第一个字符串（长度不超过128）：" << endl;
	cin >> a;
	cout << endl;
	cout << "请输入第二个字符串（长度不超过128）：" << endl;
	cin >> b;
	cout << endl;
	c = String::FsubK(a, b);
	cout << "两个字符串的最大子串为：" << endl;
	cout << c;
	return 0;
}