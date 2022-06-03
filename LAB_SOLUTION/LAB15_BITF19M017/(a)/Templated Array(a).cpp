#include<iostream>
#include"Employee.h"

using namespace std;

template <class Any>
class MyArray
{
	int size;
	int index;
	Any* arr;
public:
	MyArray(int s = 10);
	MyArray(MyArray& myArr);
	//~MyArray();
	void addElement(Any val);
	Any getElement(int i);
	void operator=(const MyArray& myArr);
	Any& operator[](const int& i);
	void Resize(int newsize)
	{
		int presize = this->size;
		Any* newarr = new Any[presize];

		for (int i = 0; i < presize; i++)
		{
			newarr[i] = arr[i];
		}

//		delete[] arr;
		arr = new Any[newsize];
	
		arr = newarr;
		

		this->size = newsize;

		//delete[] newarr;
		newarr = NULL;
	}
};

template <class Any>
MyArray<Any>::MyArray(MyArray& myArr)
{
	cout << "*** Copy Constructor Called ****" << endl;
	size = myArr.size;
	index = myArr.index;
	arr = new Any[size];
	for (int i = 0; i < size; i++)
		arr[i] = myArr.arr[i];
}

template <class Any>
MyArray<Any>::MyArray(int s)
{
	cout << "*** Constructor Called ****" << endl;
	if (s > 0)
	{
		size = s;
		index = 0;
		arr = new Any[size];
		/*for (int i = 0; i < size; i++)
			arr[i] = 0*/;
	}
	else
		cout << "Invalid array size" << endl;
}

//template <class Any>
//MyArray<Any>::~MyArray()
//{
//	delete[]arr;
//	arr = NULL;
//	cout << "~~~ Destructor is Calling . . . ~~~" << endl;
//}

template <class Any>
void MyArray<Any>::addElement(Any val)
{
	if (index < size)
	{
		arr[index] = val;
		index++;
	}
	else
		cout << "Array is full" << endl;
}

template <class Any>
Any MyArray<Any>::getElement(int i)
{
	if (i >= 0 && i < size)
		return arr[i];
	else
	{
		cout << "invalid index" << endl;
		return -1;
	}
}

template <class Any>
void MyArray<Any>::operator=(const MyArray& myArr)
{
	cout << "*** assignment operaoter= called ****" << endl;
	if (arr != NULL)
	{
		delete[]arr;
		arr = NULL;
	}
	size = myArr.size;
	index = myArr.index;
	arr = new Any[size];
	for (int i = 0; i < size; i++)
		arr[i] = myArr.arr[i];
}

template <class Any>
Any& MyArray<Any>::operator[](const int& i)
{
	if (i >= 0 and i < size)
		return arr[i];
	else
	{
		cout << "ERROR!Invalid Index." << endl;
		exit(0);
	}
}

int main()
{
	MyArray <Employee> emparray(3);
	Employee emp;
	char* name = new char;
	char* date = new char;
	cin >> name;
	cin >> date;
	emp.setName(name);
	emp.setDate(date);
	emp.setNum(0);
	for (int i = 0; i < 3; i++)
	{	
		emp.setNum(i);
		emparray[i] = emp;
	}

	for (int i = 0; i < 3; i++)
	{
		emparray[i].display();
	}

	emparray.Resize(6);

	for (int i = 0; i < 6; i++)
	{
		emp.setNum(i);
		emparray[i] = emp;
	}
	for (int i = 0; i < 6; i++)
	{
		emparray[i].display();
	}

	return 0;
}