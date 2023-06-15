#include "Student.h"
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

Student::Student(double a, double b, double c, double d, double e , string g , string h , string p ) :calculus(a), english(b), pe(c), physics(d), programming(e), name(g), id(h), password(p)
{
	transform(calculus);
	transform(english);
	transform(pe);
	transform(physics);
	transform(programming);
	Score();
}

istream& operator>>(istream& in,Student &stu)
{
	char str[80];
	in.getline(str,80,'\t');stu.name = str;
	in.getline(str, 80, '\t');stu.id = str;
	in.getline(str, 80, '\t'); istringstream string_to1(str); string_to1>>stu.calculus ;
	in.getline(str, 80, '\t'); istringstream string_to2(str); string_to2 >> stu.english ;
	in.getline(str, 80, '\t'); istringstream string_to3(str); string_to3 >> stu.pe;
	in.getline(str, 80, '\t'); istringstream string_to4(str); string_to4 >> stu.physics;
	in.getline(str, 80, '\t'); istringstream string_to5(str); string_to5 >> stu.programming;
	in.getline(str, 80,'\t'); istringstream string_to6(str); string_to6 >> stu.score;
	in.getline(str, 80);stu.password = str;
	return in;
}
ostream& operator<<(ostream& out,Student &stu)
{
	out << fixed << setprecision(2) << stu.name << '\t' << stu.id << "\t" << stu.calculus << '\t' << stu.english << '\t' << stu.pe << '\t' << stu.physics << '\t' << stu.programming << '\t' << stu.score <<'\t'<<stu.password ;
	return out;
}
bool Student::VerifyPassword()
{
	string Password;
	do {
		cout << "请输入密码：";
		cin>>Password;
		cout << "-----正在验证中-----" << endl;
		if (Password == password)
		{
			cout << "-----密码正确-----" << endl;
			return true;
		}
		cout << "-----密码错误-----" << endl;
		cout << "是否重试（y/n）" << endl;
	} while (Retry());
	cout << "----已退出----" << endl;
	system("pause");
	return false;
}
void Student::SetPassword()
{
	string Password;
	do {
		cout << "请输入原密码：";
		cin >> Password;
		cout << "-----正在验证中-----" << endl;
		if (Password == password)
		{
			cout << "密码正确，请输入新密码：";
			cin >> password;
			cout << "-----设置成功-----" << endl;
			break;
		}
		cout << "是否重试（y/n）" << endl;
	} while (Retry());
}
bool Student::operator>(Student stu)
{
	return (score > stu.score ? true : false);
}

bool Student::operator<(Student stu)
{
	return (score < stu.score ? true : false);
}

bool operator!=(Student& stu1,Student& stu2)
{
	if (stu1.name != stu2.name && stu1.id != stu2.id)
		return true;
	else return false;
}
void Student::transform(double &n)
{
	if (n >= 90) n = 4.0;
	else if (n >= 85) n = 3.7;
	else if (n >= 82) n = 3.3;
	else if (n >= 78) n = 3.0;
	else if (n >= 75) n = 2.7;
	else if (n >= 72) n = 2.3;
	else if (n >= 68) n = 2.0;
	else if (n >= 66) n = 1.7;
	else if (n >= 64) n = 1.5;
	else if (n >= 60) n = 1.0;
	else n = 0.0;
}

void Student::Set(double x, int n)
{
	transform(x);
	switch (n)
	{
	case 1:calculus = x; Score(); break;
	case 2:english = x; Score(); break;
	case 3:pe = x; Score(); break;
	case 4:physics = x; Score(); break;
	case 5:programming = x; Score(); break;
	}
}
void Student::Set(string x, int n)
{
	switch (n)
	{
	case 7:name = x; break;
	case 8:id = x; break;
	case 9:password = x; break;
	}
}
void Student::Show()
{
	cout<<"姓名" << '\t' << "学号" << '\t' << "微积分" << '\t' << "英语" << '\t' << "体育" << '\t' << "物理" << '\t' << "程序设计" << '\t' << "总绩点" << endl;
	cout << fixed << setprecision(2) << name << '\t' << id << '\t' << calculus << '\t' << english << '\t' << pe << '\t' << physics << '\t' << programming << '\t' << score << endl;
}
void Student::Score()
{
	score = calculus * 6 / 19 + english * 4 / 19 + pe * 1 / 19 + physics * 4 / 19 + programming * 4 / 19;
}
