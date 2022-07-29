#include "ProgramCounter.h"

ProgramCounter::ProgramCounter()
{
}
//add to the program counter
void ProgramCounter::addElement(int i)
{	
	checkIfSizeLimitedReached();
	values.push_back(i);
}
//check if the size limit was reached, if it is, delete first element to make room. 
void ProgramCounter::checkIfSizeLimitedReached()
{
	int i = values.size();
	if (i == 4) {
		values.erase(values.begin());
	}
}
//print all values in the counter
void ProgramCounter::printCounterCollection()
{	
	
	if (values.size() == 0) {
		cout << "\t|PC Values:\n";
	}
	else{
		cout << "\t|PC Values:\n";
		for (int i = 0; i < values.size(); i++) {
			cout << "\t\t\t|" << values.at(i) << "\n";
		}
	
	}
}
//delete everything in the counter. 
void ProgramCounter::deleteAll()
{
	values.erase(values.begin(), values.end());
}
