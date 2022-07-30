#pragma once


#include <vector>
using namespace std;
class Memory
{
private:
	vector<int> memoryValues;
public:
	Memory(vector<int> values) {
		this->memoryValues = values;
	};
	Memory() {
		
	};
	//Get value in a specific location
	int accessMemoryLocation(int location);
	//change value at a specific location
	void changeMemoryValue(int location, int newValue);
	//load values into memory
	void setInitalValues(vector<int> values);
	//return current memory size. 
	int getSize();
};

