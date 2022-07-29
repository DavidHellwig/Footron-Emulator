#pragma once
#include <string>
#include "Memory.h"
#include "Accumulator.h"

using namespace std;
class CPU
{
private:
	
	//Inital values for stopping and current line in code
	bool debugOn = false;
	bool stop = false;
	int currentLineInCode;
	
	
public: 
	//Two contructors, one that takes int is for debugging
	//starting on current line
	CPU(int loc) {
		this->currentLineInCode = loc;
	};
	CPU() {
		this->currentLineInCode = 0;
	}
	//Execute instruction
	void executeInstruction(Memory &mem, int instruction,Accumulator &accum);
	//Get an instruction from memory
	int getInstruction(Memory mem);
	//Get the memory location from an instruction
	int getLocationToChange(Memory mem);
	//return the current line in code
	int getCurrentLine();
	//d
	bool debugStop();
	//set the current line to the given int. 
	void setCurrentLine(int i);
	

	
};

