#include<iostream>
#include"ScoreKeeper.h"

using namespace std;

Scorekeeper::Scorekeeper()
{
	course = "";
	scoresCount = 0;
}

Scorekeeper::Scorekeeper(string courseName, int tScores)
{
	this->course = courseName;

	if (tScores > 0)
	{
		this->scoresCount = tScores;
	}
	scores = new int[this->scoresCount];

	for (int i = 0; i < this->scoresCount; i++)
	{
		cout << "Please enter Score for test#" << i + 1 << ": " << endl;
		cin >> scores[i];
		while (scores[i] < 0 || scores[i] > 100)
		{
			cout << "INVALID INPUT!!!" << endl;
			cout << "Please enter Score for test#" << i + 1 << ": " << endl;
			cin >> scores[i];
		}
	}
}

Scorekeeper::~Scorekeeper()
{
	delete[] scores;
	scores = nullptr;
}

 void Scorekeeper::setCourseName(string courseName)
{
	 this->course = courseName;
}

void Scorekeeper::setScoresCount(int scoreCount)
{
	if (scoreCount >= 0)
		this->scoresCount = scoreCount;
}

void Scorekeeper::setScores(int* scr)
{
	this->scores = scr;
}

string Scorekeeper::getScourseName()
{
	return this->course;
}

int Scorekeeper::getScoresCount()
{
	return this->scoresCount;
}

int* Scorekeeper::getScores()
{
	return this->scores;
}

ostream& operator<<(ostream& out, const Scorekeeper & myscore)
{
	out << "Course name: " << myscore.course;
	out << "\tNumber of Courses: " << myscore.scoresCount << endl;
	out << "Scores: ";
	for (int i = 0; i < myscore.scoresCount; i++)
		out << myscore.scores[i] << "\t";
	out << endl;
	return out;
}

void Scorekeeper::operator=(const Scorekeeper& myscore)
{
	this->course = myscore.course;
	this->scoresCount = myscore.scoresCount;

	scores = new int[scoresCount];

	for (int i = 0; i < scoresCount; i++)
	{
		scores[i] = myscore.scores[i];
	}
}

int Scorekeeper::operator[](int index) const
{
	if (index < scoresCount)
		return scores[index];
	else
		return 0;
}