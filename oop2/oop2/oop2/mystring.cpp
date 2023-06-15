#include "mystring.h"
using namespace std;
MyString::MyString()
{
    this->str = NULL;
    this->size = 0;
    cout << "***********此处执行无参构造" << endl;
}

MyString::MyString(const char* temp)
{
    cout << "***********此处执行有参构造" << endl;
    this->str = new char[strlen(temp) + 1];
    strcpy(this->str, temp);
    this->size = strlen(str);
}
MyString::MyString(const MyString& ob)
{
    cout << "***********此处执行拷贝构造" << endl;
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
    cout << "***********此处执行析构函数" << endl;
}

int MyString::Size()
{
    return this->size;
}

char& MyString::operator[](int i)
{
    cout << "***********此处执行运算符[]重载" << endl;
    if (i >= 0 && i < this->size)
        return (this->str)[i];
    else
        throw("下标无效");
}

MyString& MyString::operator =(const MyString& ob)
{
    //先将this->str的旧空间释放掉
    if (this->str != NULL)
    {
        delete []str;
        this->str = NULL;
    }
    str = new char[strlen(ob.str) + 1];
    strcpy(str, ob.str);
    this->size = strlen(ob.str);
    cout << "***********此处执行赋值函数/运算符=重载" << endl;
    return *this;
}

MyString& MyString::operator+(const MyString& ob)
{
    int tmp_size = strlen(this->str) + strlen(ob.str) + 1;
    char* tmp = new char[tmp_size];
    strcpy(tmp, this->str);
    strcat(tmp, ob.str);
    MyString s(tmp);
    if (strcmp(s.str, tmp) != 0)//更新s变量中的值
        strcpy(s.str, tmp);
    if (tmp != NULL)//及时释放堆区申请的空间
    {
        delete []tmp;
        tmp = NULL;
    }
    cout << "***********此处执行运算符+重载" << endl;
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
    cout << "***********此处执行运算符+重载" << endl;
    return s;
}
bool MyString::operator==(const MyString& ob)
{
    cout << "***********此处执行运算符==重载" << endl;
    if ((strcmp(this->str, ob.str) == 0))
        return true;
    else
        return false;
}

bool MyString::operator==(const char* str)
{
    cout << "***********此处执行运算符==重载" << endl;
    if ((strcmp(this->str, str) == 0))
        return true;
    else
        return false;
}
bool MyString::operator!=(const MyString& ob)
{
    cout << "***********此处执行运算符!=重载" << endl;
    if ((strcmp(this->str, ob.str) == 0))
        return false;
    else
        return true;
}

bool MyString::operator!=(const char* str)
{
    cout << "***********此处执行运算符!=重载" << endl;
    if ((strcmp(this->str, str) == 0) && (this->size == strlen(str)))
        return false;
    else
        return true;
}

ostream& operator<<(ostream& out, MyString& ob)
{
    out << ob.str;
    cout << "\n***********此处执行运算符<<重载" << endl;
    return out;
}

istream& operator>>(istream& in, MyString& ob)
{
    //记得将原有数据擦除
    if (ob.str != NULL)
    {
        delete []ob.str;
        ob.str = NULL;
    }
    char buf[1024] = "";//临时buf
    in.getline(buf, 1024);//先得到键盘输入的数据 然后根据buf的实际大小开辟空间，最多读1023最后一位补\0
    ob.str = new char[strlen(buf) + 1];
    strcpy(ob.str, buf);
    ob.size = strlen(buf);
    cout << "\n***********此处执行运算符>>重载" << endl;
    return in;
}
