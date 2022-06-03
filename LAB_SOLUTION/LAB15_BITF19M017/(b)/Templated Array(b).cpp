#include<iostream>

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
	int getSize();
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
int MyArray<Any>::getSize()
{
	return size;
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

template <class Any>
void Sort(MyArray<Any>& anyarray)
{
	for (int i = 0; i < anyarray.getSize(); i++)
	{
		Any value = anyarray[i];
		for (int j = i + 1; j < anyarray.getSize(); j++)
		{
			Any value2 = anyarray[j];
			if (value > value2)
			{
				Any temp = anyarray[i];
				anyarray[i] = temp;
				anyarray[i] = anyarray[j];
				anyarray[j] = temp;
			}
		}
	}
}

int main()
{
	MyArray<double> anyarr(10);

	anyarr.addElement(123);
	anyarr.addElement(15.1);
	anyarr.addElement(431.3);
	anyarr.addElement(346);
	anyarr.addElement(-123.5);
	anyarr.addElement(-12.4);
	anyarr.addElement(0);
	anyarr.addElement(10.1);
	anyarr.addElement(-103.3);
	anyarr.addElement(87);

	for (int i = 0; i < 10; i++)
		cout << anyarr[i] << ", ";

	cout << "\b\b" << endl << endl;
	Sort(anyarr);


	cout << "After sort:" << endl;

	for (int i = 0; i < 10; i++)
		cout << anyarr[i] << ", ";

	cout << "\b\b";
	return 0;

}