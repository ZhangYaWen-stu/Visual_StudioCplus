#include "Tree.h"
void Read(const char &temp)
{
	cout << temp;
}

int main()
{
	/*BinaryTree<char> tree;
	char key;
	int flag = -1;
	char tmp;
	while (true)
	{
		cout << "\t\t\t=====================================" << endl;
		cout << "\t\t\t|===================================|" << endl;
		cout << "\t\t\t|                                   |" << endl;
		cout << "\t\t\t|#1-------建立默认二叉树            |" << endl;
		cout << "\t\t\t|#2-------建立二叉树                |" << endl;
		cout << "\t\t\t|#3-------非递归中序遍历二叉树      |" << endl;
		cout << "\t\t\t|#4-------输出现有树叶子节点的个数  |" << endl;
		cout << "\t\t\t|#5-------退出程序                  |" << endl;
		cout << "\t\t\t|                                   |" << endl;
		cout << "\t\t\t=====================================" << endl;
		cin >> key;
		while ((tmp = getchar()) != '\n' && tmp != EOF);
		if(key=='5')
			break;
		switch (key)
		{
		case '1':tree.TestTreeChar(); cout << "已建立默认测试用二叉树" << endl; break;
		case '2':tree.CreateBinaryTree(); break;
		case '3':cout << "非递归中序遍历二叉树的结果："; tree.InOrderNonRec(Read); cout << endl; break;
		case '4':cout << "现有二叉树叶子节点的个数为" << tree.LeafNode() << endl; break;
		}
		while ((tmp = getchar()) != '\n' && tmp != EOF);
		system("pause");
		system("CLS");
	}*/
	BinaryTree<int> t;
	t.TestTreeInt();
	cout << t.IsBinarySortTree() << endl;
	return 0;
}

