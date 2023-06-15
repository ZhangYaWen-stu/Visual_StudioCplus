#include"DBL.h"
template<typename ElemType>
void Swap(ElemType* a, ElemType* b)
{
	ElemType tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

template<typename ElemType>
void ShakerSort(ElemType e[], int n)
{
	if (n <= 0)
		throw FAIL;
	for (int start = 0, end = n - 1; start < end; start++, end--)
	{
		for (int i = start; i < end ; i++)
			if (e[i] > e[i + 1])
				Swap(&e[i], &e[i + 1]);
		for (int i = end - 1; i > start; i--)
			if (e[i] < e[i - 1])
				Swap(&e[i], &e[i - 1]);
	}
}

int main()
{
	LinkList<int> a;
	int b[] = { 7,4,9,11,26,15,31,6 };
	int length = sizeof(b) / sizeof(int);
	ShakerSort(b, length);
	for (int i = 0; i < length; i++)
		cout << b[i] << endl;
	a.Append(7);
	a.Append(4);
	a.Append(9);
	a.Append(11);
	a.Append(26);
	a.Append(15);
	a.Append(31);
	a.Append(6);
	a.QuickSort();
	cout << a;
	return 0;
}