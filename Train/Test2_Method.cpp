#include "Test2_Method.h"
void Init(student*& head)
{
	int a[] = { 1,2,3,4,5,6,7 };
	int n = sizeof(a) / sizeof(*a);
	Create(head, n, a);
}
void Create(student *&head, int n, int *a)
{
	int i;
	student* temp;
	temp = new student;
	head = temp;
	for (i = 0; ; i++)
	{
		temp->id = a[i];
		if (i == n - 1)
		{
			temp->next = NULL;
			break;
		}
		temp->next = new student;
		temp = temp->next;
	}
}
int NumNodes(student* head)
{
	int num=0;
	for (; head!=NULL; head = head->next, num++);
	return num;
}
int ShowList(student* head)
{
	int num = NumNodes(head);
	int i;
	for (i = 0; i < num; head=head->next,i++)
	{
		cout << head->id << endl;
	}
	return num;
}
student* Insert(student*& head, int x)
{
	student* temp;
	temp = new student;
	temp->id=x;
	temp->next = head;
	head = temp;
	return temp;
}
student* Append(student* head, int x)
{
	student* temp;
	temp = new student;
	temp->id = x;
	temp->next = NULL;
	for (;; head = head->next)
	{
		if (head->next == NULL)
		{
			head->next = temp;
			break;
		}
	}
	return temp;
}
void FreeList(student*& head)
{
	student* p;
	for (;; )
	{
		p = head;
		head = head->next;
		delete p;
		if (head == NULL)
			break;
	}
}