#include<iostream>
#include<string>
using namespace std;
struct MovieData
{
	string title;
	string director;
	short int yearReleased;
	short int runningTime;
	int productionCost;
	int firstYearRevenue;
	int profitLoss;
};

void inputMovieData(MovieData &mv)
{
	cout << "ENTER MOVIE NAME: " ;
	getline(cin, mv.title);
	cout << "ENTER MOVIE DIRECTOR NAME: " ;
	getline(cin, mv.director);
	cout << "ENTER MOVIE YEAR RELEASED: " ;
	cin >> mv.yearReleased;
	while(mv.yearReleased < 1888 || mv.yearReleased > 2020)
	{
		cout << "[+]INVALID INPUT!!!" << endl;
		cout << "ENTER MOVIE YEAR RELEASED: " ;
		cin >> mv.yearReleased;
	}
	cout << "ENTER MOVIE RUNNING TIME: " ;
	cin >> mv.runningTime;
	while(mv.runningTime <= 0)
	{
		cout << "[+]INVALID INPUT!!!" << endl;
		cout << "ENTER MOVIE RUNNING TIME: " ;
		cin >> mv.runningTime;
	}
	cout << "ENTER MOVIE PRODUCTION COST: " ;
	cin >> mv.productionCost;
	while(mv.productionCost <= 0)
	{
		cout << "[+]INVALID INPUT!!!" << endl;
		cout << "ENTER MOVIE PRODUCTION COST: " ;
		cin >> mv.productionCost;
	}
	cout << "ENTER MOVIE 1st YEAR REVENUE: " ;
	cin >> mv.firstYearRevenue;
}

void displayMovieData(MovieData mv)
{
	cout << "MOVIE NAME: / " << mv.title << " /" << endl;
	cout << "MOVIE DIRECTOR: / " << mv.director << " /" << endl;
	cout << "RELEASED YEAR: / " << mv.yearReleased << " /" << endl;
	cout << "RUNNING TIME(in minutes): / " << mv.runningTime << "min /" << endl;
	cout << "MOVIE PROFIT/LOSS: / " << mv.profitLoss << "$ /" << endl;
}

int main()
{
	MovieData movie1;
	MovieData movie2;

	inputMovieData(movie1);
	cin.ignore();
	inputMovieData(movie2);
	
	movie1.profitLoss = movie1.firstYearRevenue - movie1.productionCost;
	movie2.profitLoss = movie2.firstYearRevenue - movie2.productionCost;
	
	cout << "MOVIE 1: " << endl;
	displayMovieData(movie1);
	cout << "\nMOVIE 2: " << endl;
	displayMovieData(movie2);
	return 0;
}
