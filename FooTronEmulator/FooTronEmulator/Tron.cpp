#include "Tron.h"

using namespace std;
//load values into memory
void Tron::loadMemoryValues()
{   
    string s;
    cin >> s;
    this->memory.setInitalValues(fr.readFile(s));
    int j = 0;
}


//Execute one cycle on instructions
void Tron::executeStep()
{
    if (cpu.getCurrentLine() == memory.getSize()) {
        cout << "\nProgram has stopped. ";
        exit(0);
    }
    else if (this->cpu.debugStop() == true) {
        cout << "\nProgram has stopped. ";
        exit(0);
    }
    this->pc.addElement(memory.accessMemoryLocation(cpu.getCurrentLine()));

    this->cpu.executeInstruction(this->memory, cpu.getInstruction(this->memory), this->accum);

    
     
}


//Print relavent info to the screen. This is intented to be used with NEXT. As such if we detect an infinte loop is about to happen, we crash. 
void Tron::printInfo()
{
    cout << "Accumualator: " << accum.peekValue();
    pc.printCounterCollection();
    cout << "-------------------------------------------" << endl;
    cout << "Memory Values\n";
    int currentLocationInCode = cpu.getCurrentLine();
    
    int nextLineToBeExecuted;
    nextLineToBeExecuted = currentLocationInCode;
    //check to see if we will be branching and show this on screen, what an ugly logical expression this is
    //if branching normally or using the other branch operations, our next location will be the changed appropriately 
    if ((this->cpu.getInstruction(this->memory)) == 40 || (this->cpu.getInstruction(this->memory)) == 41 && this->accum.peekValue() <  0 || ((this->cpu.getInstruction(this->memory)) == 42 && this->accum.peekValue() == 0))  {
        nextLineToBeExecuted = this->cpu.getLocationToChange(this->memory);
    }
    else{
        nextLineToBeExecuted +=1;
    }
    for (int i = 0; i < memory.getSize(); i++) {
        //cout << this->memory.accessMemoryLocation(i);
        if (currentLocationInCode == nextLineToBeExecuted) {
            cout << memory.accessMemoryLocation(i);
            cout << "<--Error:Infinite Loop detected , Line: " << this->cpu.getCurrentLine() << endl;
            exit(0);
        }
        else if (i == nextLineToBeExecuted) {
            cout << memory.accessMemoryLocation(i);
            cout << "<--Next Instruction!" << endl; //underlining wasn't working, this is more obvious

        }
        else if (i == currentLocationInCode) {
            cout << memory.accessMemoryLocation(i);
            cout << "<--You are here!" << endl;

        }
        
        else {
           cout << memory.accessMemoryLocation(i)<<endl;
        }
        
        
    }
    
    cout << "\n\n";
   
}
//print user help info
void Tron::userHelp()
{   
    cout << "Be warned, if your program doesn't has unitialized variables, it will not work. Add a 0000 at the memory \nlocation where you want your variable\n";
    cout << "\n TYPE READ TO READ IN A TEXT FILE(KNOW THE FILEPATH)\n TYPE NEXT TO RUN THE NEXT INSTRUCTION\n TYPE RESET TO RESET THE PROGRAM\n TYPE START TO RUN THE PROGRAM ON THE CURRENT LINE\n\n";
}
//reset the state of the machine 
void Tron::reset()
{
    this->cpu.setCurrentLine(0);
    loadMemoryValues();
}



