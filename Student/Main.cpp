#include"Main.h"
Student NewStudent()
{
	system("CLS");
	Student stu;
	double temp;
	string p;
	cout << "请输入新学生的姓名:";
	cin >> p;
	stu.Set(p, 7);
	cout << "请输入新学生的学号:";
	cin >> p;
	stu.Set(p, 8);
	cout << "请输入新学生的微积分成绩:";
	cin >> temp;
	stu.Set(temp, 1);
	cout << "请输入新学生的英语成绩:";
	cin >> temp;
	stu.Set(temp, 2);
	cout << "请输入新学生的体育成绩:";
	cin >> temp;
	stu.Set(temp, 3);
	cout << "请输入新学生的物理成绩:";
	cin >> temp;
	stu.Set(temp, 4);
	cout << "请输入新学生的程序设计成绩:";
	cin >> temp;
	stu.Set(temp, 5);
	return stu;
}
Node<Student>* FindID(LinkList<Student>& Link)
{
	Node<Student>* goal;
	Student stu;
	string ID;
	cout << "请输入您想查找学生的学号:";
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
	cout << "请输入您要查找的学生姓名:";
	cin >> name;
	stu.Set(name, 7);
	do
	{
		if (goal = Link.Locate(stu, flag))
		{
			cout << "该生信息为:\n"; goal->Return().Show();
			cout << "----该生是否为您所查找的学生(y/n)----" << endl;
			k = Retry();
			flag = false;
			if (k)
				break;
			cout << "----继续查找----" << endl;
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
	cout << "\t\t|=========请选择您要修改的科目=========|" << endl;
	cout << "\t\t|1-----微积分                          |" << endl;
	cout << "\t\t|2-----英语                            |" << endl;
	cout << "\t\t|3-----体育                            |" << endl;
	cout << "\t\t|4-----物理                            |" << endl;
	cout << "\t\t|5-----程序设计                        |" << endl;
	cout << "\t\t|0-----返回上级(ESC)                   |" << endl;
	cout << "\t\t========================================" << endl;
	key = Key("012345\x1b");
	if (key == '0' || key == '\x1b')
		return;
	cout << "请输入您想要修改为:";
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
		cout << "\t\t|=====模式选择====  |" << endl;
		cout << "\t\t|1-----学生模式     |" << endl;
		cout << "\t\t|2-----管理员模式   |" << endl;
		cout << "\t\t|0-----退出程序(Esc)|" << endl;
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
					cout << "请输入您的学号：";
					cin >> ID;
					temp.Set(ID, 8);
					t = 0;
					if ((s = Link.Locate(temp, true)) && (s->Return().VerifyPassword()))
					{
						do {
							system("CLS");
							cout << "\n\t\t=============================" << endl;
							cout << "\t\t|==========功能选择=========|" << endl;
							cout << "\t\t|1-----查询成绩             | " << endl;
							cout << "\t\t|2-----查询排名             |" << endl;
							cout << "\t\t|3-----更改密码             |" << endl;
							cout << "\t\t|0-----返回模式选择(ESC)    |" << endl;
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
									cout << "该生排名为第" << s->Rate(Link) << "名" << endl; system("pause");
								}break;
							case '3':
								{
									s->Return().SetPassword(); system("pause");
								}break;
							}
						} while (true);
					}
					else if(s==NULL){
						cout << "输入的学号无效，是否进行重试（y/n）" << endl;
						t = Retry();
					}
				} while (t);

			} while (t);
			break;
		case '2':
			do
			{
				do {
					cout << "请输入您的账号:" ;
					cin >> ID;
					temp.Set(ID, 8);
					n = 0;
					if ((a = ALink.Locate(temp, true)) && a->Return().VerifyPassword())
					{
						do 
						{
							system("CLS");
							cout << "\n\t\t============================" << endl;
							cout << "\t\t|===========功能选择=======|" << endl;
							cout << "\t\t|1-----查找学生            |" << endl;
							cout << "\t\t|2-----查看学生信息        |" << endl;
							cout << "\t\t|3-----添加学生信息        |" << endl;
							cout << "\t\t|4-----更改管理员密码      |" << endl;
							cout << "\t\t|0-----返回模式选择(Esc)   |" << endl;
							cout << "\t\t============================" << endl;
							key = Key("01234\x1b");
							if (key == '0' || key == '\x1b')
								break;
							switch (key) {
							case '1':
							{
								system("CLS");
								cout << "\n\t\t=============================" << endl;
								cout << "\t\t|==========查找条件=========|" << endl;
								cout << "\t\t|1-----学号                 |" << endl;
								cout << "\t\t|2-----姓名                 | " << endl;
								cout << "\t\t|0-----返回功能选择(Esc)    |" << endl;
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
												cout << "\t\t|=========你想要进行的操作========|" << endl;
												cout << "\t\t|1-----查询成绩                   |" << endl;
												cout << "\t\t|2-----查询排名                   |" << endl;
												cout << "\t\t|3-----更改该生成绩               |" << endl;
												cout << "\t\t|4-----更改该生密码               |" << endl;
												cout << "\t\t|5-----删除该生信息               |" << endl;
												cout << "\t\t|0-----返回上一级(Esc)            |" << endl;
												cout << "\t\t===================================" << endl;
												key = Key("012345\x1b");
												if (key == '0' || key == '\x1b')
												{
													t = 0;
													break;
												}
												switch (key) {
												case '1':s->Return().Show(); system("pause"); break;
												case '2':cout << "该生排名为第" << s->Rate(Link) << "名" << endl; system("pause"); break;
												case '3':Grade(s); system("pause"); break;
												case '4':cout << "请输入新密码:"; cin >> Password; s->Return().Set(Password, 9); system("pause"); break;
												case'5':cout << "是否进行删除(y/n)" << endl; if (Retry()) {
													Link.DeleteCurNode(); t = 0; cout << "----已删除----" << endl; system("pause");
												} break;
													if (t == 1) { cout << "----是否继续对该生的操作(y/n)----" << endl; t = Retry(); }
												}
											} while (true && t);
										}
										else {
											cout << "----未查找到该生信息，是否重试(y/n)----" << endl;
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
												cout << "\t\t|=========你想要进行的操作========|" << endl;
												cout << "\t\t|1-----查询成绩                   |" << endl;
												cout << "\t\t|2-----查询排名                   |" << endl;
												cout << "\t\t|3-----更改该生成绩               |" << endl;
												cout << "\t\t|4-----更改该生密码               |" << endl;
												cout << "\t\t|5-----删除该生信息               |" << endl;
												cout << "\t\t|0-----返回上一级(Esc)            |" << endl;
												cout << "\t\t===================================" << endl;
												key = Key("012345\x1b");
												if (key == '0' || key == '\x1b')
												{
													t = 0;
													break;
												}
												switch (key) {
												case '1':s->Return().Show(); system("pause"); break;
												case '2':cout << "该生排名为第" << s->Rate(Link) << "名" << endl; system("pause"); break;
												case '3':Grade(s); break;
												case '4':cout << "请输入新密码:"; cin >> Password; s->Return().Set(Password, 9); system("pause"); break;
												case'5':cout << "是否进行删除(y/n)" << endl; if (Retry()) {
													Link.DeleteCurNode(); t = 0; cout << "----已删除----" << endl; system("pause");
												} break;
													if (t == 1) { cout << "----是否继续对该生的操作(y/n)----" << endl; t = Retry(); }
												}
											} while (true && t);
										}
										else {
											cout << "----未查找到该生信息，是否重试(y/n)----" << endl;
											t = Retry();
										}
									} while (true && t);
								}break;


							}break;
							case '2':
							{
								cout << "姓名" << '\t' << "学号" << '\t' << "微积分" << '\t' << "英语" << '\t' << "体育" << '\t' << "物理" << '\t' << "程序设计" << '\t' << "总绩点" << endl;
								cout << Link << endl; system("pause");
							}break;
							case '3':
							{
								stu = NewStudent();
								cout << "----新建完毕，是否要进行添加（y/n）----" << endl;
								if (Retry())
								{
									cout << "----添加中----" << endl;
									Link.Append(stu);
									cout << "----添加完毕----" << endl;
									system("pause");
								}
								else { cout << "----已取消添加----" << endl; system("pause"); }
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
					cout << "输入的账号无效，是否进行重试（y/n）" << endl;
					n = Retry();
					}
				} while (n);
			}while (n);
		}
	}
    LLink.Save(filename.c_str());
	return 0;
}

