#include "string.h"
#include<stdlib.h>
int Choice(const char* prompt, const char* options = "");
void test1()  //1 --- �ַ��������졢��������ֵ��صĺ���
{
	String s1("SHU");		//���캯��
	cout << s1 << endl;
	cout << "----�����޲ι���----" << endl;
	String s2;	//�޲ι���
	cout << "----���и�ֵ----" << endl;
	s2 = s1;	//��ֵ����
	cout << s2 << endl;
	system("pause"); system("CLS");
}
void test2()  //2 --- �����������<<��>>��+��=��==��!=��[]
{
	String s1("hello");
	cout << "s1 = " << s1 << endl;		//�����<<����
	String s2;
	cout << "������s2:";
	cin >> s2;		//�����>>����
	cout <<"s2=" << s2 << endl;
	String s3;
	s3 = s1 + s2;	//�����=,+����
	cout <<"s3=s1+s2=" << s3 << endl;
	try
	{
		cout << "s1[1] = " << s1[1] << endl;
	}
	catch (execption e)
	{
		cout << e.i << endl;
	}
	try
	{
		cout << "s1[7] = " ;
		cout << s1[7] << endl;
	}
	catch (execption e)
	{
		cout << endl;
		cout <<"���ش���" << e.i << endl;
	}
	if (s1 == s2)	//�����==����
		cout << "s1��s2���" << endl;
	else
		cout << "s1��s2�����" << endl;
	if (s1 != s2)	//�����!=����
		cout << "s1��s2�����" << endl;
	else
		cout << "s1��s2���" << endl;
	system("pause"); system("CLS");
}
void test3()
{
	int key,l,p;
	String temp1, temp2;
	while (true)
	{
		cout << "\n\n\t�ַ�����ģ�����" << endl;
		cout << "1 --- empty�������ԣ��ж�String�Ƿ�Ϊ�գ�" << endl;
		cout << "2 --- swap�������ԣ�������String�����ֵ����<<��>>��+��=��==��!=��[]" << endl;
		cout << "3 --- c_str�������ԣ�����ָ�����ͣ�" << endl;
		cout << "4 --- Size�������ԣ������ַ������ȣ�" << endl;
		cout << "5 --- insert�������ԣ������ַ�����" << endl;
		cout << "6 --- Reverse�������ԣ���ת�ַ�����" << endl;
		cout << "7 --- Compare�������ԣ��Ƚ���String���͵Ĵ�С��" << endl;
		cout << "8 --- Find�������ԣ������ַ���λ�ã�" << endl;
		cout << "9 --- Append�������ԣ����ַ���β�������ַ�����" << endl;
		cout << "a --- clear�������ԣ�����ַ������ݣ�" << endl;
		cout << "b --- erase�������ԣ�ɾ��һ���ַ�����" << endl;
		cout << "c --- Condense�������ԣ�ѹ���ַ�����ɾ���ַ����еĿո�" << endl;
		key = Choice("\n��ѡ��", "123456789abc\x1b");
		cout << "\n\n";
		system("CLS");
		if (key == 27)		// '\x1b'����27��ָESC��
			break;
		cout << "�������ַ���1:" ;
		cin >> temp1;
		cout << endl;
		switch (key)
		{
		case '1':	if (temp1.empty()) cout << "�ַ���Ϊ��<<endl"; else cout << "�ַ�����Ϊ��" << endl; system("pause"); system("CLS");				break;
		case '2':	cout << "�������ַ���2:"; cin >> temp2; cout << endl; temp1.swap(temp2); cout << "string1:" << temp1 << endl; cout << "string2:" << temp2 << endl; system("pause"); system("CLS");				break;
		case '3':	cout<<"string1:"<<temp1.c_str()<<endl; system("pause"); system("CLS");				break;
		case '4':	cout << "string1�ĳ���:" << temp1.Size() << endl; system("pause"); system("CLS");				break;
		case '5':	cout << "������string2��"; cin >> temp2; cout << endl; cout << "������������뵽�ĸ��±�֮ǰ��"; cin >> l; try { temp1.insert(temp2, l); cout << "����֮����ַ���Ϊ��" << temp1 << endl; }
				catch (execption e) { cout << e.msg << endl; }system("pause"); system("CLS");			break;
		case '6':	try { cout << "��ת֮����ַ���Ϊ��"; temp1.Reverse(); cout << temp1 << endl; }
				catch (execption e) {
					cout << e.msg << endl;
				}system("pause"); system("CLS");			break;
		case '7':	cout << "������string2��"; cin >> temp2; cout << endl;	try {
			if (temp1.Compare(temp2) == 0) cout << "string1=string2" << endl; else if (temp1.Compare(temp2) > 0) cout << "string1>string2" << endl; else cout << "string1<string2" << endl;
		}
				catch (execption e) { cout << e.msg << endl; }system("pause"); system("CLS");			break;
		case '8':	cout << "������string2��"; cin >> temp2; cout << endl;try
		{
			l = temp1.Find(temp2);
			cout << "�����ַ�����string1�е�λ���±�Ϊ" << l << endl;
		}
		catch (execption e)
		{
			cout << e.msg << endl;
		}system("pause"); system("CLS");					break;
		case '9':	cout << "������string2��"; cin >> temp2; cout << endl; temp1.Append(temp2.c_str());	cout << "��string2��ӵ�string1β����string1Ϊ��" << temp1 << endl; system("pause"); system("CLS");			break;
		case 'a':	cout << "string1Ϊ��" << temp1 << endl; cout << "Clear. . . . ." << endl; temp1.clear(); cout << "string1Ϊ��" << temp1 << endl; system("pause"); system("CLS");		break;
		case 'b':	cout << "�����뿪ʼɾ�����±�λ���Լ�����ɾ�����±�λ�ã�"; cin >> l>>p;try
		{
			temp1.erase(l, p);
			cout << temp1 << endl;
		}
		catch (execption e)
		{
			cout << e.msg << endl;
		}system("pause"); system("CLS");	break;
		case 'c':	cout << "�Ƿ�ѹ���ַ����ڵĿո�(1/0)" << endl; cin >> l; temp1.Condense(l); cout <<"���ѹ������ַ���Ϊ��" << temp1 << endl; system("pause"); system("CLS");		break;
		}	
	}
}
int Pos(char ch, const char* str)			// ����ָ���ַ�ch���ַ���str�е��±ꡣ������ʱ����-1
{
	int i;
	for (i = 0; str[i] != '\0'; i++)
		if (ch == str[i])
			return i;
	return -1;
}
int Choice(const char* prompt, const char* options)		// �������塣�����ʾ��Ϣprompt������ѡ����ַ������ء�
{
	int key;
	cout << prompt << "{";
	for (int i = 0; options[i] != '\0'; i++)
	{
		if (' ' < (options[i] & 0x7f) && (options[i] & 0x7f) < 127)	// ѡ��options�еĿɴ�ӡ�ַ�
			cout << options[i] << ' ';
		else														// ѡ��options�еĲ��ֿ����ַ�
		{
			switch (options[i])
			{
			case '\t':   cout << "[Tab] ";   break;					// ѡ���е�Tab�ַ�'\t'����ASCII����9��
			case '\x1b': cout << "[Esc] ";   break;					// ѡ���е�Esc�ַ�'\x1b'����ASCII����27��
			case ' ':    cout << "[Space] "; break;					// ѡ���еĿո��ַ�' '����ASCII����32��
			}
		}
	}
	cout << "\b}: ";					// '\b'�˸�����һ��������һ�����
	do
	{
		key = _getch();
	} while (options[0] != '\0' && Pos(key, options) < 0); // ��optionsΪ�ճ���Ϊ0���ַ����������������ƣ�����������Ӧ����optins�С�
	cout << endl;
	return key;
}
int main()
{
	int key;
	while (true)
	{
		cout << "\n\n\t�ַ�����ģ�����" << endl;
		cout << "1 --- �ַ��������졢��������ֵ��صĺ���" << endl;
		cout << "2 --- �����������<<��>>��+��=��==��!=��[]" << endl;
		cout << "3 --- String��������" << endl;
		key = Choice("\n��ѡ��", "123\x1b");
		system("CLS");
		cout << "\n\n";
		if (key == 27)		// '\x1b'����27��ָESC��
			break;
		switch (key)
		{
		case '1':	test1();			break;
		case '2':	test2();			break;
		case '3':	test3();			break;
		}
	}
	return 0;
}