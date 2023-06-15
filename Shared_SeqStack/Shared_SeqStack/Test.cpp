#include "SharedSeqStack.h"
int main()
{
	SharedStack<int> a;
	int temp,flag;
	Status p;
	char t;
	while (true)
	{
		cout << "1--创建新的栈" << endl;
		cout << "2--入栈操作" << endl;
		cout << "3--出栈操作" << endl;
		cout << "4--展示栈" << endl;
		cout << "5--判断栈空" << endl;
		cout << "请选择(1~5) 输入e退出程序" << endl;
		cin >> t;
		if (t == 'e')
			break;
		switch (t)
		{
		case '1':
			if (!a.IsEmpty(1)||!a.IsEmpty(2))
				a.Clear();
			cout << "请输入整数入栈A（输入-1停止操作）" << endl;
			while (true)
			{
				cin >> temp;
				if (temp == -1)
					break;
				if (a.push(temp,1) == OVER_FLOW)
				{
					cout << "栈已满" << endl;
					break;
				}
			}
			if (a.StackFull())
			{
				cout << "共享栈空间已满,不再执行入栈B操作" << endl;
				break;
			}
			cout << "请输入整数入栈B（输入-1停止操作）" << endl;
			while (true)
			{
				cin >> temp;
				if (temp == -1)
					break;
				if (a.push(temp, 2) == OVER_FLOW)
				{
					cout << "栈已满" << endl;
					break;
				}
			}
			cout << "已建立新的栈" << endl; break;
		case '2':
			cout << "请输入整数" << endl;
			cin >> temp;
			cout << "请输入栈A|B（1|2）" << endl;
			cin >> flag;
			if ((p = a.push(temp, flag)) == OVER_FLOW)
				cout << "栈已满" << endl;
			else if (p == PARAMETER_ERROR)
				cout << "选择所入栈参数错误" << endl;
			else cout << "已入栈" << endl; break;
		case '3':
			cout << "请输出栈A|B（1|2）" << endl;
			cin >> flag;
			if ((p=a.pop(temp,flag)) == UNDER_FLOW)
				cout << "队列已空" << endl;
			else if(p==PARAMETER_ERROR)
				cout << "选择所出栈参数错误" << endl;
			else cout << temp << "已出栈" << endl; break;
		case '4':
			a.output();
			break;
		case '5':
			cout << "请输入查看栈A|B是否为空（1|2）" << endl;
			cin >> flag;
			try {
				if (a.IsEmpty(flag))
					cout << "所选栈为空" << endl;
				else cout << "所选栈不为空" << endl;
			}
			catch(Status){
				cout << "所输入栈的参数错误" << endl;
			}
		}
		system("PAUSE");
		//system("CLS");
	}

	return 0;
}