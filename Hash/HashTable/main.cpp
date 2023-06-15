#include"HashTable.h"
int main()
{
	int b[] = { 1,2,3 };
	HashTable<int> a(b, 3, 2);
	cout << a.Find(0);
	return 0;
}