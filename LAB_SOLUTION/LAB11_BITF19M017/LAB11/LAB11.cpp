#include<iostream>
#include"Document.h"

using namespace std;

int main()
{
	Document doc(1);
	doc.insert("age", "0");

	doc.display();
	return 0;
}