#pragma once
#ifndef JSON_H
#define JSON_H

#include"PairArray.h"
#include"DataConverter.h"

class JSON : public PairArray
{
	DataConverter converter;
	int count;
	//Represents a JSON object
public:
	JSON(int size);
	~JSON();
	void insert(int value, CString key); //inserts Integer
	void insert(CString, CString key); //inserts CString
	void insert(float, CString key); //inserts float
	void insert(Date, CString key); //inserts Date
	void getData(CString&, const CString& key); //returns CString
	void getData(Date&, const CString& key); //returns Date
	void getData(int& value, const CString& key); //returns int
	void getData(float&, const CString& key); //returns float
	int getCount();
};

#endif // !JSON_H
