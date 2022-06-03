#pragma once
#ifndef BOOK_H
#define BOOK_H
#include"Media.h"
#include<iostream>
#include<string>

using namespace std;

class Book : public Media
{
private:
	string author;
	string ISBN;
public:
	Book();
	Book(string, string, string);

	void display();
};

Book::Book() : Media(" "), author (" "), ISBN (" ")
{}

Book::Book(string title, string author, string isbn)
{
	this->title = title;
	this->author = author;
	this->ISBN = isbn;
}

void Book::display()
{
	cout << "*****************************" << endl;
	cout << "BOOK : " << endl;
	cout << "Book Title: " << title << endl;
	cout << "Book Author: " << author << endl;
	cout << "Book ISBN: " << ISBN << endl;
	cout << "*****************************" << endl;
}

#endif // !BOOK_H
