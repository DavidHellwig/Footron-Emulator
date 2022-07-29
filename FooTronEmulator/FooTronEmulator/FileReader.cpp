
#include "FileReader.h"
#include<fstream>
#include <regex>
#include <iostream>

using namespace std;
FileReader::FileReader() {

}
//Sanitize a given string, removing anything that isn't a digit
int FileReader::sanitizeString(string s) {
	regex dirt("[^0-9 |-]+");
	s = regex_replace(s, dirt, "");

	int j = stoi(s);
	
	return j;

}
//open a file and return the instructions, removing comments 
vector<int> FileReader::readFile(string s) {
	FileReader fr;
	fstream file;
	
	
	vector<int> vivec;
	
	file.open(s);
	if (file.fail()) {
		cout << "Invalid file name";
		exit(0);
	}
	
	if (file.is_open()) {
		int i = 0;
		string line2;
		string line;
		while (getline(file,line2)){

			line = line2;

			vivec.push_back(sanitizeString(line));
			i += 1;
		}
	}
	
	return vivec;
	
}