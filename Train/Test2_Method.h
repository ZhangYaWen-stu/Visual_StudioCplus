#pragma once
#include<iostream>
using namespace std;
struct student
{
	int id;
	student* next;
};
void Init(student*& head);
void Create(student*& head, int n, int* a);
int NumNodes(student* head);
int ShowList(student* head);
student* Insert(student*& head, int x);
student* Append(student* head, int x);
void FreeList(student*& head);