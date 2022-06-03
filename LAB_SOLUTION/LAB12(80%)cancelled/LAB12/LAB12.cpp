#include<iostream>
#include"Window.h"
using namespace std;

int main()
{
	Window btn;

	btn.insertButton();
	btn.performAction(0);
	btn.removeButton();

	return 0;
}