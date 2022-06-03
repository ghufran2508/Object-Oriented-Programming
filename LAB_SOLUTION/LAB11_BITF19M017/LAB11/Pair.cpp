#include"Pair.h"

Pair::Pair()
{
	this->key = " ";
	this->value = " ";
}

Pair::Pair(const CString& value, const CString* key)
{
	this->value = value;
	this->key = *key;
}

Pair::~Pair()
{}