#pragma once
#ifndef PAIR_H
#define PAIR_H

#include"CString.h"

class Pair {
public:
	CString key;
	CString value;
	Pair();
	Pair(const CString& key, const CString* value);
	~Pair();
};

#endif // !PAIR_H
