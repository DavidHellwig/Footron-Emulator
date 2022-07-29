#pragma once

#include <string>
#include <vector>
using namespace std;
class FileReader
{
public:
	FileReader();
	//read in a file
    vector<int> readFile(string s);
	//remove invalid text, ie comments
	int sanitizeString(string s);

};

