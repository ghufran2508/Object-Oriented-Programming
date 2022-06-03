#include<iostream>
#include"CString.h"

using namespace std;

CString::CString() :size(100)
{
	data = new char[this->size];

	data[0] = '\0';
}

CString::CString(char ch)
{
	size = 1;
	data = new char[this->size + 1];
	data[0] = ch;
	data[1] = '\0';
}

CString::CString(const char* string)
{
	int count = 0;
	while (string[count] != '\0')
		count++;

	this->size = count;
	data = new char[this->size + 1];

	for (int i = 0; i < this->size; i++)
		this->data[i] = string[i];

	this->data[this->size] = '\0';
}

CString::CString(const CString& ref)
{
	this->size = ref.size;
	this->data = new char[this->size + 1];

	for (int i = 0; i < this->size; i++)
	{
		data[i] = ref.data[i];
	}

	this->data[this->size] = '\0';
}

CString::~CString()
{
	delete[] data;
	data = NULL;
}

char& CString::at(int index)
{
	if (index >= 0 && index < getLength())
	{
		if (data != NULL)
			return data[index];
	}
	else
	{
		exit(0);
	}
}

bool CString::isEmpty()
{
	if (getLength() == 0)
		return true;
	else
		return false;
}

bool CString::isFull()
{
	if (getLength() == size)
		return true;
	else
		return false;
}

//void CString::resize(int newsize)
//{
//	int previous_size = getLength();
//	char* newptr = new char[previous_size];
//	for (int i = 0; i < previous_size; i++)
//	{
//		newptr[i] = data[i];
//	}
//
//	delete[]data;
//	this->size = newsize;
//	data = new char[this->size + 1];
//	if (previous_size < newsize)
//	{
//		for (int i = 0; i < previous_size; i++)
//		{
//			data[i] = newptr[i];
//		}
//		data[previous_size] = '\0';
//	}
//	else
//	{
//		for (int i = 0; i < newsize; i++)
//		{
//			data[i] = newptr[i];
//		}
//		data[newsize] = '\0';
//	}
//
//	delete[] newptr;
//	newptr = NULL;
//}

void CString::resize(int newsize)
{
	int previous_size = getLength();
	char* newptr = new char[previous_size];
	for (int i = 0; i < previous_size; i++)
	{
		newptr[i] = data[i];
	}

	delete[]data;
	this->size = newsize;
	data = new char[this->size + 1];

	for (int i = 0; i < previous_size; i++)
	{
		data[i] = newptr[i];
	}
	data[previous_size] = '\0';
	delete[] newptr;
	newptr = NULL;
}

int CString::getLength()
{
	int s = 0;

	while (data[s] != '\0')
		s++;

	return s;
}

void CString::display()
{
	for (int i = 0; i < getLength(); i++)
	{
		cout << this->data[i];
	}
}

int CString::find(CString& subString, int start)
{
	int total = 0;
	bool exist;

	for (int i = start; i < getLength(); i++)
	{
		exist = true;
		if (data[i] == subString.data[0])
		{
			for (int j = 0; j < subString.getSize(); j++)
			{
				if (subString.data[j] != data[i + j])
				{
					exist = false;
					break;
				}
			}
			if (exist)
				total++;
		}
	}

	return total;
}

void CString::insert(int index, CString& substring)
{
	if (index >= 0 && index <= getLength())
	{
		if (index == getLength())
		{
			resize(size + substring.getSize());
			for (int i = index; i < index + substring.getSize(); i++)
			{
				data[i] = substring.data[i - index];
			}
			data[index + substring.getSize()] = '\0';
		}
		else
		{
			char* temp = new char[getLength() - index];

			for (int i = 0; i < getLength() - index; i++)
			{
				temp[i] = data[i + index];
			}

			resize(size + substring.getSize());

			for (int i = index; i < index + substring.getSize(); i++)
			{
				data[i] = substring.data[i - index];
			}

			for (int i = index + substring.getSize(); i < this->size; i++)
			{
				data[i] = temp[i - (index + substring.getSize())];
			}
			data[index + substring.getSize()] = '\0';
			delete[]  temp;
		}
	}
}
//error!!!
//void CString::insert(int index, CString& substring)
//{
//	if (index >= 0 && index <= getLength())
//	{
//		for (int i = index, j = 0; substring.data[j] != '\0'; i++, j++)
//		{
//			if (i == getLength())
//			{
//				this->resize(this->size * 2);
//			}
//			for (int k = getLength() - 1; k >= i; k--)
//			{
//				data[k + 1] = data[k];
//			}
//			data[i] = substring.data[j];
//		}
//	}
//}

void CString::remove(int index, int count)
{
	if ((index >= 0 && index < getLength()) && (index + count <= getLength()) && (count > 0))
	{
		for (int j = 0; j < count; j++)
		{
			for (int i = index; i < getLength(); i++)
			{
				data[i] = data[i + 1];
			}
		}
		if (getLength() <= size / 4)
		{
			resize(this->size / 2);
		}
	}
	else
	{
		exit(0);
	}
}

int CString::replace(CString& oldString, CString& newString)
{
	int total = find(oldString);

	if (total > 0)
	{
		bool finder;

		for (int j = 0; j < getLength(); j++)
		{
			finder = true;
			if (this->data[j] == oldString.data[0])
			{
				for (int k = 0; k < oldString.getSize(); k++)
				{
					if (this->data[k + j] != oldString.data[k])
					{
						finder = false;
						break;
					}
				}
				if (finder)
				{
					remove(j, oldString.getSize());
					insert(j, newString);
				}
			}
		}
	}

	return total;
}

void CString::trimLeft()
{
	int totalspaces = 0;

	for (int i = 0; data[i] == 32; i++)
		totalspaces++;

	remove(0, totalspaces);
}

void CString::trimRight()
{
	int totalspaces = 0;

	for (int i = getLength() - 1; data[i] == 32; i--)
		totalspaces++;

	remove(getLength() - totalspaces, totalspaces);
}

void CString::trim()
{
	this->trimLeft();
	this->trimRight();
}

void CString::makeUpper()
{
	for (int i = 0; i < getLength(); i++)
	{
		if (data[i] >= 97 && data[i] <= 127)
			data[i] -= 32;
	}
}

void CString::makeLower()
{
	for (int i = 0; i < getLength(); i++)
	{
		if (data[i] >= 65 && data[i] <= 90)
			data[i] += 32;
	}
}

int CString::compare(CString& newString)
{
	for (int i = 0; i < getLength(); i++)
	{
		if (data[i] != newString.data[i])
		{
			if (data[i] < newString.data[i])
				return -1;
			else
				return 1;
		}
	}

	return 0;
}

void CString::reverse()
{
	if (getLength() > 0)
	{
		char temp;
		for (int i = 0, j = getLength() - 1; i < getLength() / 2; i++, j--)
		{
			temp = data[i];
			data[i] = data[j];
			data[j] = temp;
		}
	}
}

void CString::concatEqual(const CString& s2)
{
	int previous_size = size;

	int s2Size = 0;

	while (data[s2Size] != '\0')
		s2Size++;

	resize(size + s2Size);

	for (int i = previous_size; i < size; i++)
		data[i] = s2.data[i - previous_size];

	data[size] = '\0';
}

void CString::concatEqual(const char* const s2)
{
	int previous_size = size;
	int i = 0;

	while (s2[i] != '\0')
	{
		i++;
	}

	resize(size + i);

	for (int i = previous_size; i < size; i++)
		data[i] = s2[i - previous_size];

	data[size] = '\0';
}

bool CString::isEqual(const CString& s2)
{
	int count = 0;
	while (s2.data[count] != '\0')
		count++;

	if (getLength() == count)
	{
		for (int i = 0; i < size; i++)
		{
			if (data[i] != s2.data[i])
				return false;
		}
		return true;
	}
	else
		return false;
}

bool CString::isEqual(const char* const s2)
{
	int i = 0;

	while (s2[i] != '\0')
	{
		i++;
	}

	if (getLength() == i)
	{
		for (int i = 0; i < getLength(); i++)
		{
			if (data[i] != s2[i])
				return false;
		}
		return true;
	}
	else
		return false;
}

CString CString::concat(const CString& s2) const
{
	CString newString(data);

	newString.concatEqual(s2);

	return newString;
}

CString CString::concat(const char* const s2) const
{
	CString newString(data);

	newString.concatEqual(s2);

	return newString;
}

CString& CString::operator= (const CString& ref)
{
	this->size = ref.size;

	int count = 0;
	while (ref.data[count] != '\0')
		count++;

	resize(size);

	for (int i = 0; i < count; i++)
	{
		data[i] = ref.data[i];
	}

	data[count] = '\0';
	return *this;
}

CString& CString::operator=(const char* ref)
{
	int i = 0;

	while (ref[i] != '\0')
	{
		i++;
	}

	size = i;
	resize(size);
	for (int i = 0; i < size; i++)
	{
		data[i] = ref[i];
	}

	data[i] = '\0';
	return *this;
}

char& CString::operator[](const int index)
{
	if (index >= 0 && index < getLength())
		return data[index];
	else
	{
		cout << "Index out of bound!!!" << endl;
		char a = '\0';
		return a;
	}
}

void CString::operator+=(const CString& s2)
{
	concatEqual(s2);
}

void CString::operator+=(const char* s2)
{
	concatEqual(s2);
}

int CString::operator==(const CString& s2)
{
	int count = 0;
	while (s2.data[count] != '\0')
		count++;

	if (getLength() == count)
	{
		for (int i = 0; i < getLength(); i++)
		{
			if (data[i] != s2.data[i])
				return false;
		}
		return 1;
	}
	else
		return 0;
}

CString CString::operator+(const CString& s2) const
{
	CString newString;

	newString = concat(s2);

	return newString;
}

CString CString::operator+(const char* const s2) const
{
	CString newString;

	newString = concat(s2);

	return newString;
}

ostream& operator<<(ostream& out, const CString& string)
{
	for (int i = 0; string.data[i] != '\0'; i++)
		out << string.data[i];

	return out;
}

istream& operator>>(istream& in, const CString& string)
{
	char dat[30];
	int size = 0;;

	in >> dat;

	while (dat[size] != '\0')
		size++;

	for (int i = 0; i < size; i++)
		string.data[i] = dat[i];
	string.data[size] = '\0';

	return in;
}