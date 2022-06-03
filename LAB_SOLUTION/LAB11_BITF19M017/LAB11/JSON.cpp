#include"JSON.h"

using namespace std;

JSON::JSON(int size):PairArray(size)
{
	this->count = 0;
}

JSON::~JSON()
{
	PairArray::~PairArray();
}

void JSON::insert(int value, CString key) 
{
	CString converted;
	converter.dataConverter(converted, value);
	this->insertData(converted, key);
	count++;
} 

void JSON::insert(CString value, CString key)
{
	this->insertData(value, key);
	count++;
}

void JSON::insert(float value, CString key) //inserts float
{
	CString converted;
	converter.dataConverter(converted, value);
	this->insertData(converted, key);
	count++;
}

void insert(Date, CString key); //inserts Date

void JSON::getData(CString& valueg, const CString& key) //returns CString
{
	valueg = extractData(key);
}

void JSON::getData(int& value, const CString& key) {
	CString extractedValue = this->extractData(key);
	converter.dataConverter(value, extractedValue);
} //returns int
void JSON::getData(float& value, const CString& key) //returns float
{
	CString extractedValue = this->extractData(key);
	converter.dataConverter(value, extractedValue);
}

void getData(Date&, const CString& key); //returns Date

int JSON::getCount()
{
	return this->count;
}