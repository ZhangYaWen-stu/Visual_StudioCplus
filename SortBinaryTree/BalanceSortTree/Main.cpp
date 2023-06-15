#include "BalanceTree.h"
void Read(const char& temp)
{
	cout << temp;
}

int main()
{
	BinarySortTree<int> a;
	a.InsertNode(5);
	a.InsertNode(2);
	a.InsertNode(7);
	a.InsertNode(3);
	a.InsertNode(6);
	cout << a.Find(3) << endl;
	a.DelNode(3);
	cout << a.Find(3) << endl;
	cout << a.Find(7) << endl;
	cout << a.Findk(3)->data << endl;
	return 0;
}

