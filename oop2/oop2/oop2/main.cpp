#include"mystring.h"
using namespace std;
int Pos(char ch, const char* str)			// 返回指定字符ch在字符串str中的下标。不存在时返回-1
{
	int i;
	for (i = 0; str[i] != '\0'; i++)
		if (ch == str[i])
			return i;
	return -1;
}
int Choice(const char* prompt, const char* options = "");	// 函数声明
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
		key = getch();
	} while (options[0] != '\0' && Pos(key, options) < 0); // 若options为空长度为0的字符串，则输入无限制；否则输入项应该在optins中。
	cout << endl;
	return key;
}
int main()
{
	void test1(), test2();
	int key;
	while (true)
	{
		cout << "\n\n\t字符串类模板测试" << endl;
		cout << "1 --- 字符串对象构造、析构、赋值相关的函数" << endl;
		cout << "2 --- 重载运算符：<<、>>、+、=、==、!=、[]" << endl;
		key = Choice("\n请选择", "12345\x1b");
		cout << "\n\n";
		if (key == 27)		// '\x1b'等于27，指ESC键
			break;
		switch (key)
		{
		case '1':	test1();			break;
		case '2':	test2();			break;
		}
	}
	return 0;
}