#pragma once
#ifndef DOCUMENT_H
#define DOCUMENT_H
#include<iostream>
#include"JSON.h"

using namespace std;

class Document : public JSON
{
	//Represents a Document object
public:
	Document(int size) :JSON(size) {}
	~Document() { JSON::~JSON(); }
	void display()
	{
		//SAMPLE DISPLAY:
		/*
		Document =
		{
		"name" : "Ansab Gillani"
		"age" : 22
		"roll number" : "BCSF17M047"
		"dob" : "13th May 1999"
		"cgpa" : 3.23
		}
		*/
		int age;
		//float cgpa;
		//CString rollnumber = " ";
		//CString name = " ";
		
		for (int i = 0; i < this->getCount(); i++)
		{
			//this->getData(name, "name");
			this->getData(age, "age");
			//this->getData(rollnumber, "roll number");
			//this->getData(cgpa, "cgpa");


			//cout << "\"name\" : "; name.display();
			//cout << endl;
			cout << "\"age\" : " << " " << age << endl;
			//cout << "\"roll number\" : "; rollnumber.display();
			//cout << endl;
			//cout << "\"cgpa\" : " << cgpa << endl;
		}
	}
	void displayValue()
	{
		cout << "Enter the key: ";
		CString key;
		key.input();
		CString value;
		value = this->extractData(key);

		value.display();
	}
	void input() //Takes a key and a value and stores it
	{
		CString key;
		int type = 0;
		cout << "Enter the key: ";
		key.input();

		cout << "Choose the type of the value..." << endl;
		cout << "1. Int." << endl;
		cout << "2. Float." << endl;
		cout << "3. CString." << endl;
		cin >> type;

		while (type < 1 || type > 3)
		{
			cout << "INVALID INPUT!!!" << endl;
			cin >> type;
		}


		switch (type)
		{
		case 1:
			int ivalue;
			cout << "Enter Integer value: ";
			cin >> ivalue;
			this->insert(ivalue, key);
			break;
		case 2:
			float fvalue;
			cout << "Enter float value: ";
			cin >> fvalue;
			this->insert(fvalue, key);
			break;
		case 3:
			CString svalue;
			cout << "Enter CString value: ";
			svalue.input();
			this->insert(svalue, key);
			break;
		}

	}
};

#endif // !DOCUMENT_H
