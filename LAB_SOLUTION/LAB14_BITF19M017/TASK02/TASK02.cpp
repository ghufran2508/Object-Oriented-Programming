#include<iostream>
#include<string>
#include"Sets.h"

using namespace std;

int main()
{
	{
		cout << "Random numbers for integers set....\n\n" << endl;
		Set <int> set1;
		Set <int> set2;

		for (int i = 0; i < 20; i++)
		{
			int a = rand() % 10;
			set1.insertElement(a);
			set2.insertElement(a + 1);
		}

		cout << "set1: " << endl;
		set1.displaySet();
		cout << endl << "set2: " << endl;
		set2.displaySet();
		cout << endl;

		Set <int> set3;
		set3 = set1.intersection(set2);
		cout << "set3: set1 intersection set2: " << endl;
		set3.displaySet();
		cout << endl;

		Set<int> set4;
		set4 = set1.Union(set2);

		cout << "set4: set1 Union set2: " << endl;
		set4.displaySet();
		cout << endl;



		int subset = set4.isSubSet(set3);
		if (subset == 1)
		{
			cout << "set3 is a proper subset of set4" << endl;
		}
		else if (subset == 0)
		{
			cout << "set3 is not a subset of set4." << endl;
		}
		else if (subset == 2)
		{
			cout << "set3 is an improper subset of set4." << endl;
		}
		cout << endl << endl;
	}
	system("pause");
	system("cls");
	{
		cout << "Now for string....\n\n" << endl;
		Set <string> set1;
		Set <string> set2;

		for (int i = 0; i < 5; i++)
		{
			string a;
			cout << "Enter any string# " << i+1<< " :";
			getline(cin, a);
			set1.insertElement(a);
			set2.insertElement(a);
		}

		cout << "set1: " << endl;
		set1.displaySet();
		cout << endl << "set2: " << endl;
		set2.displaySet();
		cout << endl;
		cout << endl;



		int subset = set1.isSubSet(set2);
		if (subset == 1)
		{
			cout << "set1 is a proper subset of set2" << endl;
		}
		else if (subset == 0)
		{
			cout << "set1 is not a subset of set2." << endl;
		}
		else if (subset == 2)
		{
			cout << "set1 is an improper subset of set2." << endl;
		}
	}

	return 0;
}