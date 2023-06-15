#include"Vector.h"
template<typename T>
Vector<T>::Vector(int dimension)
{
	Dim = dimension;
	if (!dimension)
		Data = NULL;
	else {
		Data = new T[dimension];
		for (int i = 0; i < dimension; i++)
			*(Data + i) = 0;
	}
}

template<typename T>
Vector<T>::Vector(T* temp,int d)
{
	if (temp == NULL)
	{
		Dim = 0;
		Data = NULL;
	}
	else
	{
		Dim = d;
		Data = new T[Dim];
		for (int i = 0; i < Dim; i++)
			*(Data + i) = *(temp + i);
	}	
}

template<typename T>
Vector<T>::Vector(Vector<T>& temp)
{
	Dim = temp.Dim;
	Data = NULL;
	if (Dim)
	{
		Data = new T[Dim];
		for(int i=0;i<Dim;i++)
			*(Data + i) = *(temp.Data + i);
	}
}

template<typename T>
Vector<T>::~Vector()
{
	delete[]Data;
	Data = NULL;
}

template<typename T>
int Vector<T>::type()
{
	string c(typeid(char).name());
	string flag(typeid(T).name());
	if (flag == c)
		return 1;
	else return 0;
}
template<typename T>
void Vector<T>::push_back(const T& x)
{
	int d = Dim++;
	T* temp = Data;
	Data = new T[Dim];
	for (int i = 0; i < d; i++)
		*(Data + i) = *(temp + i);
	*(Data + d) = x;
	delete[]temp;
}

template<typename T>
void Vector<T>::pop_back()
{
	if (!Dim)
		throw execption("==向量为空 不能进行此操作==");
	T* temp = Data;
	if (Dim > 1)
	{
		Data = new T[--Dim];
		for (int i = 0; i < Dim; i++)
			*(Data + i) = *(temp + i);
		delete[]temp;
	}
	else clear();
}

template<typename T>
void Vector<T>::clear()
{
	if (Dim)
	{
		Dim = 0;
		delete[]Data;
		Data = NULL;
	}
}

template<typename T>
T& Vector<T>::at(int pos)
{
	if (pos < 0 || pos >= Dim)
		throw execption("====下标溢出====");
	return *(Data + pos);
}

template<typename T>
T& Vector<T>::front()
{
	if (Dim == 0)
		throw execption("==向量为空 不能进行此操作==");
	else return *(Data);
}

template<typename T>
T& Vector<T>::back()
{
	if (Dim == 0)
		throw execption("==向量为空 不能进行此操作==");
	else return *(Data+Dim-1);
}

template<typename T>
T* Vector<T>::begin()
{
	if (Dim == 0)
		throw execption("==向量为空 不能进行此操作==");
	else return Data;
}
template<typename T>
T* Vector<T>::end()
{
	if (Dim == 0)
		throw execption("==向量为空 不能进行此操作==");
	else return Data+Dim-1;
}

template<typename T>
bool Vector<T>::empty() const
{
	if (Dim)
		return false;
	else return true;
}

template<typename T>
int Vector<T>::GetDim()
{
	return Dim;
}

template<typename T>
void Vector<T>::swap(Vector<T>& temp)
{
	Vector<T> temp1(temp);
	if(temp.Dim)
		delete[]temp.Data;
	temp.Data = NULL;
	temp.Dim = Dim;
	if(temp.Dim)
	{
		temp.Data = new T[temp.Dim];
		for (int i = 0; i < temp.Dim; i++)
			*(temp.Data + i) = *(Data + i);
	}
	delete[]Data;
	Data = NULL;
	Dim = temp1.Dim;
	if (Dim)
	{
		Data = new T[Dim];
		for (int i = 0; i < Dim; i++)
			*(Data + i) = *(temp1.Data + i);
	}
}

template<typename T>
void Vector<T>::erase(int head, int end)
{
	int i = 0,j;
	if (head<0 || head>end || head == end||end<0||head>Dim-1||end>Dim-1)
		throw execption("====下标溢出====");
	T* temp = Data;
	int length = end - head;
	Dim = Dim - length;
	Data = new T[Dim];
	for (; i < head; i++)
		*(Data + i) = *(temp + i);
	for (j=end; i < Dim+length; j++,i++)
		*(Data + i) = *(temp + j);
}

template<typename T>
void Vector<T>::assign(int n, T x)
{
	if (n<0 || n>Dim - 1)
		throw execption("====下标溢出====");
	*(Data + n) = x;
}

template<typename T>
void Vector<T>::reverse()
{
	int head, end;
	T x;
	for (head = 0, end = Dim - 1; head < end; head++, end--)
	{
		x = *(Data + head);
		*(Data + head) = *(Data + end);
		*(Data + end) = x;
	}
}

template<typename T>
void Vector<T>::insert(int pos, T temp)
{
	if (pos<0 || pos>Dim - 1)
		throw execption("====下标溢出====");
	T* temp1 = Data;
	Data = new T[++Dim];
	int i=0;
	for (; i < pos; i++)
		*(Data + i) = *(temp1 + i);
	*(Data + i) = temp;
	for (i+=1; i < Dim; i++)
		*(Data + i) = *(temp1 + i-1);
}

template<typename T>
Vector<T> Vector<T>::resize(int dimension,int d, T* temp)
{
	if (dimension <= 0)
		throw 6;
	int t = d,total,i=0;
	total = t + Dim;
	T* temp1 = Data;
	Data = new T[dimension];
	if (total <= dimension)
	{
		for(;i<Dim;i++)
			*(Data + i) = *(temp1 + i);
		for (; i < total; i++)
			*(Data + i) = *(temp + i-Dim);
		for (; i < dimension; i++)
			*(Data + i) = 0;	
	}
	else
	{
		if(Dim>dimension)
			for (; i < dimension; i++)
				*(Data + i) = *(temp1 + i);
		else
		{
			for (; i < Dim; i++)
				*(Data + i) = *(temp1 + i);
			for (; i < dimension; i++)
				*(Data + i) = *(temp + i - Dim);
		}
	}
	Dim = dimension;
	delete[]temp1;
	return *this;
}

template<typename T>
T Vector<T>::operator[](int index)
{
	if (index < 0 || index >= Dim)
		throw execption("====下标溢出====");
	return *(Data + index);
}

template<typename T>
Vector<T> Vector<T>::operator=(const Vector<T> &temp)
{
	Dim = temp.Dim;
	if (Data != NULL)
		delete[]Data;
	Data = NULL;
	if (Dim)
	{
		Data = new T[Dim];
		for (int i = 0; i < Dim; i++)
			*(Data + i) = *(temp.Data + i);
	}
	return *this;
}

template<typename T>
bool Vector<T>::operator!=(Vector<T> temp)
{
	if (Dim != temp.Dim)
		return true;
	if (Dim == temp.Dim)
	{
		for (int i = 0; i < Dim; i++)
			if (*(Data + i) != *(temp.Data + i))
				return true;
		return false;
	}
}

template<typename T>
bool Vector<T>::operator==(Vector<T> temp)
{
	if (Dim != temp.Dim)
		return false;
	else
	{
		for (int i = 0; i < Dim; i++)
			if (*(Data + i) != *(temp.Data + i))
				return false;
		return true;
	}
}

template<typename T>
ostream& operator<<(ostream& out,Vector<T> v)
{
	int i;
	out << "[";
	for (i = 0; i < v.Dim - 1; i++)
		out << v[i] << ",";
	if (i == v.Dim - 1)
		out << v[i];
	out << "]";
	return out;
}
template<typename T>
Vector<T> Vector<T>::operator+(const Vector<T> &temp)
{
	if (Dim != temp.Dim)
		throw execption("====维数不同 无法进行此操作====");
	if (type())
		throw execption("====向量类型错误 无法进行此操作====");
	Vector<T> temp1;
	temp1.Dim = Dim;
	if (Dim)
	{
		temp1.Data = new T[Dim];
		for (int i = 0; i < Dim; i++)
			*(temp1.Data + i) = *(Data + i) + *(temp.Data + i);
	}
	return temp1;
}

template<typename T>
Vector<T> Vector<T>::operator-(const Vector<T> &temp)
{
	if (Dim != temp.Dim)
		throw execption("====维数不同 无法进行此操作====");
	if (type())
		throw execption("====向量类型错误 无法进行此操作====");
	Vector<T> temp1;
	temp1.Dim = Dim;
	if (Dim)
	{
		temp1.Data = new T[Dim];
		for (int i = 0; i < Dim; i++)
			*(temp1.Data + i) = *(Data + i) - *(temp.Data + i);
	}
	return temp1;
}

template<typename T>
T Vector<T>::operator*(Vector<T> temp)
{
	if (Dim != temp.Dim)
		throw execption("====维数不同 无法进行此操作====");
	if (type())
		throw execption("====向量类型错误 无法进行此操作====");
	T model=0;
	for (int i = 0; i < Dim; i++)
		model += ( * (Data + i)) * (*(temp.Data + i));
	return model;
}