#include<Jieba.hpp>
#include<iostream>
using namespace std;
int main()
{
	Jieba jieba("jieba");
	jieba.Cut("�������Ǹ�������", hmm =1);
	return 0;
}