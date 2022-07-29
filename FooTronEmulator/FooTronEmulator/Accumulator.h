#pragma once
class Accumulator
{
private:
	int value = 0;

public:
	Accumulator();
	//add value to accumulator
	void add(int number);
	//divide accumulator value
	void divide(int number);
	//store value to accumulator
	void store(int newValue);
	//see the current value
	int peekValue();
	//Subtract value from accumulator
	void subtract(int s);
	//multiply accumulator value 
	void multiply(int m);
};

