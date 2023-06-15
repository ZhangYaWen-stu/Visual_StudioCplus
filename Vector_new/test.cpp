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
	cout << "{请输入\t";
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
	cout << "----调用无参数的构造函数----" << endl;
	cout << d << endl;
	Vector<int> c(15);
	cout << "----调用有参数的构造函数----" << endl;
	cout << c << endl;
	int a[4] = { 0,1,2,3 };
	Vector<int> b(a, sizeof(a) / sizeof(a[0]));
	cout << "----调用有参数的构造函数----" << endl;
	cout << b << endl;
	Vector<int> e(b);
	cout << "----调用拷贝构造函数----" << endl;
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
	cout << "<<的重载:" <<"向量a为" << a << endl;
	try {
		cout << "[]的重载" << endl;
		cout << "a[1]=" << a[1] << endl;
		cout << "a[10]=";
		cout<< a[10] << endl;
	}
	catch(execption e) {
		cout << e.msg << endl;
	}
	try {
		cout << "+的重载" << endl;
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
		cout << "-的重载" << endl;
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
		cout << "*的重载" << endl;
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
		cout << "\n\n\t字符串类模板测试" << endl;
		cout << "1 --- push_back函数测试（在向量尾部加入一个新的数据）" << endl;
		cout << "2 --- pop_back函数测试（删除向量尾部的数据）" << endl;
		cout << "3 --- clear函数测试（删除向量的所有数据）" << endl;
		cout << "4 --- at函数测试（返回下标指向的数据的引用）" << endl;
		cout << "5 --- empty函数测试（判断数据是否为空）" << endl;
		cout << "6 --- GetDim函数测试（反转字符串）" << endl;
		cout << "7 --- swap函数测试（交换两向量的值）" << endl;
		cout << "8 --- erase函数测试（删除下标[head,end)的值）" << endl;
		cout << "9 --- assign函数测试（更改相应的的值）" << endl;
		cout << "A/a --- reverse函数测试（反转向量）" << endl;
		cout << "B/b --- resize函数测试（重置向量的大小）" << endl;
		cout << "C/c --- insert（在下标前加入元素）" << endl;
		key = Key("123456789AaBbCc\x1b");
		cout << "\n\n";
		system("CLS");
		if (key == 27)		// '\x1b'等于27，指ESC键
			break;
		Vector<int> temp1(5);
		Vector<int> temp2(5);
		int temp,temp3,a[3]={0,1,2};
		temp1.assign(0, 1);
		temp1.assign(3, 1);
		switch (key)
		{
		case '1':cout << "请输入想添加的元素："; cin >> temp; cout << "Vector1为：" << temp1 << endl; temp1.push_back(temp); cout << "添加后Vector1为：" << temp1 << endl; system("pause");system("CLS"); break;
		case '2':try {
			cout << "Vector1为：" << temp1 << endl; temp1.pop_back(); cout << "删除后Vector1为：" << temp1 << endl;
		}
				catch (execption e) {
					cout << e.msg << endl;
				}system("pause"); system("CLS"); break;
		case '3':cout << "Vector1为：" << temp1 << endl; temp1.clear(); cout << "清除后Vector1为：" << temp1 << endl; system("pause"); system("CLS"); break;
		case '4':try {
			cout << "请输入下标："; cin >> temp; cout << "Vector1为：" << temp1 << endl;cout << "引用的元素为" << temp1.at(temp) << endl;
		}
				catch (execption e) {
					cout << e.msg << endl;
				}system("pause"); system("CLS"); break;
		case '5':if (temp1.empty()) cout << "该向量不为空" << endl; else cout << "该向量为空" << endl; system("pause"); system("CLS"); break;
		case '6':cout << "Vector1为：" << temp1 << endl; cout << "Vector1的维数为：" << temp1.GetDim() << endl; system("pause"); system("CLS"); break;
		case '7':cout << "Vector1为：" << temp1 << endl; cout << "Vector2为：" << temp2 << endl; temp1.swap(temp2); cout << "交换后的Vector1为：" << temp1 << endl; cout << "交换后的Vector2为：" << temp2 << endl; system("pause"); system("CLS"); break;
		case '8':try {
			cout << "请输入head："; cin >> temp; cout << "请输入end："; cin >> temp3; cout << "Vector1为：" << temp1 << endl; temp1.erase(temp, temp3); cout << "删除之后的向量" << temp1 << endl;
		}
				catch (execption e) {
					cout << e.msg << endl;
				}system("pause"); system("CLS"); break;
		case '9':try {
			cout << "请输入要更改元素的下标："; cin >> temp; cout << "请输入要更改的值："; cin >> temp3; cout << "Vector1为：" << temp1 << endl; temp1.assign(temp, temp3); cout << "更改之后的向量" << temp1 << endl;
		}
				catch (execption e) {
					cout << e.msg << endl;
				}system("pause"); system("CLS"); break;
		case 'A':
		case 'a':try {
			 cout << "Vector1为：" << temp1 << endl; temp1.reverse(); cout << "反转之后的向量" << temp1 << endl;
		}
				catch (execption e) {
					cout << e.msg << endl;
				}system("pause"); system("CLS"); break;
		case 'B':
		case 'b':cout << "Vector1为：" << temp1 << endl; temp1.resize(15, sizeof(a) / sizeof(a[0]), a); cout << "重置之后的向量" << temp1 << endl; system("pause"); system("CLS"); break;
		case 'C':
		case 'c':try {
			cout << "请输入下标："; cin >> temp; cout << "请输入要插入的值："; cin >> temp3; cout << "Vector1为：" << temp1 << endl; temp1.insert(temp, temp3); cout << "更改之后的向量" << temp1 << endl;
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
		cout << "\n\n\t字符串类模板测试" << endl;
		cout << "1 --- Vector对象构造、析构、赋值相关的函数" << endl;
		cout << "2 --- 重载运算符：<<、+、-、=、==、!=、[]" << endl;
		cout << "3 --- Vector函数测试" << endl;
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