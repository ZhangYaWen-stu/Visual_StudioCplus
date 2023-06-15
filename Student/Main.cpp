#include"Main.h"
Student NewStudent()
{
	system("CLS");
	Student stu;
	double temp;
	string p;
	cout << "��������ѧ��������:";
	cin >> p;
	stu.Set(p, 7);
	cout << "��������ѧ����ѧ��:";
	cin >> p;
	stu.Set(p, 8);
	cout << "��������ѧ����΢���ֳɼ�:";
	cin >> temp;
	stu.Set(temp, 1);
	cout << "��������ѧ����Ӣ��ɼ�:";
	cin >> temp;
	stu.Set(temp, 2);
	cout << "��������ѧ���������ɼ�:";
	cin >> temp;
	stu.Set(temp, 3);
	cout << "��������ѧ��������ɼ�:";
	cin >> temp;
	stu.Set(temp, 4);
	cout << "��������ѧ���ĳ�����Ƴɼ�:";
	cin >> temp;
	stu.Set(temp, 5);
	return stu;
}
Node<Student>* FindID(LinkList<Student>& Link)
{
	Node<Student>* goal;
	Student stu;
	string ID;
	cout << "�������������ѧ����ѧ��:";
	cin >> ID;
	stu.Set(ID, 8);
	goal = Link.Locate(stu, true);
	return goal;
}
Node<Student>* FindName(LinkList<Student>& Link)
{
	Node<Student>* goal;
	Student stu;
	string name;
	int k = 1;
	bool flag = true;
	cout << "��������Ҫ���ҵ�ѧ������:";
	cin >> name;
	stu.Set(name, 7);
	do
	{
		if (goal = Link.Locate(stu, flag))
		{
			cout << "������ϢΪ:\n"; goal->Return().Show();
			cout << "----�����Ƿ�Ϊ�������ҵ�ѧ��(y/n)----" << endl;
			k = Retry();
			flag = false;
			if (k)
				break;
			cout << "----��������----" << endl;
		}
		else break;
	} while (true);
	return goal;
}
void Grade(Node<Student>* s)
{
	int key;
	double x;
	cout << "\n\t\t========================================" << endl;
	cout << "\t\t|=========��ѡ����Ҫ�޸ĵĿ�Ŀ=========|" << endl;
	cout << "\t\t|1-----΢����                          |" << endl;
	cout << "\t\t|2-----Ӣ��                            |" << endl;
	cout << "\t\t|3-----����                            |" << endl;
	cout << "\t\t|4-----����                            |" << endl;
	cout << "\t\t|5-----�������                        |" << endl;
	cout << "\t\t|0-----�����ϼ�(ESC)                   |" << endl;
	cout << "\t\t========================================" << endl;
	key = Key("012345\x1b");
	if (key == '0' || key == '\x1b')
		return;
	cout << "����������Ҫ�޸�Ϊ:";
	cin >> x;
	s->Return().Set(x, key - '0');
}
int main()
{
	LinkList < LinkList<Student>> LLink;
	Student temp,stu;
	Node<Student> *s,*a;
	string filename = "Information.txt";
	string ID, Password;
	int t=0;
	int num = LLink.Load(filename.c_str()),n=0;
	int key;
	LinkList<Student>& Link = LLink.Go(0)->Return();
	LinkList<Student>& ALink = LLink.Go(1)->Return();
	while (true)
	{
		system("CLS");
		cout << "\t\t=====================" << endl;
		cout << "\t\t|=====ģʽѡ��====  |" << endl;
		cout << "\t\t|1-----ѧ��ģʽ     |" << endl;
		cout << "\t\t|2-----����Աģʽ   |" << endl;
		cout << "\t\t|0-----�˳�����(Esc)|" << endl;
		cout << "\t\t=====================" << endl;
		key = Key("012\x1b");
		if (key == 27 || key == '0')
			break;
		switch(key)
		{
		case '1':
			do
			{
				do
				{
					cout << "����������ѧ�ţ�";
					cin >> ID;
					temp.Set(ID, 8);
					t = 0;
					if ((s = Link.Locate(temp, true)) && (s->Return().VerifyPassword()))
					{
						do {
							system("CLS");
							cout << "\n\t\t=============================" << endl;
							cout << "\t\t|==========����ѡ��=========|" << endl;
							cout << "\t\t|1-----��ѯ�ɼ�             | " << endl;
							cout << "\t\t|2-----��ѯ����             |" << endl;
							cout << "\t\t|3-----��������             |" << endl;
							cout << "\t\t|0-----����ģʽѡ��(ESC)    |" << endl;
							cout << "\t\t=============================" << endl;
							key = Key("0123\x1b");
							if (key == '0' || key == '\x1b')
								break;
							switch (key) {
							case '1':
							{
								s->Return().Show(); system("pause");
							}break;
							case '2':
								{
									cout << "��������Ϊ��" << s->Rate(Link) << "��" << endl; system("pause");
								}break;
							case '3':
								{
									s->Return().SetPassword(); system("pause");
								}break;
							}
						} while (true);
					}
					else if(s==NULL){
						cout << "�����ѧ����Ч���Ƿ�������ԣ�y/n��" << endl;
						t = Retry();
					}
				} while (t);

			} while (t);
			break;
		case '2':
			do
			{
				do {
					cout << "�����������˺�:" ;
					cin >> ID;
					temp.Set(ID, 8);
					n = 0;
					if ((a = ALink.Locate(temp, true)) && a->Return().VerifyPassword())
					{
						do 
						{
							system("CLS");
							cout << "\n\t\t============================" << endl;
							cout << "\t\t|===========����ѡ��=======|" << endl;
							cout << "\t\t|1-----����ѧ��            |" << endl;
							cout << "\t\t|2-----�鿴ѧ����Ϣ        |" << endl;
							cout << "\t\t|3-----���ѧ����Ϣ        |" << endl;
							cout << "\t\t|4-----���Ĺ���Ա����      |" << endl;
							cout << "\t\t|0-----����ģʽѡ��(Esc)   |" << endl;
							cout << "\t\t============================" << endl;
							key = Key("01234\x1b");
							if (key == '0' || key == '\x1b')
								break;
							switch (key) {
							case '1':
							{
								system("CLS");
								cout << "\n\t\t=============================" << endl;
								cout << "\t\t|==========��������=========|" << endl;
								cout << "\t\t|1-----ѧ��                 |" << endl;
								cout << "\t\t|2-----����                 | " << endl;
								cout << "\t\t|0-----���ع���ѡ��(Esc)    |" << endl;
								cout << "\t\t=============================" << endl;
								key = Key("012\x1b");
								if (key == '0' || key == '\x1b')
									break;
								switch (key) {
								case '1':
									do
									{
										if (s = FindID(Link))
										{
											do
											{
												system("CLS");
												t = 1;
												cout << "\n\t\t===================================" << endl;
												cout << "\t\t|=========����Ҫ���еĲ���========|" << endl;
												cout << "\t\t|1-----��ѯ�ɼ�                   |" << endl;
												cout << "\t\t|2-----��ѯ����                   |" << endl;
												cout << "\t\t|3-----���ĸ����ɼ�               |" << endl;
												cout << "\t\t|4-----���ĸ�������               |" << endl;
												cout << "\t\t|5-----ɾ��������Ϣ               |" << endl;
												cout << "\t\t|0-----������һ��(Esc)            |" << endl;
												cout << "\t\t===================================" << endl;
												key = Key("012345\x1b");
												if (key == '0' || key == '\x1b')
												{
													t = 0;
													break;
												}
												switch (key) {
												case '1':s->Return().Show(); system("pause"); break;
												case '2':cout << "��������Ϊ��" << s->Rate(Link) << "��" << endl; system("pause"); break;
												case '3':Grade(s); system("pause"); break;
												case '4':cout << "������������:"; cin >> Password; s->Return().Set(Password, 9); system("pause"); break;
												case'5':cout << "�Ƿ����ɾ��(y/n)" << endl; if (Retry()) {
													Link.DeleteCurNode(); t = 0; cout << "----��ɾ��----" << endl; system("pause");
												} break;
													if (t == 1) { cout << "----�Ƿ�����Ը����Ĳ���(y/n)----" << endl; t = Retry(); }
												}
											} while (true && t);
										}
										else {
											cout << "----δ���ҵ�������Ϣ���Ƿ�����(y/n)----" << endl;
											t = Retry();
										}
									} while (true && t);
									break;
								case '2':
									do
									{
										if (s = FindName(Link))
										{
											do
											{
												system("CLS");
												t = 1;
												cout << "\n\t\t===================================" << endl;
												cout << "\t\t|=========����Ҫ���еĲ���========|" << endl;
												cout << "\t\t|1-----��ѯ�ɼ�                   |" << endl;
												cout << "\t\t|2-----��ѯ����                   |" << endl;
												cout << "\t\t|3-----���ĸ����ɼ�               |" << endl;
												cout << "\t\t|4-----���ĸ�������               |" << endl;
												cout << "\t\t|5-----ɾ��������Ϣ               |" << endl;
												cout << "\t\t|0-----������һ��(Esc)            |" << endl;
												cout << "\t\t===================================" << endl;
												key = Key("012345\x1b");
												if (key == '0' || key == '\x1b')
												{
													t = 0;
													break;
												}
												switch (key) {
												case '1':s->Return().Show(); system("pause"); break;
												case '2':cout << "��������Ϊ��" << s->Rate(Link) << "��" << endl; system("pause"); break;
												case '3':Grade(s); break;
												case '4':cout << "������������:"; cin >> Password; s->Return().Set(Password, 9); system("pause"); break;
												case'5':cout << "�Ƿ����ɾ��(y/n)" << endl; if (Retry()) {
													Link.DeleteCurNode(); t = 0; cout << "----��ɾ��----" << endl; system("pause");
												} break;
													if (t == 1) { cout << "----�Ƿ�����Ը����Ĳ���(y/n)----" << endl; t = Retry(); }
												}
											} while (true && t);
										}
										else {
											cout << "----δ���ҵ�������Ϣ���Ƿ�����(y/n)----" << endl;
											t = Retry();
										}
									} while (true && t);
								}break;


							}break;
							case '2':
							{
								cout << "����" << '\t' << "ѧ��" << '\t' << "΢����" << '\t' << "Ӣ��" << '\t' << "����" << '\t' << "����" << '\t' << "�������" << '\t' << "�ܼ���" << endl;
								cout << Link << endl; system("pause");
							}break;
							case '3':
							{
								stu = NewStudent();
								cout << "----�½���ϣ��Ƿ�Ҫ������ӣ�y/n��----" << endl;
								if (Retry())
								{
									cout << "----�����----" << endl;
									Link.Append(stu);
									cout << "----������----" << endl;
									system("pause");
								}
								else { cout << "----��ȡ�����----" << endl; system("pause"); }
							}break;
							case '4':
							{
								a->Return().SetPassword();
								system("pause");
							}break;
							}
						} while (true);	
						
					}
					else if (a == NULL) {
					cout << "������˺���Ч���Ƿ�������ԣ�y/n��" << endl;
					n = Retry();
					}
				} while (n);
			}while (n);
		}
	}
    LLink.Save(filename.c_str());
	return 0;
}

