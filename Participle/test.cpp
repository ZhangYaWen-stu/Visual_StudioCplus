#include<Jieba.hpp>
#include<iostream>
using namespace std;
int main()
{
	Jieba jieba("jieba");
	jieba.Cut("今天真是个好天气", hmm =1);
	return 0;
}