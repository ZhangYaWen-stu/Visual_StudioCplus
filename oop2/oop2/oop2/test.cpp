#include"mystring.h"
int Pause(const char* prompt = "���������������")
{
	cout << prompt;
	return getch();
}
void test1()  //1 --- �ַ��������졢��������ֵ��صĺ���
{
	MyString s1("SHU");		//���캯��
	cout << s1 << endl;
	MyString s2;	//�޲ι���
	s2 = s1;	//��ֵ����
	cout << s2 << endl;
	
}
void test2()  //2 --- �����������<<��>>��+��=��==��!=��[]
{
	MyString s1("hello");
	cout << "s1 = " << s1 << endl;		//�����<<����
	MyString s2;
	cout << "������s2:";
	cin >> s2 ;		//�����>>����
	cout << s2;
	MyString s3;
	s3 = s1 + s2;	//�����=,+����
	cout << s3 << endl;
	cout << "s1[1] = " << s1[1] << endl;
	cout << "s1[7] = " << endl;
	cout << s1[7] << endl;

	if (s1 == s2)	//�����==����
		cout << "s1��s2���" << endl;
	else
		cout << "s1��s2�����" << endl;
	if (s1 != s2)	//�����!=����
		cout << "s1��s2�����" << endl;
	else
		cout << "s1��s2���" << endl;
	
}