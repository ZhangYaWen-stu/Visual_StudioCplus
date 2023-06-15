#include "string.h"
#include<stdlib.h>
int Choice(const char* prompt, const char* options = "");
bool Try()
{
    int key;
	key = Choice("\n请选择", "YyNn");
	if (key == 'y' || key == 'Y')
		return true;
	else return false;
}
void test1()  //1 --- 字符串对象构造、析构、赋值相关的函数
{
	cout << "=====|1 --- 字符串对象构造、析构、赋值相关的函数        |=====" << endl<<endl;
	String s1("SHU");		//构造函数
	cout <<"s1 = "<< s1 << endl;
	cout << "----进行无参构造----" << endl;
	String s2;	//无参构造
	cout << "----进行赋值----" << endl;
	s2 = s1;	//赋值函数
	cout << "s2 = " << s2 << endl;
	system("pause"); system("CLS");
}
void test2()  //2 --- 重载运算符：<<、>>、+、=、==、!=、<、>、[]  
{
	cout << "=====|2 --- 重载运算符：<<、>>、+、=、==、!=、<、>、[]  |=====" << endl << endl;
	String s1("hello");
	cout << "s1 = " << s1 << endl;		//运算符<<重载
	String s2;
	cout << "请输入s2:";
	cin >> s2;		//运算符>>重载
	cout <<"s2 = " << s2 << endl;
	String s3;
	s3 = s1 + s2;	//运算符=,+重载
	cout <<"s3 = s1 + s2 = " << s3 << endl;
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
		cout <<"返回错误下标：" << e.i << endl;
	}
	if (s1 != s2)	//运算符!=重载
		cout << "s1与s2不相等" << endl;
	if (s1 == s2)	//运算符==重载
		cout << "s1与s2相等" << endl;
	else {
		if (s1 > s2)	//运算符>重载
			cout << "s1 > s2" << endl;
		else
			cout << "s1 < s2" << endl;
		if (s1 < s2)	//运算符<重载
			cout << "s1 < s2" << endl;
		else
			cout << "s1 > s2" << endl;
	}
	system("pause"); system("CLS");
}
void test3()
{
	int key,l,p;
	char emp;
	String temp1, temp2;
	while (true)
	{
		cout << "\t=========================================================================" << endl;
		cout << "\t|==========================String函数测试 ==============================|" << endl;
		cout << "\t|1   --- empty函数测试（判断String是否为空）                            |" << endl;
		cout << "\t|2   --- swap函数测试（交换两String对象的值）                           |" << endl;
		cout << "\t|3   --- c_str函数测试（返回指针类型）                                  |" << endl;
		cout << "\t|4   --- Size函数测试（返回字符串长度）                                 |" << endl;
		cout << "\t|5   --- insert函数测试（插入字符串）                                   |" << endl;
		cout << "\t|6   --- Reverse函数测试（反转字符串）                                  |" << endl;
		cout << "\t|7   --- Compare函数测试（比较两String类型的大小）                      |" << endl;
		cout << "\t|8   --- Find函数测试（查找字符串位置）                                 |" << endl;
		cout << "\t|9   --- Append函数测试（在字符串尾部接上字符串）                       |" << endl;
		cout << "\t|A/a --- clear函数测试（清空字符串内容）                                |" << endl;
		cout << "\t|B/b --- erase函数测试（删除一段字符串）                                |" << endl;
		cout << "\t|C/c --- Condense函数测试（压缩字符串，删除字符串中的空格）             |" << endl;
		cout << "\t=========================================================================" << endl;
		key = Choice("\n请选择", "123456789AaBbCc\x1b");
		cout << "\n\n";
		system("CLS");
		if (key == 27)		// '\x1b'等于27，指ESC键
			break;
		switch (key)
		{
		case '1':	cout << "\n=====|1   --- empty函数测试（判断String是否为空）                            |=====" << endl << endl; break;
		case '2':	cout << "\n=====|2   --- swap函数测试（交换两String对象的值）                           |=====" << endl << endl; break;
		case '3':	cout << "\n=====|3   --- c_str函数测试（返回指针类型）                                  |=====" << endl << endl; break;
		case '4':	cout << "\n=====|4   --- Size函数测试（返回字符串长度）                                 |=====" << endl << endl; break;
		case '5':	cout << "\n=====|5   --- insert函数测试（插入字符串）                                   |=====" << endl << endl; break;
		case '6':	cout << "\n=====|6   --- Reverse函数测试（反转字符串）                                  |=====" << endl << endl; break;
		case '7':	cout << "\n=====|7   --- Compare函数测试（比较两String类型的大小）                      |=====" << endl << endl; break;
		case '8':	cout << "\n=====|8   --- Find函数测试（查找字符串位置）                                 |=====" << endl << endl; break;
		case '9':	cout << "\n=====|9   --- Append函数测试（在字符串尾部接上字符串）                       |=====" << endl << endl; break;
		case 'a':
		case 'A':	cout << "\n=====|A/a --- clear函数测试（清空字符串内容）                                |=====" << endl << endl; break;
		case 'b':
		case 'B':	cout << "\n=====|B/b --- erase函数测试（删除一段字符串）                                |=====" << endl << endl; break;
		case 'c':
		case 'C':	cout << "\n=====|C/c --- Condense函数测试（压缩字符串，删除字符串中的空格）             |=====" << endl << endl; break;
		}
		cout << "请输入string1:" ;
		cin >> temp1;
		cout << endl;
		switch (key)
		{
		case '1':	if (temp1.empty()) cout << "字符串为空"<<endl; else cout << "字符串不为空" << endl; system("pause"); system("CLS");				break;
		case '2':	cout << "请输入string2:"; cin >> temp2; cout << endl; temp1.swap(temp2); cout << "string1:" << temp1 << endl; cout << "string2:" << temp2 << endl; system("pause"); system("CLS");				break;
		case '3':	cout<<"string1:"<<temp1.c_str()<<endl; system("pause"); system("CLS");				break;
		case '4':	cout << "string1的长度:" << temp1.Size() << endl; system("pause"); system("CLS");				break;
		case '5':	cout << "请输入string2："; cin >> temp2; cout << endl; cout << "请输入您想插入到哪个下标之前："; cin >> l; emp=getchar(); try { temp1.insert(temp2, l); cout << "插入之后的字符串为：" << temp1 << endl; }
				catch (execption e) { cout << e.msg << endl; }system("pause"); system("CLS");			break;
		case '6':	 try { cout << "反转之后的字符串为："; temp1.Reverse(); cout << temp1 << endl; }
				catch (execption e) {
					cout << e.msg << endl;
				}system("pause"); system("CLS");			break;
		case '7':	 cout << "请输入string2："; cin >> temp2; cout << endl;	try {
			if (temp1.Compare(temp2) == 0) cout << "string1=string2" << endl; else if (temp1.Compare(temp2) > 0) cout << "string1>string2" << endl; else cout << "string1<string2" << endl;
		}
				catch (execption e) { cout << e.msg << endl; }system("pause"); system("CLS");			break;
		case '8':	 cout << "请输入string2："; cin >> temp2; cout << endl;try
		{
			l = temp1.Find(temp2);
			cout << "输入字符串在string1中的位置下标为：" << l << endl;
		}
		catch (execption e)
		{
			cout << e.msg << endl;
		}system("pause"); system("CLS");					break;
		case '9':	 cout << "请输入string2："; cin >> temp2; cout << endl; temp1.Append(temp2.c_str());	cout << "将string2添加到string1尾部后，string1为：" << temp1 << endl; system("pause"); system("CLS");			break;
		case 'a':
		case 'A':	 cout << "string1为：" << temp1 << endl; cout << "Clear. . . . ." << endl; temp1.clear(); cout << "string1为：" << temp1 << endl; system("pause"); system("CLS");		break;
		case 'b':
		case 'B':	 cout << "请输入开始删除的下标位置以及结束删除的下标位置："; cin >> l >> p; emp=getchar(); try
		{
			temp1.erase(l, p);
			cout << "temp1:"<<temp1 << endl;
		}
		catch (execption e)
		{
			cout << e.msg << endl;
		}system("pause"); system("CLS");	break;
		case 'c':
		case 'C':	 cout << "是否压缩字符串内的空格" << endl;  temp1.Condense(Try()); cout <<"输出压缩后的字符串为：" << temp1 << endl; system("pause"); system("CLS");		break;
		}	
	}
}
int Pos(char ch, const char* str)			// 返回指定字符ch在字符串str中的下标。不存在时返回-1
{
	int i;
	for (i = 0; str[i] != '\0'; i++)
		if (ch == str[i])
			return i;
	return -1;
}
int Choice(const char* prompt, const char* options)		// 函数定义。输出提示信息prompt，输入选择的字符并返回。
{
	int key;
	cout << prompt << "{";
	for (int i = 0; options[i] != '\0'; i++)
	{
		if (' ' < (options[i] & 0x7f) && (options[i] & 0x7f) < 127)	// 选项options中的可打印字符
			cout << options[i] << ' ';
		else														// 选项options中的部分控制字符
		{
			switch (options[i])
			{
			case '\t':   cout << "[Tab] ";   break;					// 选项中的Tab字符'\t'（即ASCII编码9）
			case '\x1b': cout << "[Esc] ";   break;					// 选项中的Esc字符'\x1b'（即ASCII编码27）
			case ' ':    cout << "[Space] "; break;					// 选项中的空格字符' '（即ASCII编码32）
			}
		}
	}
	cout << "\b}: ";					// '\b'退格。先退一格，在输出右花括号
	do
	{
		key = _getch();
	} while (options[0] != '\0' && Pos(key, options) < 0); // 若options为空长度为0的字符串，则输入无限制；否则输入项应该在optins中。
	cout << endl;
	return key;
}
int main()
{
	int key;
	while (true)
	{
		cout << "\t====================================================" << endl;
		cout << "\t|=================字符串类模板测试=================|" << endl;
		cout << "\t|1 --- 字符串对象构造、析构、赋值相关的函数        |" << endl;
		cout << "\t|2 --- 重载运算符：<<、>>、+、=、==、!=、<、>、[]  |" << endl;
		cout << "\t|3 --- String函数测试                              |" << endl;
		cout << "\t====================================================" << endl;
		key = Choice("\n请选择", "123\x1b");
		system("CLS");
		cout << "\n\n";
		if (key == 27)		// '\x1b'等于27，指ESC键
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