// Lab1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "Header.h"
using namespace std;


int parseFunc(vector<string>& vect, char* fileName) {

	std::ifstream file(fileName);
	if (file.is_open()) {
		std::string line;
		while (file >> line) {

			vect.push_back(line);
		}
		file.close();
		return success;
	}

	// if the name of the file is invalid; or the file doesn't exist
	else
	{
		cout << "Failed to open the file." << endl;
		return fail;
	}

}



int returnMessage(string programName) {

	cout << "This program reads and parses strings from a text file." << endl
		<< "Usage: Enter the file's name after the program's name, like " << endl
		<< programName << " text_file.txt" << endl;
	return tooManyArgs;

}

int main(int argc, char* argv[])
{
	

	if (argc != numcommandarg)
	{
		return returnMessage(argv[programName]);
	}
	else
	{
		vector<string> vect;
		int hold = parseFunc(vect, argv[fileName]);

		if (hold != success) { return hold; }
		else {
			vector<int> vect2;
			vector<string> stringVec;
			
			for (size_t i = 0; i < vect.size(); ++i) {
				int k = 0;
				int ch = 0;
				
				for (size_t j = 0; j < vect[i].size(); ++j) {
					if (isdigit(vect[i].at(j) == false)) {
						cout << vect[i] << endl;
						ch++;
					}
					else {
						k++;
		
					}
				}
				if (k == vect[i].size()) {

					stringstream p(vect[i]);
					
					int save =0;
					p >> save;
					
					vect2.push_back(save);
					
				}
				else if (ch == vect[i].size()) {

					
					stringVec.push_back(vect[i]);


				}
			
				
			}

			for (size_t i = 0; i < vect2.size(); ++i) {
				cout << vect2[i] << endl;
				
			}
			//for (size_t i = 0; i < stringVec.size(); ++i) {
			//	cout << stringVec[i] << endl;

		//	}
			

			

		}
			
	

	}
	return success;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
