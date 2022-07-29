#pragma once
#include <iostream>
#include <vector>

using namespace std;
class ProgramCounter
{
private:
	vector<int> values;
public:
	ProgramCounter();
	// add to the program counter
	void addElement(int i);
	//check if the size limit was reached
	void checkIfSizeLimitedReached();
	//print everything
	void printCounterCollection();
	//empty the counter
	void deleteAll();
};

