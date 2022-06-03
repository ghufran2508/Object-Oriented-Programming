#include"PairArray.h"

PairArray::PairArray(int size)
{
	this->size = (size > 0) ? size : 1;

	pairs = new Pair[size];
}

PairArray::~PairArray()
{
	if (pairs)
	{
		delete[] pairs;
		pairs = nullptr;
	}
}

bool PairArray::isEmpty(int count)
{
	if (count < size)
	{
		if(pairs[count].key == "")
			return true;
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

bool PairArray::isFull(int count)
{
	if (size == count)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void PairArray::resize(int resize)
{
	Pair *newpairs;
	newpairs = new Pair[size];

	for (int i = 0; i < size; i++)
	{
		newpairs[i].key = this->pairs[i].key;
		newpairs[i].key = this->pairs[i].value;
	}

	delete[] pairs;

	pairs = new Pair[resize];

	for (int i = 0; i < size; i++)
	{
		this->pairs[i].key = newpairs[i].key;
		this->pairs[i].value = newpairs[i].value;
	}
	this->size = resize;
	delete[] newpairs;
}

int PairArray::findKey(const CString& key)
{
	for (int i = 0; i < size; i++)
	{
		if (pairs[i].key == key)
		{
			return i;
		}
	}
	return -1;
}

void PairArray::insertData(const CString value, const CString key)
{
	int index = findKey(key);

	if (index >= 0)
	{
		this->pairs[index].value = value;
	}
	else
	{
		pairs[size - 1].key = key;
		pairs[size - 1].value = value;
		resize(size + 1);
	}
}

CString PairArray::extractData(const CString key)
{
	for (int i = 0; i < size; i++)
	{
		if (this->pairs[i].key == key)
		{
			return this->pairs[i].value;
		}
	}
}