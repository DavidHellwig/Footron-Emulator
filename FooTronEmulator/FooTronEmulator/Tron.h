#pragma once

#include "CPU.h"
#include "Memory.h"
#include "Accumulator.h"
#include<iostream>
#include "FileReader.h"
#include "ProgramCounter.h"
#include <windows.h> 
using namespace std;
class Tron
{
private:
	Accumulator accum;

	FileReader fr;

	CPU cpu;
	
	Memory memory;

	ProgramCounter pc;
	//load values into memory
	void loadMemoryValues();


public:
	Tron() {
		loadMemoryValues();
	};
	
	//run a line of code
	void executeStep();
	//print current state of the machine
	void printInfo();
	//display help message
	void userHelp();
	//reset to starting state. 
	void reset();
};

