#include "mystring.h"
using namespace std;
MyString::MyString()
{
    this->str = NULL;
    this->size = 0;
    cout << "***********�˴�ִ���޲ι���" << endl;
}

MyString::MyString(const char* temp)
{
    cout << "***********�˴�ִ���вι���" << endl;
    this->str = new char[strlen(temp) + 1];
    strcpy(this->str, temp);
    this->size = strlen(str);
}
MyString::MyString(const MyString& ob)
{
    cout << "***********�˴�ִ�п�������" << endl;
    if (str != NULL)
        delete[]str;
    this->str = new char[strlen(ob.str) + 1];
    strcpy(this->str, ob.str);
    this->size = ob.size;
}

MyString::~MyString()
{

    if (this->str != NULL)
    {
        delete []str;
        this->str = NULL;
    }
    cout << "***********�˴�ִ����������" << endl;
}

int MyString::Size()
{
    return this->size;
}

char& MyString::operator[](int i)
{
    cout << "***********�˴�ִ�������[]����" << endl;
    if (i >= 0 && i < this->size)
        return (this->str)[i];
    else
        throw("�±���Ч");
}

MyString& MyString::operator =(const MyString& ob)
{
    //�Ƚ�this->str�ľɿռ��ͷŵ�
    if (this->str != NULL)
    {
        delete []str;
        this->str = NULL;
    }
    str = new char[strlen(ob.str) + 1];
    strcpy(str, ob.str);
    this->size = strlen(ob.str);
    cout << "***********�˴�ִ�и�ֵ����/�����=����" << endl;
    return *this;
}

MyString& MyString::operator+(const MyString& ob)
{
    int tmp_size = strlen(this->str) + strlen(ob.str) + 1;
    char* tmp = new char[tmp_size];
    strcpy(tmp, this->str);
    strcat(tmp, ob.str);
    MyString s(tmp);
    if (strcmp(s.str, tmp) != 0)//����s�����е�ֵ
        strcpy(s.str, tmp);
    if (tmp != NULL)//��ʱ�ͷŶ�������Ŀռ�
    {
        delete []tmp;
        tmp = NULL;
    }
    cout << "***********�˴�ִ�������+����" << endl;
    return s;
}
MyString& MyString::operator+(const char* str)
{
    int tmp_size = strlen(this->str) + strlen(str) + 1;
    char* tmp = new char[tmp_size];
    strcpy(tmp, this->str);
    strcat(tmp, str);
    static MyString s(tmp);
    if (strcmp(s.str, tmp) != 0)
        strcpy(s.str, tmp);
    if (tmp != NULL)
    {
        delete []tmp;
        tmp = NULL;
    }
    cout << "***********�˴�ִ�������+����" << endl;
    return s;
}
bool MyString::operator==(const MyString& ob)
{
    cout << "***********�˴�ִ�������==����" << endl;
    if ((strcmp(this->str, ob.str) == 0))
        return true;
    else
        return false;
}

bool MyString::operator==(const char* str)
{
    cout << "***********�˴�ִ�������==����" << endl;
    if ((strcmp(this->str, str) == 0))
        return true;
    else
        return false;
}
bool MyString::operator!=(const MyString& ob)
{
    cout << "***********�˴�ִ�������!=����" << endl;
    if ((strcmp(this->str, ob.str) == 0))
        return false;
    else
        return true;
}

bool MyString::operator!=(const char* str)
{
    cout << "***********�˴�ִ�������!=����" << endl;
    if ((strcmp(this->str, str) == 0) && (this->size == strlen(str)))
        return false;
    else
        return true;
}

ostream& operator<<(ostream& out, MyString& ob)
{
    out << ob.str;
    cout << "\n***********�˴�ִ�������<<����" << endl;
    return out;
}

istream& operator>>(istream& in, MyString& ob)
{
    //�ǵý�ԭ�����ݲ���
    if (ob.str != NULL)
    {
        delete []ob.str;
        ob.str = NULL;
    }
    char buf[1024] = "";//��ʱbuf
    in.getline(buf, 1024);//�ȵõ�������������� Ȼ�����buf��ʵ�ʴ�С���ٿռ䣬����1023���һλ��\0
    ob.str = new char[strlen(buf) + 1];
    strcpy(ob.str, buf);
    ob.size = strlen(buf);
    cout << "\n***********�˴�ִ�������>>����" << endl;
    return in;
}
