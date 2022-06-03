#pragma once
#ifndef PAIRARRAY_H
#define PAIRARRAY_H

#include"Pair.h"

class PairArray
{
	int size;
	Pair* pairs;
	int findKey(const CString& key); //returns index of a key
	void resize(int newSize);
	bool isFull(int count);
	bool isEmpty(int count);
public:
	PairArray(int size);
	~PairArray();
	void insertData(const CString value, const CString key);
	//inserts key to a specific value
	CString extractData(const CString key);
	//returns value of a specific key
};

#endif // !PAIRARRAY_H
