#pragma once
#include<string>

using namespace std;

class Scorekeeper
{
private:
	string course;
	int scoresCount;
	int* scores;
public:
	Scorekeeper();
	Scorekeeper(string courseName, int tScores);
	~Scorekeeper();

	void setCourseName(string courseName);
	void setScoresCount(int scoreCount);
	void setScores(int* scr);

	string getScourseName();
	int getScoresCount();
	int* getScores();

	friend ostream& operator<<(ostream&, const Scorekeeper &);
	
	void operator=(const Scorekeeper&);
	int operator[](int) const;
};