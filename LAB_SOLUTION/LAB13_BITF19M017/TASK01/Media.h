#pragma once
#ifndef MEDIA_H
#define MEDIA_h

#include<iostream>
#include<string>
using namespace std;

class Media
{
protected:
	string title;
public:
	Media();
	Media(string);

	void setTitle(string);
	string getTitle() const;

	virtual void display();
};

Media::Media(): title(" ")
{}

Media::Media(string title)
{
	this->title = title;
}

void Media::setTitle(string title)
{
	this->title = title;
}

string Media::getTitle() const
{
	return this->title;
}

void Media::display()
{
	cout << "Media Title: " << title << endl;
}
#endif // !MEDIA_H
