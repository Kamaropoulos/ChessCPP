#pragma once
#include <string>

using namespace std;

class Position {
private:
	string str;
	unsigned short file;
	unsigned short rank;
	static int _letterToNumber(char letter);
	static char _numberToLetter(int number);
	void _updateString();
public:
	static pair<int, int> stringToFileAndRank(string notation);

	string toString();

	Position(string posStr);
	Position(int file, int rank);

	void set(string posStr);
	void set(int file, int rank);

	void setFile(int file);
	void setFile(char file);

	void setRank(int rank);

	int getFile();
	int getRank();

};

