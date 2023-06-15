#include "Tree_Link.h"
int main()
{
	LinkTree<char> tmp;
	tmp.Test();
	cout << tmp.GetDegree() << endl;
	cout << tmp.GetHeight() << endl;
	cout << tmp.GetLeafNode() << endl;
	return 0;
}