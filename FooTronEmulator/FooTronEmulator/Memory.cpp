#include "Memory.h"
using namespace std;


//Set the intial memory values
void Memory::setInitalValues(vector<int> values) {
	memoryValues = values;

}
//return memory size. 
int Memory::getSize()
{
	return this->memoryValues.size();
}
//change the value in memory at a given location
void Memory::changeMemoryValue(int location, int newValue) {
	this->memoryValues.at(location) = newValue;
}
//Return the a value at a given location in memory
int Memory::accessMemoryLocation(int location){
	return this->memoryValues[location];
}