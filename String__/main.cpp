#include "String__.h"
int main()
{
	String a, b, c;
	cout << "�������һ���ַ��������Ȳ�����128����" << endl;
	cin >> a;
	cout << endl;
	cout << "������ڶ����ַ��������Ȳ�����128����" << endl;
	cin >> b;
	cout << endl;
	c = String::FsubK(a, b);
	cout << "�����ַ���������Ӵ�Ϊ��" << endl;
	cout << c;
	return 0;
}