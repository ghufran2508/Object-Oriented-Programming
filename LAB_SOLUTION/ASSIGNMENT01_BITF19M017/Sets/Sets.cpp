#include<iostream>
#include"Sets.h"

using namespace std;
//Default Constructor...
Set::Set()
{
	//setting size of array 10 by default
	this->size = 10;
	//initially noOfElements would be 0
	this->noOfElements = 0;
	//generating pointer array of size 10
	this->arr = new int[size];

	cout << "Default constructor is called..." << endl;
}
//Constructor with Specific size
Set::Set(int size)
{
	//check if size is valid(Positive value)
	if (size > 0)
	{
		this->size = size;	//tehn set the size of Size as size
	}
	//else give the default size(10)..
	else
	{
		this->size = 10;
	}
	//generting the array...
	this->arr = new int[this->size];
	this->noOfElements = 0;

	cout << "Custructor with size is called..." << endl;
}
//Copy Constructor...
Set::Set(const Set& ref)
{
	//set size as ref.size
	this->size = ref.size;
	//generating the array...
	this->arr = new int[this->size];
	//copy elements of ref.arr to the new arr...
	for (int i = 0; i < ref.noOfElements; i++)
		this->arr[i] = ref.arr[i];
	//setting noOfElements to ref.elements
	this->noOfElements = ref.noOfElements;

	cout << "Copy Constructor is called..." << endl;
}
//Destructor...
Set::~Set()
{
	//deleting the array from the heap~
	delete[] arr;
	//setting the pointer to NULL
	this->arr = NULL;
	cout << "~~~Destructor is called~~~" << endl;
}
//reduce size method to reduce the size of the array to save memory...
void Set::reduce_size()
{
	//setting new size to half of the previous size.
	this->size /= 2;
	int* new_arr;
	//generating a new array of half size to store values.
	new_arr = new int[this->size];
	//copy every value from arr to newly generated array...
	for (int i = 0; i < size; i++)
	{
		new_arr[i] = this->arr[i];
	}
	//delete the previous array and then generate it with new size.
	delete[] arr;
	this->arr = new int[size];
	//backup values for new_arr to arr...
	for (int i = 0; i < size; i++)
	{
		this->arr[i] = new_arr[i];
	}
	//deleting new_arr from memory
	delete[] new_arr;
	new_arr = nullptr;
	//if noOfElements were greater than size, then set them half
	if(noOfElements > size / 2)
		this->noOfElements = size / 2;
}
//invrease size method to increase the size of array by 2 to store more values
void Set::increase_size()
{
	//first generate a new array of size and store values in it
	int* new_arr;
	int previous_size = this->size;
	new_arr = new int[previous_size];
	//copy every value from arr...
	for (int i = 0; i < previous_size; i++)
	{
		new_arr[i] = this->arr[i];
	}
	//increase the size by 2
	this->size *= 2;
	//delete the arr
	delete[] arr;
	//then generate it with new size
	this->arr = new int[size];
	//backup values from new_arr...
	for (int i = 0; i < previous_size; i++)
	{
		arr[i] = new_arr[i];
	}
	//deleting the new_arr...
	delete[]new_arr;
	new_arr = nullptr;
}
//method to check is set is Empty or not.
bool Set::isEmpty()
{
	//if no of elements are equal to zero then return true
	if (this->noOfElements == 0)
	{
		return true;
	}
	//else return false
	else
		return false;
}
//check if set is full
bool Set::isFull()
{
	//if no of elements are equal to size of the set, then return true.
	if (this->noOfElements == this->size)
		return true;
	else
		//else return false.
		return false;
}
//method to insert elements to set and check if value already exist or not...
bool Set::insertElement(int value)
{
	//check if value already exist
	for (int i = 0; i < this->noOfElements; i++)
	{
		//if value exist then return false.
		if (this->arr[i] == value)
			return false;
	}
	//if set is full then increase the size of the set
	if (isFull())
	{
		increase_size();
	}
	//if value does not exist, then insert it at the last...
	this->arr[noOfElements] = value;
	//increase no of elements...
	this->noOfElements++;
	return true;
}
//method to remove value from the set and return false if value does not exist
bool Set::removeElement(int value)
{
	//check if value exist
	for (int i = 0; i < this->noOfElements; i++)
	{
		//if it exist, then
		if (this->arr[i] == value)
		{
			/*from that index, copy every element from next index,
			and then decrease the no Of elements.*/
			for (int j = i; j < this->noOfElements-1; j++)
			{
				this->arr[j] = this->arr[j + 1];
			}
			this->noOfElements--;
			//if remaining no of elements are less than equal to half of the size..
			if (this->noOfElements <= this->size / 2)
			{
				//then reduce the array to save memory
				reduce_size();
			}
			return true;
		}
	}
	//if it does not find the value, then it will return false.
	return false;
}
//method to search element in the set and return its index
int Set::searchElementPosition(int value)
{
	//check for every value...
	for (int i = 0; i < this->noOfElements; i++)
	{
		//if value exist, then return its index
		if (this->arr[i] == value)
		{
			return i;
		}
	}
	//if it does not find a value, then return -1 which is not an index of any array
	return -1;
}
//method to search value in the set..
bool Set::searchElement(int value)
{
	//check for every value
	for (int i = 0; i < this->noOfElements; i++)
	{
		//if value exist, then return true.
		if (this->arr[i] == value)
		{
			return true;
		}
	}
	//if not then return false.
	return false;
}
//method to display complete set on the console.
void Set::displaySet()
{
	cout << "{ ";
	for (int i = 0; i < this->noOfElements; i++)
	{
		cout << this->arr[i] << " ,";
	}
	cout << "\b}";
}
//method to store common elements of 2 sets, and then return a new Set.
Set Set::intersection(Set a)
{
	Set newSet;	//initializing new Set
	//for every element of Set1
	for (int i = 0; i < this->noOfElements; i++)
	{
		//if Set1 element exist in Set2, then insert it in the Set3(Intersection)...
		if (a.searchElement(this->arr[i]))
		{
			newSet.insertElement(this->arr[i]);
		}
	}
	//for every element of set2
	for (int i = 0; i < a.noOfElements; i++)
	{
		//if Set2 element existin set1, then insert it in the Set3(Intersection)
		if (searchElement(a.arr[i]))
		{
			newSet.insertElement(a.arr[i]);
		}
	}
	//return newSet...
	return newSet;
}
//method to store all the elements of Set1 and Set2 in Set3
Set Set::Union(Set a)
{
	Set newSet;	//initializing new Set
	//for every element in Set1
	for (int i = 0; i < this->noOfElements; i++)
	{
		newSet.insertElement(this->arr[i]);
	}
	//for every element in Set2
	for (int i = 0; i < a.noOfElements; i++)
	{
		newSet.insertElement(a.arr[i]);
	}
	//return Set3
	return newSet;
}
//Same as the Union method....
Set Set::operator+(Set& first)
{
	Set newSet;

	for (int i = 0; i < first.noOfElements; i++)
	{
		newSet.insertElement(first.arr[i]);
	}

	for (int i = 0; i < noOfElements - 1; i++)
	{
		newSet.insertElement(arr[i]);
	}

	return newSet;
}
//method to store only those elements which are not present in Set1,
//but not present in Set2
Set Set::difference(Set a)
{
	Set newSet;
	//for every element in Set1
	for (int i = 0; i < noOfElements; i++)
	{
		//if element does not exist in Set2, then insert it
		if (!a.searchElement(arr[i]))
			newSet.insertElement(arr[i]);
	}
	//return Set3
	return newSet;
}
//same as difference method....
Set Set::operator-(Set& first)
{
	Set newSet;

	for (int i = 0; i < first.noOfElements; i++)
	{
		if (!searchElement(first.arr[i]))
			newSet.insertElement(first.arr[i]);
	}

	return newSet;
}
//method to return element at specific index..
int& Set::operator[](int index)
{
	//if index is out of bound, then return -1
	if (index >= noOfElements && index < 0)
	{
		exit(0);
	}
	else
	{
		//else return that specific index.
		return arr[index];
	}
}
//method to check if a reference Set is a subset or not
//return 0 for not a subset.
//return 1 for proper subset
//return 2 for improper subset
int Set::isSubSet(Set a)
{
	//if calling Set no of elements are less then reference Set, then it is not a subset..
	if (a.noOfElements > noOfElements)
		return 0;
	
	if (a.noOfElements == noOfElements)
	{
		//for every element of Set2
		for (int i = 0; i < a.noOfElements; i++)
		{
			//check if set2 element exist in set1.
			//if not then return 0(not a subset)
			if (!searchElement(a.arr[i]))
				return 0;
		}
		return 2;
	}

	if (a.noOfElements < noOfElements)
	{
		for (int i = 0; i < a.noOfElements; i++)
		{
			if (!searchElement(a.arr[i]))
				return 0;
		}
		return 1;
	}
}