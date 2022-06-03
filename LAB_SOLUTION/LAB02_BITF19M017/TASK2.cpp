#include<iostream>

using namespace std;

struct Player
{
	string* Name;
	int* Number;
	int* PointScored;	
	int totalPoints = 0;
};

void createArray(Player &noob)
{
	noob.Name = new string[12];
	noob.Number = new int[12];
	noob.PointScored = new int[12];
}

void PopulateArray(Player &noob)
{
	for(int i = 0; i < 12; i++)
	{
		cout << "Please enter player# " << i+1 <<" name: " ;
		getline(cin, noob.Name[i]);
		cout << "Please enter " << noob.Name[i] << " number: " ;
		cin >> noob.Number[i];
		cout << "Please enter " << noob.Name[i] << " points scored: " ;
		cin >> noob.PointScored[i];
		cin.ignore();
	}
}

void DisplayScoreBoard(Player noob)
{
	cout << "PLAYER'S NAME\t PLAYER NUMBER\t PLAYER POINTS" << endl;
	for(int i = 0; i < 12; i++)
	{
		cout << noob.Name[i] << "  \t\t" << noob.Number[i] << "  \t\t" << noob.PointScored[i] << endl;
	}
}

void calculateTotalPoints(Player &noob)
{
	for(int i = 0; i < 12; i++)
	{
		noob.totalPoints += noob.PointScored[i];
	}
}

string FindTopScorer(Player noob)
{
	string name;
	int temp = noob.PointScored[0];
	for(int i = 0; i < 12; i++)
	{
		if(temp < noob.PointScored[i])	temp = noob.PointScored[i];
	}
	for(int i = 0; i < 12; i++)
	{
		if(temp == noob.PointScored[i])	name = noob.Name[i];
	}
	
	return name;
}

int main()
{
	string topperName;
	
	Player noobs;
	createArray(noobs);
	PopulateArray(noobs);
	DisplayScoreBoard(noobs);
	calculateTotalPoints(noobs);
	topperName = FindTopScorer(noobs);
	
	cout << "\nTotal Points Scored by the team: " << noobs.totalPoints << endl;
	cout << "Top Scorer Player: " << topperName << endl;
	
	return 0;
}







