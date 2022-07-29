#include "CPU.h"
#include <iostream>
using namespace std;

//Execute the instruction at a given memory location
void CPU::executeInstruction(Memory &mem, int instruction,Accumulator &accum) {

	

	//if instruction is 43, halt
	if (instruction == 43) {
		this->stop = true;
	}
	//if instruction is 10, get user input and send the input to the location in memory
	else if (instruction == 10) {

		int newLocation = getLocationToChange(mem);
		int input;
		cout << "Please input a number\n";
		cin >> input;
		if (cin.fail()) {
			cout << "Error:Invalid value entered";
			exit(0);
		}
		cin.clear();
		mem.changeMemoryValue(newLocation, input);
		this->currentLineInCode += 1;
	}
	//if instruction is 11, print the value at the given location
	else if (instruction == 11) {
		int newLocation = getLocationToChange(mem);
		cout << "\n\nOutput:" << mem.accessMemoryLocation(newLocation) << "\n";
		this->currentLineInCode += 1;
	}
	//if instruction is 20, load a value from memory to the accumulator
	else if (instruction == 20) {
		int newLocation = getLocationToChange(mem);
		accum.store(mem.accessMemoryLocation(newLocation));
		this->currentLineInCode += 1;
	}
	//if instruction is 21, store the value in the accumulator to the given location
	else if (instruction == 21) {
		int newLocation = getLocationToChange(mem);
		int storedValue = accum.peekValue();
		mem.changeMemoryValue(newLocation, storedValue);
		this->currentLineInCode += 1;
	}
	//if instruction is 30, add a value from memroy to accumulator
	else if (instruction == 30) {
		int newLocation = getLocationToChange(mem);
		accum.store(mem.accessMemoryLocation(newLocation));
		this->currentLineInCode += 1;
	}
	//if instruction is 31, subtract a value from memory from accumulator
	else if (instruction == 31) {
		int newLocation = getLocationToChange(mem);
		accum.subtract(mem.accessMemoryLocation(newLocation));
		this->currentLineInCode += 1;

	}
	//if instruction is 32, divide accumualator value by value in memory at given location
	else if (instruction == 32) {
		int newLocation = getLocationToChange(mem);
		accum.divide(mem.accessMemoryLocation(newLocation));
		this->currentLineInCode += 1;
	}
	//if instruction is 33, multiply accumulator 
	else if (instruction == 33) {
		int newLocation = getLocationToChange(mem);
		accum.multiply(mem.accessMemoryLocation(newLocation));
		this->currentLineInCode += 1;
	}
	//if instruction is 40, set the current location to the given location
	else if (instruction == 40){
		int newLocation = getLocationToChange(mem);
		this->currentLineInCode = newLocation;
	}
	//if instruction is 41, and the value in the accumulator is negative,  set the current location to the given location
	else if (instruction == 41) {
		if (accum.peekValue() < 0) {
			int newLocation = getLocationToChange(mem);
			this->currentLineInCode = newLocation;
		}
		else {
			this->currentLineInCode += 1;
		}
		
	}
	//if instruction is 42, and the value in the accumulator is 0,  set the current location to the given location
	else if (instruction == 42) {
		if (accum.peekValue() == 0) {
			int newLocation = getLocationToChange(mem);
			this->currentLineInCode = newLocation;
		}
		else {
			this->currentLineInCode += 1;
		}
	}
	else {
		this->currentLineInCode += 1;
	}
	

}
//Get an instruction from  a location in memory
int CPU::getInstruction(Memory mem) {
	int valueAtLocation = mem.accessMemoryLocation(this->currentLineInCode) / 100;
	return valueAtLocation;
}
//Get the pointer to the memory location to which the instruction will be operating on
int CPU::getLocationToChange(Memory mem) {
	
	int valueAtLocation = mem.accessMemoryLocation(this->currentLineInCode) % 100;
	if (valueAtLocation > mem.getSize()) {
		cout << "\nError at Line: " << this->currentLineInCode << ", Memory Location out of range.";
		exit(0);
	}
	
	return valueAtLocation;
}
//get the current line of code we are on
int CPU::getCurrentLine()
{
	return this->currentLineInCode;
}
//return the stop variable
bool CPU::debugStop()
{
	return this->stop;
}
//Set the line we are at in code
void CPU::setCurrentLine(int i)
{
	this->currentLineInCode = i;
}


