#include<iostream>
using namespace std;
//declaring structure of MovieData to store the entities...
struct MovieData
{
	string title;	//string to store movie name
	string director;	//string to store movie director name
	short yearReleased;	 //short integer to store the year released of the movie
	short runningTime;	//short integer to store the running time of the movie in minutes...
};
//function definition to display the data of movies on console
void displayMovieData(MovieData mv)
{
	cout << "MOVIE NAME: / " << mv.title << " /" << endl; //display movie title
	cout << "MOVIE DIRECTOR: / " << mv.director << " /" << endl; //display movie director
	cout << "RELEASED YEAR: / " << mv.yearReleased << " /" << endl;	//display movie year released
	cout << "RUNNING TIME(in minutes): / " << mv.runningTime << "min /" << endl; //display movie run time in minutes...
}
//main function//
int main()
{
	MovieData movie1;	//craeting a struct of name movie1
	MovieData movie2;	//craeting a struct of name movie2
	movie1.director = "Frank Darabont";	//assigning movie1 director name
	movie1.title = "The ShawShank Redmption"; //assigning movie1 titla name
	movie1.yearReleased = 1994;	//assigning movie1 yearReleased
	movie1.runningTime = 142;	//assigning movie1 running time
	movie2.director = "Oliver Stone";	//assigning movie2 director name
	movie2.title = "Snowden";	//assigning movie2 titla name
	movie2.yearReleased = 2016;	//assigning movie2 yearReleased
	movie2.runningTime = 134;	//assigning movie2 running time
	cout << "MOVIE 1: " << endl;
	//calling function to display movie data on console
	displayMovieData(movie1);
	cout << "\nMOVIE 2: " << endl;
	//calling function to display movie data on console
	displayMovieData(movie2);
	return 0;
}

