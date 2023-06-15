#include "BinarySortTree.h"
void Read(const char& temp)
{
	cout << temp;
}

int main()
{
	BinarySortTree<int> b;
	b.InsertNode(2);
	b.InsertNode(4);
	b.InsertNode(1);
	b.InsertNode(0);
	b.InsertNode(5);
	b.InsertNode(7);
	cout << b.Find(3) << endl;
	cout << b.Find(0) << endl;
	b.DelNode(0);
	cout << b.Find(0) << endl;
	b.Findx(3);
	return 0;
}

