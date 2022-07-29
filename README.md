# Footron-Emulator
This program is designed to emulate hypothetical computer than runs a language called Footron. 


## Footron Features:
- 1 Register (accumulator)
- Reads memory locations and instructions from 32 bit numbers (0001 - 9999). 
- Zero based indexing for reading instructions. 
- Reads txt files to obtain instructions (limited to files within project folder)

### Instruction Set
- ttRead 10 : Read a word from the keyboard into a specific location in memory. 
- ttWrite 11 : Write a word from a specific memory location.
- ttLoad 20 : Load a word from a specific location in memory into the accumulator  
- ttStore 21 : Store a word from the accumulator into a specific location in memory.
- ttAdd 30 : Add a word from a specific location in memory to the word in the accumulator, leaving the results in the accumulator. 
- ttSubstract 31 : Subtract a word from a specific location in memory from the word in the accumulator, leaving the results in the accumulator.
- ttDivide 32 Divide a word from a specific location in memory into the word in the accumulator, leaving the results in the accumulator.
- ttMultiply 33 : Multiple a word from a specific location in memory by the word in the accumulator, leaving the results in the accumulator.
- ttBranch 40 : Branch (goto) a specific location in memory.
- ttBranchNegative 41 : Branch to a specific location in memory IFF (If and only if) the value in the accumulator is negative
- ttBranchZero 42 : Branch to a specific location in memory IFF the value in the ccumulator is Zero.
- ttHalt 43 : Halt - The program has completed its task.
