#include"Vector.h"
#include"Vector.cpp"

int Pos(const char ch, const char* str)
{
	int len = int(strlen(str)), i = 0;
	for (; i < len; i++)
		if (ch == str[i])
			return 0;
	return 1;
}
int Key(const char* a)
{
	int i = 0;
	char s;
	cout << "{������\t";
	for (i = 0; a[i] != '\0'; i++)
	{
		if (' ' < (a[i] & 0x7f) && (a[i] & 0x7f) < 127)
			cout << a[i] << ' ';
		if (a[i] == '\x1b')
			cout << "[Esc]}:" << endl;
	}
	s = _getch();
	for (; Pos(s, a) && a[0] != '\0'; s = _getch());
	return s;
}
int Retry()
{
	char key;
	key = Key("YyNn\x1b");
	if (key == 'Y' || key == 'y')
		return 1;
	else return 0;
}
void test1()  
{
	Vector<int> d;
	cout << "----�����޲����Ĺ��캯��----" << endl;
	cout << d << endl;
	Vector<int> c(15);
	cout << "----�����в����Ĺ��캯��----" << endl;
	cout << c << endl;
	int a[4] = { 0,1,2,3 };
	Vector<int> b(a, sizeof(a) / sizeof(a[0]));
	cout << "----�����в����Ĺ��캯��----" << endl;
	cout << b << endl;
	Vector<int> e(b);
	cout << "----���ÿ������캯��----" << endl;
	cout << e << endl;
	system("pause");
	system("CLS");
}
void test2()
{
	Vector<int> a(4);
	a.assign(0, 1);
	a.assign(1, 4);
	Vector<int> b(4);
	b.assign(0, 3);
	b.assign(1, 6);
	Vector<int> c(4);
	Vector<int> d(3);
	Vector<char> e(4);
	Vector<char> f(4);
	Vector<char> g(4);
	int m=0;
	cout << "<<������:" <<"����aΪ" << a << endl;
	try {
		cout << "[]������" << endl;
		cout << "a[1]=" << a[1] << endl;
		cout << "a[10]=";
		cout<< a[10] << endl;
	}
	catch(execption e) {
		cout << e.msg << endl;
	}
	try {
		cout << "+������" << endl;
		cout << "a + b =";
		c = a + b;
		cout<< c << endl;
		cout << "a + d =";
		c = a + d;
		cout<< c << endl;
	}
	catch (execption e) {
		cout << e.msg << endl;
	}
	try {
		cout << "e + f =";
		g = e + f;
		cout<< g << endl;
	}
	catch (execption e) {
		cout << e.msg << endl;
	}
	try {
		cout << "-������" << endl;
		cout << "a - b =";
		c = a - b;
		cout<< c << endl;
		cout << "a - d =";
		c = a - d;
		cout<< c << endl;
	}
	catch (execption e) {
		cout << e.msg << endl;
	}
	try {
		cout << "e - f =";
		g = e - f;
		cout << g << endl;
	}
	catch (execption e) {
		cout << e.msg << endl;
	}
	try {
		cout << "*������" << endl;
		cout << "a * b =" << a * b << endl;
		cout << "a * d =" << a * d << endl;
	}
	catch (execption e) {
		cout << e.msg << endl;
	}
	try {
		cout << "e * f =" << e * f << endl;
	}
	catch (execption e) {
		cout << e.msg << endl;
	}
	if (a == b)
		cout << "a==b" << endl;
	else cout << "a!=b" << endl;
	system("pause");
	system("CLS");
}
void test3()
{
	int key;
	while (true)
	{
		cout << "\n\n\t�ַ�����ģ�����" << endl;
		cout << "1 --- push_back�������ԣ�������β������һ���µ����ݣ�" << endl;
		cout << "2 --- pop_back�������ԣ�ɾ������β�������ݣ�" << endl;
		cout << "3 --- clear�������ԣ�ɾ���������������ݣ�" << endl;
		cout << "4 --- at�������ԣ������±�ָ������ݵ����ã�" << endl;
		cout << "5 --- empty�������ԣ��ж������Ƿ�Ϊ�գ�" << endl;
		cout << "6 --- GetDim�������ԣ���ת�ַ�����" << endl;
		cout << "7 --- swap�������ԣ�������������ֵ��" << endl;
		cout << "8 --- erase�������ԣ�ɾ���±�[head,end)��ֵ��" << endl;
		cout << "9 --- assign�������ԣ�������Ӧ�ĵ�ֵ��" << endl;
		cout << "A/a --- reverse�������ԣ���ת������" << endl;
		cout << "B/b --- resize�������ԣ����������Ĵ�С��" << endl;
		cout << "C/c --- insert�����±�ǰ����Ԫ�أ�" << endl;
		key = Key("123456789AaBbCc\x1b");
		cout << "\n\n";
		system("CLS");
		if (key == 27)		// '\x1b'����27��ָESC��
			break;
		Vector<int> temp1(5);
		Vector<int> temp2(5);
		int temp,temp3,a[3]={0,1,2};
		temp1.assign(0, 1);
		temp1.assign(3, 1);
		switch (key)
		{
		case '1':cout << "����������ӵ�Ԫ�أ�"; cin >> temp; cout << "Vector1Ϊ��" << temp1 << endl; temp1.push_back(temp); cout << "��Ӻ�Vector1Ϊ��" << temp1 << endl; system("pause");system("CLS"); break;
		case '2':try {
			cout << "Vector1Ϊ��" << temp1 << endl; temp1.pop_back(); cout << "ɾ����Vector1Ϊ��" << temp1 << endl;
		}
				catch (execption e) {
					cout << e.msg << endl;
				}system("pause"); system("CLS"); break;
		case '3':cout << "Vector1Ϊ��" << temp1 << endl; temp1.clear(); cout << "�����Vector1Ϊ��" << temp1 << endl; system("pause"); system("CLS"); break;
		case '4':try {
			cout << "�������±꣺"; cin >> temp; cout << "Vector1Ϊ��" << temp1 << endl;cout << "���õ�Ԫ��Ϊ" << temp1.at(temp) << endl;
		}
				catch (execption e) {
					cout << e.msg << endl;
				}system("pause"); system("CLS"); break;
		case '5':if (temp1.empty()) cout << "��������Ϊ��" << endl; else cout << "������Ϊ��" << endl; system("pause"); system("CLS"); break;
		case '6':cout << "Vector1Ϊ��" << temp1 << endl; cout << "Vector1��ά��Ϊ��" << temp1.GetDim() << endl; system("pause"); system("CLS"); break;
		case '7':cout << "Vector1Ϊ��" << temp1 << endl; cout << "Vector2Ϊ��" << temp2 << endl; temp1.swap(temp2); cout << "�������Vector1Ϊ��" << temp1 << endl; cout << "�������Vector2Ϊ��" << temp2 << endl; system("pause"); system("CLS"); break;
		case '8':try {
			cout << "������head��"; cin >> temp; cout << "������end��"; cin >> temp3; cout << "Vector1Ϊ��" << temp1 << endl; temp1.erase(temp, temp3); cout << "ɾ��֮�������" << temp1 << endl;
		}
				catch (execption e) {
					cout << e.msg << endl;
				}system("pause"); system("CLS"); break;
		case '9':try {
			cout << "������Ҫ����Ԫ�ص��±꣺"; cin >> temp; cout << "������Ҫ���ĵ�ֵ��"; cin >> temp3; cout << "Vector1Ϊ��" << temp1 << endl; temp1.assign(temp, temp3); cout << "����֮�������" << temp1 << endl;
		}
				catch (execption e) {
					cout << e.msg << endl;
				}system("pause"); system("CLS"); break;
		case 'A':
		case 'a':try {
			 cout << "Vector1Ϊ��" << temp1 << endl; temp1.reverse(); cout << "��ת֮�������" << temp1 << endl;
		}
				catch (execption e) {
					cout << e.msg << endl;
				}system("pause"); system("CLS"); break;
		case 'B':
		case 'b':cout << "Vector1Ϊ��" << temp1 << endl; temp1.resize(15, sizeof(a) / sizeof(a[0]), a); cout << "����֮�������" << temp1 << endl; system("pause"); system("CLS"); break;
		case 'C':
		case 'c':try {
			cout << "�������±꣺"; cin >> temp; cout << "������Ҫ�����ֵ��"; cin >> temp3; cout << "Vector1Ϊ��" << temp1 << endl; temp1.insert(temp, temp3); cout << "����֮�������" << temp1 << endl;
		}
				catch (execption e) {
					cout << e.msg << endl;
				} system("pause"); system("CLS"); break;
		}
	}
}

int main()
{
	int key;
	while (true)
	{
		cout << "\n\n\t�ַ�����ģ�����" << endl;
		cout << "1 --- Vector�����졢��������ֵ��صĺ���" << endl;
		cout << "2 --- �����������<<��+��-��=��==��!=��[]" << endl;
		cout << "3 --- Vector��������" << endl;
		key = Key("123\x1b");
		system("CLS");
		cout << "\n\n";
		if (key == '\x1b')
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