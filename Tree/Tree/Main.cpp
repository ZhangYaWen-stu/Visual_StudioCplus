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
		cout << "\t\t\t|#1-------����Ĭ�϶�����            |" << endl;
		cout << "\t\t\t|#2-------����������                |" << endl;
		cout << "\t\t\t|#3-------�ǵݹ��������������      |" << endl;
		cout << "\t\t\t|#4-------���������Ҷ�ӽڵ�ĸ���  |" << endl;
		cout << "\t\t\t|#5-------�˳�����                  |" << endl;
		cout << "\t\t\t|                                   |" << endl;
		cout << "\t\t\t=====================================" << endl;
		cin >> key;
		while ((tmp = getchar()) != '\n' && tmp != EOF);
		if(key=='5')
			break;
		switch (key)
		{
		case '1':tree.TestTreeChar(); cout << "�ѽ���Ĭ�ϲ����ö�����" << endl; break;
		case '2':tree.CreateBinaryTree(); break;
		case '3':cout << "�ǵݹ���������������Ľ����"; tree.InOrderNonRec(Read); cout << endl; break;
		case '4':cout << "���ж�����Ҷ�ӽڵ�ĸ���Ϊ" << tree.LeafNode() << endl; break;
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

