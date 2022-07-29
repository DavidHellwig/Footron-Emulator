#include "Accumulator.h"
Accumulator::Accumulator() {

}
//add to accumulator
void Accumulator::add(int number) {
	this->value += number;
};
//divide accumulator value
void Accumulator::divide(int number) {
	this->value = value/ number;
};
//store to accumulator
void Accumulator::store(int newValue) {
	this->value = newValue;
};
//return the current accumulator value
int Accumulator::peekValue() {
	return this->value;
}
//subtract from accumulator
void Accumulator::subtract(int s)
{
	this->value = value - s;
}
//multiply accumulator value
void Accumulator::multiply(int m)
{
	this->value = value * m;
}
;