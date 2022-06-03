#pragma once
#ifndef WINDOW_H
#define WINDOW_H

#include<iostream>
#include"CString.h"
#include"Button.h"
#include"ClearButton.h"
#include"AddButton.h"
#include"ConvertToLowerButton.h"
#include"ConvertToUpperButton.h"
#include"ConvertToIntButton.h"
#include"ConvertToFloatButton.h"
#include"DisplayButton.h"
#include"RemoveButton.h"
#include"ReverseButtonh.h"

using namespace std;

class Window
{
private:
	Button* buttons;
	CString data = " ";
public:
	void insertButton()
	{
		int choice;

		cout << "Which Button you want to insert??? " << endl;
		cout << "1. Clear. " << endl;
		cout << "2. Add. " << endl;
		cout << "3. Remove. " << endl;
		cout << "4. Convert To Lower. " << endl;
		cout << "5. Convert To Upper. " << endl;
		cout << "6. Convert To Int. " << endl;
		cout << "7. Convert To Float. " << endl;
		cout << "8. Display. " << endl;
		cout << "9. Reverse. " << endl;

		cin >> choice;

		while (choice < 1 || choice > 9)
		{
			cout << "Invalid Number!!!" << endl;
			cin >> choice;
		}

		switch (choice)
		{
		case 1:
			buttons = new ClearButton();
			break;
		case 2:
			buttons = new AddButton();
			break;
		case 3:
			buttons = new RemoveButton();
			break;
		case 4:
			buttons = new ConvertToLowerButton();
			break;
		case 5:
			buttons = new ConvertToUpperButton();
			break;
		case 6:
			buttons = new ConvertToIntButton();
			break;
		case 7:
			buttons = new ConvertToFloatButton();
			break;
		case 8:
			buttons = new DisplayButton();
			break;
		case 9:
			buttons = new ReverseButton();
			break;
		}

		buttons->setCommand();

		cin.ignore();
		cout << "Enter the data for the button: " ;
		data.input();
	}

	void removeButton()
	{
		//delete buttons;
	}

	void performAction(int index)
	{
		buttons->buttonExecute(data);
	}
};

#endif // !WINDOW_H