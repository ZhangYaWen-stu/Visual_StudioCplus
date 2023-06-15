#include "SharedSeqStack.h"
int main()
{
	SharedStack<int> a;
	int temp,flag;
	Status p;
	char t;
	while (true)
	{
		cout << "1--�����µ�ջ" << endl;
		cout << "2--��ջ����" << endl;
		cout << "3--��ջ����" << endl;
		cout << "4--չʾջ" << endl;
		cout << "5--�ж�ջ��" << endl;
		cout << "��ѡ��(1~5) ����e�˳�����" << endl;
		cin >> t;
		if (t == 'e')
			break;
		switch (t)
		{
		case '1':
			if (!a.IsEmpty(1)||!a.IsEmpty(2))
				a.Clear();
			cout << "������������ջA������-1ֹͣ������" << endl;
			while (true)
			{
				cin >> temp;
				if (temp == -1)
					break;
				if (a.push(temp,1) == OVER_FLOW)
				{
					cout << "ջ����" << endl;
					break;
				}
			}
			if (a.StackFull())
			{
				cout << "����ջ�ռ�����,����ִ����ջB����" << endl;
				break;
			}
			cout << "������������ջB������-1ֹͣ������" << endl;
			while (true)
			{
				cin >> temp;
				if (temp == -1)
					break;
				if (a.push(temp, 2) == OVER_FLOW)
				{
					cout << "ջ����" << endl;
					break;
				}
			}
			cout << "�ѽ����µ�ջ" << endl; break;
		case '2':
			cout << "����������" << endl;
			cin >> temp;
			cout << "������ջA|B��1|2��" << endl;
			cin >> flag;
			if ((p = a.push(temp, flag)) == OVER_FLOW)
				cout << "ջ����" << endl;
			else if (p == PARAMETER_ERROR)
				cout << "ѡ������ջ��������" << endl;
			else cout << "����ջ" << endl; break;
		case '3':
			cout << "�����ջA|B��1|2��" << endl;
			cin >> flag;
			if ((p=a.pop(temp,flag)) == UNDER_FLOW)
				cout << "�����ѿ�" << endl;
			else if(p==PARAMETER_ERROR)
				cout << "ѡ������ջ��������" << endl;
			else cout << temp << "�ѳ�ջ" << endl; break;
		case '4':
			a.output();
			break;
		case '5':
			cout << "������鿴ջA|B�Ƿ�Ϊ�գ�1|2��" << endl;
			cin >> flag;
			try {
				if (a.IsEmpty(flag))
					cout << "��ѡջΪ��" << endl;
				else cout << "��ѡջ��Ϊ��" << endl;
			}
			catch(Status){
				cout << "������ջ�Ĳ�������" << endl;
			}
		}
		system("PAUSE");
		//system("CLS");
	}

	return 0;
}