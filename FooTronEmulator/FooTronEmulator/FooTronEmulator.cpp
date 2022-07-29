
#include <iostream>
#include "FileReader.h"
#include<string>
#include "Memory.h"
#include "Accumulator.h"
#include "CPU.h"
#include "Tron.h"

#include "ProgramCounter.h"

using namespace std;
int main()
{   
    
   
    cout << "Please enter a file you want to load(make sure it's in the project directory, reading out side the scope of the emulator is meant to protect the user)\n";

    Tron tron;
    tron.userHelp();
    //This loop run the emulator. 
    //commands case sensitive
    while (true) {
        
        tron.printInfo();
        
        string s;
        cin >> s;
        cin.clear();
        //if NEXT, execute step
        if (s == "NEXT") {
            tron.executeStep();
        }
        //if start, run whole program at once
        else if (s == "START") {
            while (true) {
                tron.printInfo();
                tron.executeStep();
            }
        }
        //if reset, reset the program
        else if (s == "RESET") {
            tron.reset();
        }
        //if exit, close the program
        else if (s == "EXIT") {

            exit(0);
        }
        //if read, abort current program and run another
        else if (s == "READ") {

            tron.reset();
        }
        //if user enters bad command, try again. 
        else {
            cout << "\nI'm sorry, I didn't understand that, please try again\n\n";
        }
        }
    
    
    
    return 0;
}


