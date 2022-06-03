#include<iostream>
#include<string>
#include"Book.h"
#include"Magazine.h"

using namespace std;

int main()
{
	int n;
	string title;

	cout << "Enter Media items you want to create: ";
	cin >> n;

	while (n <= 0)
	{
		cout << "INVALID SIZE!!!" << endl;
		cin >> n;
	}

	Media** media;
	media = new Media * [n];

	for (int i = 0; i < n; i++)
	{
		int choice;

		cout << "Choose the media item you want to create..." << endl;
		cout << "1. Book." << endl;
		cout << "2. Magazine." << endl;
		cin >> choice;

		while (choice < 1 && choice > 2)
		{
			cout << "INVALID CHOICE!!!" << endl;
			cin >> choice;
		}

		if (choice == 1)
		{
			string author;
			string isbn;

			cout << "Enter title of the Book: ";
			cin >> title;
			cout << "Enter Author Name : ";
			cin >> author;
			cout << "Enter ISBN : ";
			cin >> isbn;

			media[i] = new Book(title, author, isbn);
			system("cls");
			media[i]->display();
		}
		else
		{
			string monthname;
			int yop;

			cout << "Enter title of the Magazine: ";
			cin >> title;
			cout << "Enter Month Name : ";
			cin >> monthname;
			cout << "Enter Year of Publication : ";
			cin >> yop;

			while (yop < 0)
			{
				cout << "INVALID YEAR!!!" << endl;
				cin >> yop;
			}

			media[i] = new Magazine(title, monthname, yop);
			system("cls");
			media[i]->display();
		}
	}
	
	for (int i = 0; i < n; i++)
	{
		delete media[i];
	}
	delete[] media;
	media = nullptr;

	return 0;
}